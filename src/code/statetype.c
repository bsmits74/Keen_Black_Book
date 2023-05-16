typedef struct
{
  int 		leftshapenum,rightshapenum; // Sprite to render 
                                      // on screen
  enum		{step,slide,think,stepthink,slidethink} progress;
  boolean	skippable;    //####WHAT IS SKIPPABLE#######
  boolean	pushtofloor;  // Make sure sprites stays
                        // connected with ground
  int tictime;          // How long stay in that state
  int xmove;
  int ymove;
  void (*think) ();
  void (*contact) (); 
  void (*react) ();
  void *nextstate;
} statetype;
