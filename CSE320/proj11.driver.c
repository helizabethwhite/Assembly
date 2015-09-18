/*
 * Author: Hannah White
 *
 * Title: proj11.driver.c
 *
 * Brief: Code that tests the assembly program which accepts 
 * a double value and classifies it appropriately, returning a string
 * to a pointer        
 */

#include <stdio.h>
#include "/user/cse320/lib/bitlib.h"
#include "/user/cse320/Projects/project11.support.h"


int main()
{
  char B[80];
  char A[80];
  char C[80];
  char D[80];
  char E[80];
  char F[80];
  char G[80];
  char H[80];

  union dp_item s;
  s.drep = +5.562684646268E-309;
  union dp_item t;
  t.drep = -3.000000000000E+00; 
  union dp_item u;
  u.drep = -9.881312916825E-324;
  union dp_item v;
  v.drep = -0.000000000000E+00;
  union dp_item w;
  w.drep = +1.875000000000E+00;
  double x = 0.000;
  double y = 43.2;
  double z = -10.0;
  
  
  
  printf("\nClassify: %08x\n", s.drep);
  classify(s.drep, &H[0]);
  printf("\n%s", H);
  
  printf("\nClassify: %08x\n", t.drep);
  classify(t.drep, &A[0]);
  printf("\n%s", A);
  
  printf("\nClassify: %08x\n", u.drep);
  classify( u.drep, &B[0] );
  printf("\n%s", B);

  printf("\nClassify: %08x\n", v.drep);
  classify(v.drep, &C[0]);
  printf("\n%s", C);

  printf("\nClassify: %08x\n", w.drep);
  classify(w.drep, &D[0]);
  printf("\n%s", D);

  printf("\nClassify: %08x\n", x);
  classify(x, &E[0]);
  printf("\n%s", E);

  printf("\nClassify: %08x\n", y);
  classify(y, &F[0]);
  printf("\n%s", F);

  printf("\nClassify: %08x\n", z);
  classify(z, &G[0]);
  printf("\n%s", G);


 






}
