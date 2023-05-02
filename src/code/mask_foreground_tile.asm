	jmp	SHORT @@realstart   ; start the scan
@@done:
;============
; all tiles have been scanned
;============
	ret

@@realstart:
	mov	di,[updateptr]
	mov	bp,(TILESWIDE+1)*TILESHIGH+2
	add	bp,di         ; when di = bx, 
	push di           ; all tiles have been scanned    
	mov	cx,-1         ; definately scan the entire thing
;============
; scan for a 3 in the update list
;============
@@findtile:
	mov	ax,ss
	mov	es,ax         ; scan in the data segment
	mov	al,3          ; check for '3's
	pop	di            ; place to continue scaning from
	repne	scasb
	cmp	di,bp
	je	@@done
;============
; found a tile, see if it needs to be masked on
;============
	push	di
	sub	di,[updateptr]
	shl	di,1
	mov	si,[updatemapofs-2+di]	; offset from originmap
	add	si,[originmap]
	mov	es,[mapsegs+2]      ; foreground map plane segment
	mov	si,[es:si]          ; foreground tile number
	or	si,si
	jz	@@findtile          ; 0 = no foreground tile
	mov	bx,si
	add	bx,INTILE           ; INTILE tile info table
	mov	es,[tinf]
	test [BYTE PTR es:bx],80h	; high bit = masked tile
	jz	@@findtile

; mask the tile

