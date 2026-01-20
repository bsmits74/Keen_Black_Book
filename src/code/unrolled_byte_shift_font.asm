; Macros to table shift a byte of font
MACRO	SHIFTNOXOR
  mov	al,[es:bx]   ; source of font data
  xor	ah,ah
  shl	ax,1
  mov	si,ax
  mov	ax,[bp+si]   ; table shift into two bytes
  or	[di],al      ; OR with first byte
  inc	di
  mov	[di],ah	     ; replace next byte
  inc	bx           ; next source byte
ENDM

