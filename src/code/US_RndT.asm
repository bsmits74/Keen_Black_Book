;=================================================
;
; int US_RndT (void)
; Return a random # between 0-255
; Exit : AX = value
;
;=================================================
PROC	US_RndT
	public	US_RndT

	mov	bx,[rndindex]
	inc	bx
	and	bx,0ffh
	mov	[rndindex],bx
	mov	al,[rndtable+BX]
	xor	ah,ah
	ret

ENDP
