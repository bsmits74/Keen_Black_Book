charloc		=	2     ;pointers to every character
BUFFWIDTH	=	50    ;buffer width is 50 characters

PROC	ShiftPropChar	NEAR

  mov	es,[grsegs+STARTFONT*2]	;segment of font to use
  mov	bx,[es:charloc+bx]      ;BX holds pointer to character data

; look up which shift table to use, based on bufferbit
  mov	di,[bufferbit]      ;pixel offset within byte [0-7]
  shl	di,1
  mov	bp,[shifttabletable+di]	;BP holds pointer to shift table

  mov	di,OFFSET databuffer
  add	di,[bufferbyte]	    ;DI holds pointer to buffer
  mov	cx,[es:pcharheight] ;CX contains character height
  mov	dx,BUFFWIDTH

; write one byte character
shift1wide:
	dec	dx
EVEN
@@loop1:
	SHIFTNOXOR
	add	di,dx        ; next line in buffer
	loop	@@loop1
	ret
ENDP

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

