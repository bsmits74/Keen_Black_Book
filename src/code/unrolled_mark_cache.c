#define CA_MarkGrChunk(chunk)	grneeded[chunk]|=ca_levelbit

ca_levelbit = 1;

void InitGame (void)
{
  [...]   //
          // load in and lock down some basic chunks
          //

  CA_ClearMarks ();  // Clears out all the marks at the current level

  // Mark assets to be cached in memory
  CA_MarkGrChunk(STARTFONT);
  CA_MarkGrChunk(STARTFONTM);
  CA_MarkGrChunk(STARTTILE8);
  CA_MarkGrChunk(STARTTILE8M);
  for (i=KEEN_LUMP_START;i<=KEEN_LUMP_END;i++)
    CA_MarkGrChunk(i);

  CA_CacheMarks (NULL, 0); // Cache marked assets into memory

}

