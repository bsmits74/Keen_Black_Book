_AX = 0xd              ; AH=0 (Change video mode), AL=0Dh (Mode)
geninterrupt (0x10).   ; Generate Video BIOS interrupt
