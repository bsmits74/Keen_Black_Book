PUBLIC	RFL_NewTile

[...]
	es,[mapsegs+2]			  ;foreground plane
	mov	bx,[es:si]
	mov	es,[mapsegs]			;background plane
	mov	si,[es:si]

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

	xor	si,si				      ;first word of tile data

	mov	ax,SC_MAPMASK+0001b*256	;map mask for plane 0

	mov	di,[cs:screenstartcs]

@@planeloopm:
	WORDOUT
tileofs	=	0
lineoffset	=	0
REPT	16
	mov	bx,[si+tileofs]		;background tile
	and	bx,[ss:tileofs]		;mask
	or	bx,[ss:si+tileofs+32]	;masked data
	mov	[es:di+lineoffset],bx
tileofs		=	tileofs + 2
lineoffset	=	lineoffset + SCREENWIDTH
ENDM
