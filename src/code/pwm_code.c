static void SDL_PCService(void)
{
  byte	s;
  word	t;
  s = *pcSound++;

  if (s)             // We have a frequency!
  {
    t = pcSoundLookup[s];
    asm	mov	bx,[t]

    asm mov al,0xb6	 // Write to channel 2 (speaker) timer
    asm	out	43h,al
    asm	mov	al,bl
    asm	out	42h,al   // Low byte
    asm	mov	al,bh
    asm	out	42h,al   // High byte

    asm	in	al,0x61  // Turn the speaker & gate on
    asm	or	al,3
    asm	out	0x61,al
  }
  else               // Time for some silence
  {
    asm	in	al,0x61  // Turn the speaker & gate off
    asm	and	al,0xfc  // ~3
    asm	out	0x61,al
  }
}
