void	PowerReact (objtype *ob)
{
    unsigned wall,absx,absy,angle,newangle;
    unsigned long speed;

    absx = abs(ob->xspeed);
    absy = ob->yspeed;

    wall = ob->hitnorth;
    if ( wall == 17)	// go through pole holes
    {
        [...]
	}
    else if (wall)
    {
        ob->obclass = bonusobj;
        if (ob->yspeed < 0)
            ob->yspeed = 0;

        absx = abs(ob->xspeed);
        absy = ob->yspeed;
        if (absx>absy)
        {
            if (absx>absy*2)	// 22 degrees
            {
                angle = 0;
                speed = absx*286;	// x*sqrt(5)/2
            }
            else				// 45 degrees
            {
                angle = 1;
                speed = absx*362;	// x*sqrt(2)
            }
        }
        [...]       // Handle 67 and 90 degrees
    }
}
        
