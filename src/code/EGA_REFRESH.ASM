#define	G_P_SHIFT	4   // global >> ?? = pixels

void RFL_CalcOriginStuff (long x, long y)
{
  originxglobal = x;
  originyglobal = y;	
  [...]

  //panning 0-15 pixels
  panx = (originxglobal>>G_P_SHIFT) & 15; 
  //move CRTC + 1 when move >7 pixels
  pansx = panx & 8;  
  pany = pansy = (originyglobal>>G_P_SHIFT) & 15;
  //Start location in VRAM
  panadjust = panx/8 + ylookup[pany];     
}
