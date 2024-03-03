// ID_VW.H

typedef struct
{
  int	width,
	height,
	orgx,orgy,
	xl,yl,xh,yh,
	shifts;
} spritetabletype;

typedef struct
{
	int height;
	int location[256];
	char width[256];
} fontstruct;

