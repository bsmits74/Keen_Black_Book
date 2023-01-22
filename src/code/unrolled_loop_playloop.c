void PlayLoop (void)
{
  FixScoreBox ();    // draw bomb/flower
  do
  {
    CalcSingleGravity ();   // Calculate gravity
    IN_ReadControl(0,&c);   // get player input

    // go through state changes and propose movements
    obj = player;
    do
    {
      if (obj->active)
        StateMachine(obj);  // Enemies think
      obj = (objtype *)obj->next;
    } while (obj);

    [...]           // Check for and handle collisions 
                    // between objects

    ScrollScreen(); // Scroll if Keen is nearing an edge.
                    // Draw new tiles to master screen in
                    // VRAM, and mark them in tile arrays

    [...]           // React to whatever happened, and post 
                    // sprites to the refresh manager

    RF_Refresh();   // Copy marked tiles from master to
                    // buffer screen, and update sprites
                    // in buffer screen. 
                    // Finally, switch buffer and view
                    // screen

    CheckKeys();    // Check special keys
  } while (!loadedgame && !playstate);
}
