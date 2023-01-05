#define NUMCHUNKS 3016  // Maximum number of graphic assets
int grhandle;           // handle to EGAGRAPH

void CA_CacheMarks (char *title, boolean cachedownlevel)
{
	int 	i,next;
	long	pos,endpos,compressed;
	byte	far *source;

  //
  // go through and load in anything still needed
  //
  for (i=0;i<NUMCHUNKS;i++)
    // Asset needed, but not loaded in memory
    if ( (grneeded[i]&ca_levelbit) && !grsegs[i])
    {
      pos = grstarts[i];
      next = i +1;
      while (grstarts[next] == -1)		// skip past any sparse tiles
        next++;

      compressed = grstarts[next]-pos;
      endpos = pos+compressed;

      // load buffer with a new block from disk
      // try to get as many of the needed blocks in as possible
      {
        [...]
        lseek(grhandle,pos,SEEK_SET);
        CA_FarRead(grhandle,bufferseg,endpos-pos);
        source = bufferseg;
      }
      CAL_ExpandGrChunk (i,source);  // Decompress data
    }
  }
}
