_AH = 0x0B   // Set color palette
_BH = 1      // 4-color palette mode
_BL = 1      // 0=palette 1, 1=palette 2
geninterrupt (0x10) // Generate Video BIOS interrupt

_AH = 0x0B   // Set color palette
_BH = 0      // brightness
_BL = 0x10   // 10h=high, 0h=low   
geninterrupt (0x10) // Generate Video BIOS interrupt
