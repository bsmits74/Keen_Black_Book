void DemoLoop() {
    US_SetLoadSaveHooks();
    while (1) {
        VW_InitDoubleBuffer ();
        IN_ClearKeysDown ();
        VW_FixRefreshBuffer ();
        US_ControlPanel ();  // Menu
        GameLoop ();  
          //Functions in GameLoop()
          SetupGameLevel ();
          PlayLoop () ; // 2D engine (action)
          GameOver ();
    }
    Quit("Demo loop exited???");
}
