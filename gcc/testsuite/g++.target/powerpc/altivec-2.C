/* { dg-do compile } */
/* { dg-options "-maltivec -Wall -Wno-unused-but-set-variable -Wno-deprecated" } */
/* { dg-require-effective-target powerpc_altivec } */

/* This test checks if AltiVec builtins accept const-qualified
   arguments.  */

#include <altivec.h>

vector unsigned char use_lvsl;

int main (int argc, const char * argv[])
{
  int i = 0;
  const float cf = 1.0;
  vector float v;
  const vector float cv = (vector float){1.0, 2.0, 3.0, 4.0};

  vec_dst(&cv, i, 0);
  v = vec_ld(0, &cv);	
  v = vec_lde(0, &cf);
  use_lvsl = vec_lvsl(0, &cf);
  
  return 0;
}
