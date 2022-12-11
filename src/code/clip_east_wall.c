void ClipToEastWalls (objtype *ob)
{
    ...

	for (y=top;y<=bottom;y++)
	{
		map = (unsigned far *)mapsegs[1] +
			mapbwidthtable[y]/2 + ob->tileleft;

    //Check if we hit EAST wall
		if (ob->hiteast = tinf[EASTWALL+*map])
		{
      //Clip left side actor to left side
      //of next right tile
			move = ( (ob->tileleft+1)<<G_T_SHIFT ) - ob->left;
			MoveObjHoriz (ob,move);
			return;
		}
	}
}
