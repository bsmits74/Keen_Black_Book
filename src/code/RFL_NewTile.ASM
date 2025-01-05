PROC	RFL_NewTile	updateoffset:WORD
	[...]
	mov	ax,[tilecache+si]
	or	ax,ax
	jz	@@singlemain   ; if 0, tile not in cache
;=============
; Draw single tile from cache
;=============
	[...]
	ret
;=============
; Draw single tile from main memory
;=============
@@singlemain:
	mov	ax,[cs:screenstartcs]
	mov	[tilecache+si],ax		;next time it can be drawn from 
								 					;here with latch
