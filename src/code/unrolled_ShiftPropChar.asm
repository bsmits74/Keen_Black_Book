MACRO	SHIFTNOXOR   ; Macros to table shift a byte of font
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

PROC	ShiftPropChar	NEAR
  [...]
; look up which shift table to use, based on bufferbit
  mov	di,[bufferbit]      ;pixel offset within byte [0-7]
  shl	di,1
  mov	bp,[shifttabletable+di]	;pointer to shift table
  [...]

@@loop1:
	SHIFTNOXOR
	add	di,dx        ; next line in buffer
	loop	@@loop1
	ret
ENDP


