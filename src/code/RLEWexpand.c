void CA_RLEWexpand (unsigned huge *source, unsigned huge *dest,long length, unsigned rlewtag)
{
  unsigned value,count,i;
  unsigned huge *end;
  unsigned sourceseg,sourceoff,destseg,destoff,endseg,endoff;

  end = dest + (length)/2;   // length is COMPRESSED length
  sourceseg = FP_SEG(source);
  sourceoff = FP_OFF(source);
  destseg = FP_SEG(dest);
  destoff = FP_OFF(dest);
  endseg = FP_SEG(end);
  endoff = FP_OFF(end);

  asm	mov	bx,rlewtag         // RLEW tag: ABCDh
  asm	mov	si,sourceoff
  asm	mov	di,destoff
  asm	mov	es,destseg
  asm	mov	ds,sourceseg

  expand:
  asm	lodsw
  asm	cmp	ax,bx              // value is RLEW tag?
  asm	je	repeat      
  asm	stosw                  // normal value
  asm	jmp	next

  repeat:
  asm	lodsw
  asm	mov	cx,ax              // repeat count
  asm	lodsw                  // repeat value
  asm	rep stosw

  next:                      // Next word value
  [...]
}
