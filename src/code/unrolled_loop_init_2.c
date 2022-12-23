void InitGame (void)
{
    ...

	US_TextScreen();

	VW_Startup ();
	RF_Startup ();
	IN_Startup ();
	SD_Startup ();
	US_Startup ();

	CA_Startup ();
	US_Setup ();

    //
    // load in and lock down some basic chunks
    //

	CA_ClearMarks ();

	...

	CA_LoadAllSounds ();

	fontcolor = WHITE;

	US_FinishTextScreen();

	VW_SetScreenMode (GRMODE);
	VW_ClearVideo (BLACK);
}
