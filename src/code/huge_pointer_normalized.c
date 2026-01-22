# include <stdio .h>
# include <dos.h>

int main (void){
  char huge *p = MK_FP (0xA000 , 0xFFFF );
  p--;
  p++;
  printf("%04X:%04X\n", FP_SEG(p), FP_OFF(p));
}
