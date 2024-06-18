GC_INDEX    =   0x3CE    ;Graphics Controller register
GC_MODE     =   5        ;mode register
SC_INDEX    =   0x3C4    ;Sequence register
SC_MAPMASK  =   2        ;map mask register

;==============
; Set EGA mode to read/write from latch
;==============

cli                      ;interrupts disabled
mov	dx,GC_INDEX          ;mode 1, each memory plane is 
mov	ax,GC_MODE+256*1     ;written with the content of 
out	dx,ax                ;the latches only

mov dx,SC_INDEX          ;enable writing to all 4 planes
mov ax,SC_MAPMASK+15*256 ;at once 
out dx,ax
sti                      ;interrupts enabled
