#!/usr/bin/python

import argparse
import sys
import yaml

class TileBuilder(object):

    def __init__(self):
        self.tiles = {}

    def ParseOne(self, data):
        offset = int(data['offset'])
        width = int(data['width'])
        height = int(data['height'])
        mapping = data.get('mapping', {})

        #print('// parsing 0x%x %dx%d' % (offset, width, height))

        size = (width, height)
        if size == (2, 1):
            raise ValueError('Unsupported tile arrangement')

        for i in range(width*height):
            if offset+i in self.tiles:
                raise ValueError('Tile already defined', offset+i)

        plane0 = [0]*32
        plane1 = [0]*32
        if (height == 1 and len(data['data']) !=8 or
            height == 2 and len(data['data']) != 16):
            raise ValueError('Bad number of rows', offset)

        for i, row in enumerate(data['data']):
            if width == 1 and len(row) != 8 or width == 2 and len(row) != 16:
                raise ValueError('Bad data row length', offset, row)
            mask = 0
            y = i // 8
            for j, ch in enumerate(row):
                if mask == 0:
                    mask = 0x80
                
                x = j // 8
                ch = mapping.get(ch, ch)
                ch = ord(ch) & 3
                n = x*2+y
                
                if ch & 1:
                    plane0[n*8 + i%8] |= mask
                if ch & 2:
                    plane1[n*8 + i%8] |= mask
                mask >>= 1

        if size == (1,1):
            self.tiles[offset] = plane0[0:8] + plane1[0:8]
        elif size == (1,2):
            self.tiles[offset+0] = plane0[0:8] + plane1[0:8]
            self.tiles[offset+1] = plane0[8:16] + plane1[8:16]
        elif size == (2,2):
            self.tiles[offset+0] = plane0[0:8] + plane1[0:8]
            self.tiles[offset+1] = plane0[8:16] + plane1[8:16]
            self.tiles[offset+2] = plane0[16:24] + plane1[16:24]
            self.tiles[offset+3] = plane0[24:32] + plane1[24:32]

    def PrintOne(self, offset):
        data = self.tiles.get(offset, [0]*16)
        print('    %s, // $%02x' %
                (','.join(('0x%02x' % i) for i in data), offset))

    def Print(self, r=None):
        if not r:
            r = range(256)
        for i in r:
            self.PrintOne(i)

    def Parse(self, data):
        for tile in data['tiles']:
            self.ParseOne(tile)

    def ParseFile(self, filename):
        data = yaml.load(open(filename))
        self.Parse(data)



if __name__ == '__main__':
    flags = argparse.ArgumentParser(description="Tile Builder")
    flags.add_argument('files', metavar='FILES', type=str, nargs='*',
                       help='yaml files to process')
    flags.add_argument('--range', default=None, type=str,
                       help='a range of CHRs to print')

    args = flags.parse_args(sys.argv[1:])

    t = TileBuilder()
    for a in args.files:
        t.ParseFile(a)

    if args.range:
        if '-' in args.range:
            (a, b) = args.range.split('-')
            a = int(a,0); b = int(b,0)+1
        else:
            a = int(args.range); b = a+1
        r = range(a, b)
    else:
        r = None

    t.Print(r)
