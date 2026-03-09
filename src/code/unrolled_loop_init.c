void InitGame (void)
{
	int i;

	MM_Startup ();    // Memory Manager
  if (mminfo.mainmem < 335l*1024)
  { ... (Not enough memory)}

	US_TextScreen();  // Show intro screen

	VW_Startup ();    // Video Manager
	RF_Startup ();    // Refresh Manager
	IN_Startup ();    // Input Manager
	SD_Startup ();    // Sound Manager
	US_Startup ();    // User Manager
	CA_Startup ();    // Cache Manager
	US_Setup ();      

	// load in and lock down some basic chunks
  CA_CacheMarks (NULL, 0);
  CA_LoadAllSounds ();
  //wait for a keypress and then clears the screen
  US_FinishTextScreen(); 
}
