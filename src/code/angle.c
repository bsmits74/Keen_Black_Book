absx = abs(ob->xspeed);
absy = ob->yspeed;
if (absx>absy)
{
    if (absx>absy*2)        // 22 degrees
    {
        angle = 0;
        speed = absx*286;   // x*sqrt(5)/2 *256
    }
    else
    [...]
}

if (ob->xspeed > 0)       
    angle = 7-angle;        // mirror angle

speed >>= 1;                // speed / 2 after bounce
newangle = bounceangle[ob->hitnorth][angle];
switch (newangle)
{
case 0:
	ob->xspeed = speed / 286;
	ob->yspeed = -ob->xspeed / 2;
	break;
case 1:
	ob->xspeed = speed / 362;
	ob->yspeed = -ob->xspeed;
	break;

[...]

case 5:
	ob->yspeed = -(speed / 286);
	ob->xspeed = ob->yspeed / 2;
	break;

[...]
}
