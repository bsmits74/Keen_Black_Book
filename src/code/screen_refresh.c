PROC	VW_SetScreen  crtc:WORD, pel:WORD
PUBLIC	VW_SetScreen

	mov	dx,03DAh         ;Status Register 1
;
; wait util the CRTC just starts scanning a diplayed line 
; to set the CRTC start
;
	cli

@@waitnodisplay:       ;wait until scan line is finished
	in	al,dx
	test	al,01b
	jz	@@waitnodisplay

@@waitdisplay:         ;wait until retrace is finished
	in	al,dx
	test	al,01b
	jnz	@@waitdisplay


;
; set CRTC start
;
	[...]

;
; wait for a vertical retrace to set pel panning
;
	mov	dx,03DAh
@@waitvbl:
	sti     		        ;service interrupts
	jmp	$+2
	cli
	in	al,dx
	test	al,00001000b	;look for vertical retrace
	jz	@@waitvbl

;
; set horizontal pel panning
;
	[...]
