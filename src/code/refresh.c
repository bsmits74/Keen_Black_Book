void RF_Refresh (void)
{

    updateptr = updatestart[otherpage];

    RFL_AnimateTiles ();// update animated tiles	

    // copy newly scrolled and animated tiles 
    // from the master to buffer screen
    EGAWRITEMODE(1);
    EGAMAPMASK(15);     // write 4 bytes of VRAM at once
    RFL_UpdateTiles (); // copy from master to buffer page
    RFL_EraseBlocks (); // remove sprites

    // update sprites
    EGAWRITEMODE(0);
    RFL_UpdateSprites ();

    // display the changed screen (swap view and buffer) 
    VW_SetScreen(bufferofs+panadjust,panx & xpanmask);

}
