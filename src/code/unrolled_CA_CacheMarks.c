void CA_CacheMarks (char *title, boolean cachedownlevel)
{	
	//
	// save title so cache down level can redraw it
	//
	titleptr[ca_levelnum] = title;

	numcache = 0;
	//
	// go through and make everything not needed purgable
	//
	for (i=0;i<NUMCHUNKS;i++)
		if (grneeded[i]&ca_levelbit)
		{
			if (grsegs[i])			// its allready in memory, make
				MM_SetPurge(&grsegs[i],0);	// sure it stays there!
			else
				numcache++;
		}
		else
		{
			if (grsegs[i])		// not needed, so make it purgeable
				MM_SetPurge(&grsegs[i],3);
		}

	if (!numcache)			// nothing to cache!
		return;
	...
	//
	// go through and load in anything still needed
	//
	for (i=0;i<NUMCHUNKS;i++)
		if ( (grneeded[i]&ca_levelbit) && !grsegs[i])
		{
            //load asset from disk
            ...

            CAL_ExpandGrChunk (i,source);   // decompress
		}
	}
}
