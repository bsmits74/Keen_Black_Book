void PlayLoop (void)
{
  FixScoreBox ();    // draw bomb/flower scorebox
  do
  {
    IN_ReadControl(0,&c);   // get player input

    // go through state changes and propose movements
    obj = player;
    do
    {
      if (obj->active)
        StateMachine(obj);  // Enemies think
      obj = (objtype *)obj->next;
    } while (obj);

    ScrollScreen(); // Scroll if Keen is nearing an edge.
    RF_Refresh();   // Update buffer screen and switch  
                    // buffer and view screen
    CheckKeys();    // Check special keys
  } while (!loadedgame && !playstate);
}
