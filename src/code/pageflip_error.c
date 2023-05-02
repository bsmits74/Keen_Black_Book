CRTC_INDEX	=	03D4h
CRTC_STARTHIGH	=	12

  cli                     ;disable interrupts
  mov  cx,[crtc]          ;[crtc] is start address
  mov  dx,CRTC_INDEX      ;set CRTR register
  mov  al,CRTC_STARTHIGH  ;start address high register
  out  dx,al	   
  inc  dx                 ;port 03D5h 
  mov  al,ch	   
  out  dx,al              ;set address high 
  
  ;******** VERTICAL RETRACE STARTS HERE  !!!!!!!  ****
  ;******** AND SHOWS 2 PARTIAL FRAMEBUFFERS **********  

  dec  dx                 ;set CRTR register
  mov  al,0dh             ;start address low register
  out  dx,al	   
  mov  al,cl
  inc  dx                 ;port 03D5h
  out  dx,al              ;set address low
  sti                     ;enable interrupts

  ret
