#define	G_P_SHIFT		4	// global >> ?? = pixels

//Set x,y to top-left corner of sprite
y+=spr->orgy>>G_P_SHIFT; 
x+=spr->orgx>>G_P_SHIFT; 

shift = (x&7)/2;  // Set sprite shift
