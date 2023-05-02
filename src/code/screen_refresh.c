;==============
;
; VW_SetScreen
;
;==============

	mov	dx,03DAh         ;Status Register 1
;
; wait util the CRTC just starts scaning a diplayed line 
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

endif

; #### set CRTC start address

;
; wait for a vertical retrace to set pel panning
;
	mov	dx,STATUS_REGISTER_1
@@waitvbl:
	sti     		        ;service interrupts
	jmp	$+2
	cli
	in	al,dx
	test	al,00001000b	;look for vertical retrace
	jz	@@waitvbl

endif

; #### set horizontal panning
