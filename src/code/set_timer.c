// Set the number of interrupts generated 
// by system timer 0 per second
static void SDL_SetIntsPerSec(word ints)
{
	SDL_SetTimer0(1192755 / ints);
}

// Sets system timer 0 to the specified speed
static void SDL_SetTimer0(word speed)
{
	outportb(0x43,0x36);       // Change PIT counter 0
	outportb(0x40,speed);      // Speed is counter decrements  
	outportb(0x40,speed >> 8); // to send interrupt
}
