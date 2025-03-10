void ClipToEnds (objtype *ob)
{
	[...]
  //Get midpoint of sprite [0-15]
	midxpix = (ob->midx&0xf0) >> 4;
	for (y=oldtilebottom-1 ; y<=ob->tilebottom ; y++,map+=mapwidth)
	{
    //Do we hit a NORTH wall
		if (wall = tinf[NORTHWALL+*map])
		{
		  //offset from tile border clip
			clip = wallclip[wall&7][midxpix];
      //Clip bottom side actor to top side tile + offset-1
			move = ( (y<<G_T_SHIFT)+clip - 1) - ob->bottom;
			if (move<0 && move>=maxmove)
			{
				ob->hitnorth = wall;
				MoveObjVert (ob,move);
				return;
			}
		}
	}
