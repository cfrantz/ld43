#!/usr/bin/python
import argparse
import sys
import yaml

class LevelBuilder(object):
    def __init__(self):
        self.maps = {}
        self.banks = set()
        self.objset = []

    def ParseMap(self, data):
        bank = int(data['bank'])
        self.banks.add(bank)
        id = int(data['id'])
        mapid = (bank<<3) | id
        if mapid in self.maps:
            raise KeyError('Map already exists', mapid)

        if 'mapping' not in data:
            raise ValueError('Cannot have a map without a mapping')

        mapping = {}
        for k, v in data['mapping'].items():
            mapping[k] = int(v)

        m = {}
        self.maps[mapid] = m
        m['bgpal'] = [0x0f] * 16
        m['sprpal'] = [0x0f] * 16
        m['chrbanks'] = [0, 2, 4, 5, 6, 7]
        m['exits'] = [0] * 32
        m['items'] = [0] * 24
        m['spawns'] = [0] * 48
        m['data'] = []

        for i, val in enumerate(data.get('chrbanks', [])):
            m['chrbanks'][i] = int(val)
        for i, val in enumerate(data.get('bgpal', [])):
            m['bgpal'][i] = int(val)
        for i, val in enumerate(data.get('sprpal', [])):
            m['sprpal'][i] = int(val)

        for i, val in enumerate(data.get('exits', [])):
            w = int(val.get('w', 1)) - 1
            h = int(val.get('h', 1)) - 1
            m['exits'][i*4+0] = int(val['x']) | (w<<5)
            m['exits'][i*4+1] = int(val['y']) | (h<<5)
            m['exits'][i*4+2] = int(val['dmap'])
            m['exits'][i*4+3] = int(val.get('dpos', 0))
            dx = int(val.get('dx', 0)) // 2
            dy = int(val.get('dy', 0)) // 2
            m['exits'][i*4+3] |= (dy<<4) | dx

        for i, val in enumerate(data.get('spawns', [])):
            m['spawns'][i*3+0] = int(val['x'])
            m['spawns'][i*3+1] = int(val['y'])
            m['spawns'][i*3+2] = int(val['id'])

        for i, val in enumerate(data.get('items', [])):
            m['items'][i*3+0] = int(val['x'])
            m['items'][i*3+1] = int(val['y'])
            m['items'][i*3+2] = int(val['id'])

        if len(data['data']) != 27:
            raise ValueError('Map data expected to be exactly 27 rows',
                             bank, id, len(data['data']))

        m[0] = []
        m[1] = []
        m[2] = []
        m[3] = []
        for y, row in enumerate(data['data']):
            if len(row) != 32:
                raise ValueError('Map rows expected to be exactly 32 chars',
                                 bank, id)
            screen = 2 * (y//15)
            objs = []
            for ch in row:
                if ch not in mapping:
                    raise ValueError('Char not in mapping', ch, bank, id)
                objs.append(mapping[ch])

            m[screen+0].append(objs[0:16])
            m[screen+1].append(objs[16:32])

    def PrintMap(self, n):
        if n not in self.maps:
            print('{}, // map %02x' % n)
            return

        m = self.maps[n]
        print('{  // map %02x' % n)
        print('{  // data')
        for i in range(4):
            for row in m[i]:
                print(','.join(('0x%02x' % v for v in row)) + ',')
        print('},')

        print('{  // chrbanks')
        print(','.join(('0x%02x' % v for v in m['chrbanks'])))
        print('},')
        print('{  // palette')
        print(','.join(('0x%02x' % v for v in m['bgpal'])) + ',')
        print(','.join(('0x%02x' % v for v in m['sprpal'])))
        print('},')
        print('{  // exits')
        print(','.join(('0x%02x' % v for v in m['exits'])))
        print('},')
        print('{  // items')
        print(','.join(('0x%02x' % v for v in m['items'])))
        print('},')
        print('{  // spawns')
        print(','.join(('0x%02x' % v for v in m['spawns'])))
        print('},')
        print('},')


    def PrintMaps(self, bank):
        print('#include "level.h"')
        print('#pragma rodata-name(push, "LVLDAT%d")' % bank)
        print('const uint8_t objset%d[256] = {' % bank)
        for obj in self.objset:
            print(','.join(('0x%02x' % int(x) for x in obj)) + ',')
        print('};')

        print('const struct LevelData levels%d[7] = {' % bank)
        for i in range(7):
            self.PrintMap(bank<<3 | i)
        print('};')
        print('#pragma rodata-name(pop)')

    def Print(self):
        for b in sorted(self.banks):
            self.PrintMaps(b)

    def Parse(self, data):
        self.objset = data['objset']
        for m in data['maps']:
            self.ParseMap(m)

    def ParseFile(self, filename):
        data = yaml.load(open(filename))
        self.Parse(data)


if __name__ == '__main__':
    flags = argparse.ArgumentParser(description="Map Builder")
    flags.add_argument('files', metavar='FILES', type=str, nargs='*',
                       help='yaml files to process')
    flags.add_argument('--bank', default=None, type=int,
                       help='print maps in a specific bank')

    args = flags.parse_args(sys.argv[1:])
    t = LevelBuilder()
    for a in args.files:
        t.ParseFile(a)

    if args.bank is None:
        t.Print()
    else:
        t.PrintMaps(args.bank)
