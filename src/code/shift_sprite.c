void CAL_CacheSprite (int chunk, char far *compressed)
{
    // make the shifts!
    switch (spr->shifts)
    {
    [...]
    case	4:
		dest->sourceoffset[0] = shiftstarts[0];
		dest->planesize[0] = smallplane;
		dest->width[0] = spr->width;

		dest->sourceoffset[1] = shiftstarts[1];
		dest->planesize[1] = bigplane;
		dest->width[1] = spr->width+1;
		CAL_ShiftSprite ((unsigned)grsegs[chunk],dest->sourceoffset[0],
			dest->sourceoffset[1],spr->width,spr->height,2);

		[...]   // Shift 4 and 6
		break;
	}
}
