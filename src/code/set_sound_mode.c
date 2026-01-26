boolean SD_SetSoundMode(SDMode mode)
{
  word	rate;

  // Interrupt refresh to either 140Hz or 700Hz
  rate = TickBase * t0CountTable[SoundMode];
  SDL_SetIntsPerSec(rate);
}

