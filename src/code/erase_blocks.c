typedef struct
{
    int			screenx,screeny;
    int			width,height;
} eraseblocktype;

eraseblocktype	eraselist[2][MAXSPRITES],*eraselistptr[2];

void RFL_EraseBlocks (void)
{
	eraseblocktype	*block,*done;
	unsigned	pos;

	block = &eraselist[0][0];
	done = eraselistptr[0];

	while (block != done)
	{
    [...]

	//
	// erase the block by copying from the master screen
	//
		pos = ylookup[block->screeny]+block->screenx;
		block->width = (block->width + (pos&1) + 1)& ~1;
		pos &= ~1;				// make sure a word copy gets used
		VW_ScreenToScreen (masterofs+pos,bufferofs+pos,
			block->width,block->height);
    
    [...]
    block++;
  }
}
