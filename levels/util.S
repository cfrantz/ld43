    .export     _get_screen
	.importzp	sp, sreg, regsave, regbank
	.importzp	tmp1, tmp2, tmp3, tmp4, ptr1, ptr2, ptr3, ptr4
	.import		_screen
    .import     popa

; ---------------------------------------------------------------
; unsigned char __near__ __fastcall__ get_screen (unsigned char, unsigned char)
; ---------------------------------------------------------------

.segment	"CODE"

.proc	_get_screen: near

.segment	"CODE"

;
; uint8_t __fastcall__ get_screen(uint8_t x, uint8_t y) {
;
    ldy     #>(_screen)
    sty     ptr1+1
    ldy     #<(_screen)
    sty     ptr1+0

    cmp     #15
    bcc     @1
    sbc     #15
    inc     ptr1+1
    inc     ptr1+1
@1:
    asl
    asl
    asl
    asl
    sta     tmp1
    jsr     popa

    cmp     #16
    bcc     @2
    sbc     #16
    inc     ptr1+1
@2:
    clc
    adc     tmp1
    tay

    lda     (ptr1),y
    rts
.endproc
