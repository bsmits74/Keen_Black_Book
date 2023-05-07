void CA_DownLevel (void)
{
	if (!ca_levelnum)
		Quit ("CA_DownLevel: Down past level 0!");
	ca_levelbit>>=1;
	ca_levelnum--;
    
  //recaches everyting from the previous level
	CA_CacheMarks(titleptr[ca_levelnum], 1);
}
