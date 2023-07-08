_AX = 0x1000 ; Set One Palette Register
_BL = 0      ; index color number to set
_BH = 0x5    ; 6-bit RGB color to display for that index
geninterrupt (0x10) ; Generate Video BIOS interrupt
