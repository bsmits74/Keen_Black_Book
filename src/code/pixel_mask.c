unsigned	xpanmask = 6;		// prevent panning to odd pixels
void RF_Scroll (int x, int y)
{
   [...]
   VW_SetScreen(newscreen+oldpanadjust,oldpanx & xpanmask);
}
