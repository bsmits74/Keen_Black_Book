void VW_CGAFullUpdate (void)
{
    displayofs = bufferofs+panadjust;

    asm	mov	ax,0xb800
    asm	mov	es,ax

    asm	mov	si,[displayofs]
    asm	xor	di,di

    asm	mov	bx,100          // pairs of scan lines to copy
    asm	mov	dx,[linewidth]
    asm	sub	dx,80

    asm	mov	ds,[screenseg]  // buffer segment in memory
    asm	test	si,1
    asm	jz	evenblock

    [...]

    evenblock:
    asm	mov	ax,40           // words accross screen
    copytwolines:
    asm	mov	cx,ax
    asm	rep	movsw           // copy row to VRAM bank 0
    asm	add	si,dx
    asm	add	di,0x2000-80    // go to the interlaced bank 1
    asm	mov	cx,ax
    asm	rep	movsw           // copy row to VRAM bank 1
    asm	add	si,dx
    asm	sub	di,0x2000   // go to the non interlaced bank 0

    asm	dec	bx
    asm	jnz	copytwolines

    [...]
}
