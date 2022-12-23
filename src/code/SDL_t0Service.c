static void interrupt SDL_t0Service(void)
{
  static word count = 1,

  if (!(--count))
  {
    count = t0CountTable[SoundMode]; // Set count to match 70Hz update
    LocalTime++;
    TimeCount++;
  }

  outportb(0x20,0x20);	// Acknowledge the interrupt
}
