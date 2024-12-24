static void interrupt INL_KeyService ( void ) {
	byte k;
	k = inportb (0 x60 ); // Get the scan code

	// Tell the XT keyboard controller to clear the key
	outportb(0x61,(temp = inportb(0x61)) | 0x80);
	outportb(0x61,temp);

	if (k == 0xe0)		// Special key prefix
		special = true;
	else if (k == 0xe1)	// Handle Pause key
		Paused = true;
	else
	{
		if (k & 0x80)	// Break code
		{
			k &= 0x7f;
			Keyboard[k] = false;
		}
		else		    	// Make code
		{ 
			LastCode = CurCode;
			CurCode = LastScan = k;
			Keyboard[k] = true;
			[...]       //Process the key
		}
	}
	outportb (0 x20 ,0 x20 ); // ACK interrupt to interrupt system
}
