#define	G_T_SHIFT	8   // global >> ?? = tile
#define	G_P_SHIFT	4   // global >> ?? = pixels
#define	SY_T_SHIFT 4  // screen y >> ?? = tile

void RFL_CalcOriginStuff (long x, long y)
{
  originxglobal = x;
  originyglobal = y;
  originxtile = originxglobal>>G_T_SHIFT;	
  originytile = originyglobal>>G_T_SHIFT;	
  originxscreen = originxtile<<SX_T_SHIFT;
  originyscreen = originytile<<SY_T_SHIFT;
  originmap = mapbwidthtable[originytile] + originxtile*2;

  //panning 0-15 pixels
  panx = (originxglobal>>G_P_SHIFT) & 15; 
  //pan pixels 0-7 (0) or 8-15 (1)
  pansx = panx & 8;  
  pany = pansy = (originyglobal>>G_P_SHIFT) & 15;
  //Start location in VRAM
  panadjust = panx/8 + ylookup[pany];     
}
