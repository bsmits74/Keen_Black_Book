ATR_INDEX	=	03C0h
ATR_PELPAN	=	19

;==============
; set horizontal panning
;==============

  mov	dx,ATR_INDEX
  mov	al,ATR_PELPAN or 20h ;bit 5 is high to keep palette
                           ;RAM addressing on
  out	dx,al
  mov	al,[BYTE pel]        ;pel pan value [0 to 8]
  out	dx,al
