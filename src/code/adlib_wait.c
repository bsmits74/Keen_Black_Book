/////////////////////////////////////////////////
//
//	alOut(n,b) - Puts b in AdLib card register n
//
/////////////////////////////////////////////////
void
alOut(byte n,byte b)
{
	asm	pushf
	asm	cli

	asm	mov		dx,0x388
	asm	mov		al,[n]
	asm	out		dx,al
	SDL_Delay(TimerDelay10);    //wait 10ms

	asm	mov		dx,0x389
	asm	mov		al,[b]
	asm	out		dx,al

	asm	popf

	SDL_Delay(TimerDelay25);    //wait 25ms
}
