MM_SetLock (&grsegs[STARTFONT],true);
MM_SetLock (&grsegs[STARTFONTM],true);
MM_SetLock (&grsegs[STARTTILE8],true);
MM_SetLock (&grsegs[STARTTILE8M],true);
for (i=KEEN_LUMP_START;i<=KEEN_LUMP_END;i++)
	MM_SetLock (&grsegs[i],true);
