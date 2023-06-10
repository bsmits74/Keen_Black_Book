// If one of the drives is on, 
// and we're not told to leave it on...
if ((peekb(0x40,0x3f) & 3) && !LeaveDriveOn)
{
	if (!(--drivecount))
	{
		drivecount = 5;

		sdcount = peekb(0x40,0x40);	// Get system drive count
		if (sdcount < 2)	    		  // Time to turn it off
		{
			// Wait until it's off
			while ((peekb(0x40,0x3f) & 3))
			{
				asm	pushf
				t0OldService(); // Call original timer interrupt
			}
		}
		else	// Not time yet, just decrement counter
			pokeb(0x40,0x40,--sdcount);
	}
}
