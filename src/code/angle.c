absx = abs(ob->xspeed);
absy = ob->yspeed;
if (absx>absy)
{
	if (absx>absy*2)        // 22 degrees
	{
		angle = 0;
		speed = absx*286;     // x*sqrt(5)/2 *256
	}
	else
	[...]             // Check for 45, 67 and 90 degrees      
}

if (ob->xspeed > 0)       
	angle = 7-angle;        // mirror angle

speed >>= 1;              // speed / 2 after bounce
newangle = bounceangle[ob->hitnorth][angle];
switch (newangle)
{
[...]

case 5:
	ob->yspeed = -(speed / 286);
	ob->xspeed = ob->yspeed / 2;
	break;

[...]
}
