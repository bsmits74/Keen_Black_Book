//
// tile info defines, as bytes after tinf the table starts
//


#define	SPEED       502
#define ANIM        (SPEED+NUMTILE16)

#define NORTHWALL   (ANIM+NUMTILE16)
#define EASTWALL    (NORTHWALL+NUMTILE16M)
#define SOUTHWALL   (EASTWALL+NUMTILE16M)
#define WESTWALL    (SOUTHWALL+NUMTILE16M)
#define MANIM       (WESTWALL+NUMTILE16M)
#define INTILE      (MANIM+NUMTILE16M)
#define MSPEED      (INTILE+NUMTILE16M)

//========================================================

typedef	struct
{
	long		planestart[3];
	unsigned	planelength[3];
	unsigned	width,height;
	char		name[16];
} maptype;
