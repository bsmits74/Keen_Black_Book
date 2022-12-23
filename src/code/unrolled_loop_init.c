void InitGame (void)
{
	int i;

	MM_Startup ();    // Memory Manager

	US_TextScreen();  // Show intro screen

	VW_Startup ();    // Video Manager
	RF_Startup ();    // Refresh Manager
	IN_Startup ();    // Input Manager
	SD_Startup ();    // Sound Manager
	US_Startup ();    // Font Manager

	CA_Startup ();    // Cache Manager
	US_Setup ();      

	CA_ClearMarks ();  // Clears out all the marks

	CA_LoadAllSounds (); // Load all sounds

}
