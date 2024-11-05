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

;
; set CRTC start
;
	mov	cx,[crtc]
	mov	dx,CRTC_INDEX
	mov	al,0ch		;start address high register
	out	dx,al
	inc	dx
	mov	al,ch
	out	dx,al
	dec	dx
	mov	al,0dh		;start address low register
	out	dx,al
	mov	al,cl
	inc	dx
	out	dx,al
