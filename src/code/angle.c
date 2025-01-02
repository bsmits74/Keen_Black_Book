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
