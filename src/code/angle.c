speed >>= 1;              // speed / 2 after bounce
newangle = bounceangle[ob->hitnorth][angle];

switch (newangle)
{

[...]

case 3:

case 4:
	ob->xspeed = 0;
	ob->yspeed = -(speed / 256);
	break;
case 5:
	ob->yspeed = -(speed / 286);
	ob->xspeed = ob->yspeed / 2;
	break;
case 6:
	ob->xspeed = ob->yspeed = -(speed / 362);
	break;

[...]
}
