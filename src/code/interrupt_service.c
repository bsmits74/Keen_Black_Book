static void interrupt SDL_t0Service(void)
{ [...] }

void SD_Startup(void)
{
  t0OldService = getvect(8);	// Get old timer 0 ISR

  SDL_InitDelay();	// SDL_InitDelay() uses t0OldService

  setvect(8,SDL_t0Service);	// Set to my timer 0 ISR

}
