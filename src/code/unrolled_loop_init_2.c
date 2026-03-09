void InitGame (void)
{
    MM_Startup ();
    if (mminfo.mainmem < 335l*1024)
    { // Not enough memory}

	US_TextScreen();

	VW_Startup ();
	RF_Startup ();
	IN_Startup ();
	SD_Startup ();
	US_Startup ();

	CA_Startup ();
	US_Setup ();

    // load in and lock down some basic chunks

	CA_LoadAllSounds ();

	US_FinishTextScreen();

	VW_SetScreenMode (GRMODE);
	VW_ClearVideo (BLACK);
}
