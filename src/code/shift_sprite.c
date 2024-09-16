void CAL_CacheSprite (int chunk, char far *compressed)
{
[...]
//
// make the shifts!
//
	switch (spr->shifts)
	{
	case	1:	// no shifts
		[...]	

	case	2:	// one shift of 4 pixels
		for (i=0;i<2;i++)
		{
			dest->sourceoffset[i] = shiftstarts[0];
			dest->planesize[i] = smallplane;
			dest->width[i] = spr->width;
		}
		for (i=2;i<4;i++)
		{
			dest->sourceoffset[i] = shiftstarts[1];
			dest->planesize[i] = bigplane;
			dest->width[i] = spr->width+1;
		}
		CAL_ShiftSprite ((unsigned)grsegs[chunk],dest->sourceoffset[0],
			dest->sourceoffset[2],spr->width,spr->height,4);
		break;

	case	4:	// four shifts of 2 pixels
		[...]
	default:
		Quit ("CAL_CacheSprite: Bad shifts number!");
	}
}
