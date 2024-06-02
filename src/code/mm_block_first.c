length -= 16-(FP_OFF(start)&15); // round to 16 bytes    
seglength = length / 16;         // now in segments
segstart = FP_SEG(start)+(FP_OFF(start)+15)/16; 
