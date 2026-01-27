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

    [...]           // Handle collisions between objects
    ScrollScreen(); // Scroll if Keen is nearing an edge.
    [...]           // Update sprites.
    RF_Refresh();   // Update buffer screen and switch  
                    // buffer and view screen
    CheckKeys();    // Check special keys
  } while (!loadedgame && !playstate);
}
