word			pcSoundLookup[255];

//////////////////////////////////////////////////////
//
//	SD_Startup() - starts up the Sound Mgr
//	Detects all additional sound hardware and 
//  installs my ISR
//
//////////////////////////////////////////////////////
void
SD_Startup(void)
{
    [...]

    for (i = 0;i < 255;i++)
        pcSoundLookup[i] = i * 60;

}

