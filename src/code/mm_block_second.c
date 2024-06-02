segstart = FP_SEG(start)+(FP_OFF(start)+15)/16;
// locked block of unusable near heap memory (usually just the stack)
// from end of near heap to start of far heap
GETNEWBLOCK;
mmnew->start = endfree;
mmnew->length = segstart-endfree;
mmnew->attributes = LOCKBIT;
endfree = segstart+seglength;
