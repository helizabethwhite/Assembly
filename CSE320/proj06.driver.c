#include <stdio.h>
#include "/user/cse320/Projects/project06.support.h"

/* Name: proj06.driver.c
 *
 * Author: Hannah White
 *
 * Brief: code that tests implementation of add module, a module that 
 * uses softare to add floating point values
 */

float add(float, float);

int main()
{
  float num = 24.5;
  float num1 = 1.5;
  float num2 = 3.65;
  float num3 = 4.57;
  float num4 = 0.0;
  union sp_item num5;
  num5.irep = 0x7f800000;


  union sp_item result1, result2, result3, result4, result5, result6;

  result1.frep = add(num,num1);
  result2.frep = add(num2,num3);
  result3.frep = add(num, -num1);
  result4.frep = add(-num, -num1);
  result5.frep = add(num2, num4);
  result6.frep = add(num, num5.frep);

  printf("Add: %f + %f\n", num, num1); 
  printf("Result: %f Hex: %08x\n", result1.frep, result1.irep);
  printf("\n");
  printf("Add: %f + %f\n", num2, num3);
  printf("Result: %f Hex: %08x\n", result2.frep, result2.irep);
  printf("\n");
  printf("Add: %f + %f\n", num, -num1);
  printf("Result: %f Hex: %08x\n", result3.frep, result3.irep);
  printf("\n");
  printf("Add: %f + %f\n", -num, -num1);
  printf("Result: %f Hex: %08x\n", result4.frep, result4.irep);
  printf("\n");
  printf("Add %f + %f\n", num2, num4);
  printf("Result: %f Hex: %08x\n", result5.frep, result5.irep);
  printf("\n");
  printf("Add: %f + %f\n", num, num5.frep);
  printf("Result %f Hex: %08x\n", result6.frep, result6.irep);

}
