char far *EGA = (unsigned char far*)0xA0000000L;

void ClearScreen(void){
    int i;
    _AX = 0xd;
    geninterrupt (0x10);

    for (i=0 ; i < 320*200 ; i++)
         EGA[i] = 0x00;
}

