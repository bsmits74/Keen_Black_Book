void PeaPodThink (objtype *ob)
{
	if ( abs(ob->y - player->y) > 3*TILEGLOBAL )
		return;

	if (player->x < ob->x && ob->xdir == 1)
		return;

	if (player->x > ob->x && ob->xdir == -1)
		return;

	// Randomness to spit pea brain
	if (US_RndT()<8 && ob->temp1 < MAXPEASPIT)
	{
		ob->temp1 ++;
		ob->state = &s_peapodspit1;
		ob->xmove = 0;
	}
}
