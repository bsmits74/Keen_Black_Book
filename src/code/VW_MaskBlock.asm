PROC	VW_MaskBlock	segm:WORD, ofs:WORD, dest:WORD, wide:WORD, height:WORD, planesize:WORD

[...]

@@unwoundroutine:
	mov	cx,[dest]
	shr	cx,1
	rcl	di,1					;shift a 1 in if destination is odd
	shl	di,1					;to index into a word width table
	mov	ax,[maskroutines+di]	;call the right routine
	mov	[routinetouse],ax		;and store the function pointer

@@startloop:
	mov	ds,[segm]

@@drawplane:
	[...]
	mov	si,[ofs]				;start back at the top of the mask
	mov	di,[dest]				;start at same place in all planes
	mov	cx,[height]				;scan lines to draw
	mov dx,[ss:linedelta]

	jmp [ss:routinetouse]		;draw one plane
