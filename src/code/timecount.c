longword TimeCount;

static void interrupt SDL_t0Service(void)
{
  static word count = 1,
  switch (SoundMode)
  {
  case sdm_PC:
	  SDL_PCService();
	  break;
  case sdm_AdLib:
	  SDL_ALSoundService();
	  break;
  }

  if (!(--count))
  {
    // Set count to match 70Hz update
    count = t0CountTable[SoundMode]; 
    TimeCount++;
  }
  outportb(0x20,0x20);	// Acknowledge the interrupt
}
