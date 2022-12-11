void ClipToEastWalls (objtype *ob)
{
	...

	for (y=top;y<=bottom;y++)
	{
		map = (unsigned far *)mapsegs[1] +
			mapbwidthtable[y]/2 + ob->tileleft;

		//Check if we are hitting an EAST wall
		if (ob->hiteast = tinf[EASTWALL+*map])
		{
            //Move the left side of the actor to the left side of the next right tile
			move = ( (ob->tileleft+1)<<G_T_SHIFT ) - ob->left;
			MoveObjHoriz (ob,move);
			return;
		}
	}
}
