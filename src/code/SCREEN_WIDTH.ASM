CRTC_INDEX	=	03D4h
CRTC_OFFSET	=	19

;==============
;
; set wide virtual screen
;
;==============

mov	dx,CRTC_INDEX
mov	al,CRTC_OFFSET
mov	ah,[BYTE PTR width]  ;screen width in bytes
shr	ah,1                 ;register expresses width 
                         ;in word instead of byte
out	dx,ax

