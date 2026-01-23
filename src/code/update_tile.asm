PUBLIC	RFL_NewTile

[...]
	es,[mapsegs+2]			  ;foreground plane
	mov	bx,[es:si]
	mov	es,[mapsegs]			;background plane
	mov	si,[es:si]
	mov	es,[screenseg]
	mov	dx,SC_INDEX				;stepping through map mask planes

[...]
  or	bx,bx             ;do we have foreground tile?
	jz	@@singletile			;draw background tile only
	jmp	@@maskeddraw			;draw both together

[...]
@@maskeddraw:
	shl	bx,1
	mov	ss,[grsegs+STARTTILE16M*2+bx]
	shl	si,1
	mov	ds,[grsegs+STARTTILE16*2+si]
	xor	si,si                       ;first word of tile data
	mov	ax,SC_MAPMASK+0001b*256	    ;map mask for plane 0
	mov	di,[cs:screenstartcs]

@@planeloopm:       ;start writing masked tile to VRAM 
	WORDOUT           ;set mask plane (OUT DX,AX)
	tileofs	=	0
	lineoffset	=	0
REPT	16
	mov	bx,[si+tileofs]         ;background tile
	and	bx,[ss:tileofs]         ;mask background
	or	bx,[ss:si+tileofs+32]   ;masked foreground data
	mov	[es:di+lineoffset],bx   ;move to next line in VRAM
	tileofs		=	tileofs + 2
	lineoffset	=	lineoffset + SCREENWIDTH
ENDM
	add	si,32
	shl	ah,             ;shift plane mask over for next plane
	cmp	ah,10000b
	je	@@done          ;drawn all four planes
	jmp	@@planeloopm
