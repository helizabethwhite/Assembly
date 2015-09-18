#include <stdio.h>
#include "/user/cse320/Projects/project07.support.h"

/* Name: proj07.driver.c
 *
 * Author: Hannah White
 *
 * Brief: code that tests implementation of decode module
 */

void decode(unsigned, char[]);

char destination[80];
int main()
{
  decode (0x86884002, destination);
  printf("%s",destination);
  decode (0x82906001, destination);
  printf("%s",destination);
  decode (0xC200E810, destination);
  printf("%s",destination);
  decode (0xC2214007, destination);
  printf("%s",destination);
  decode (0x03304F15, destination);
  printf("%s",destination);
  decode (0x7FFFFFCE, destination);
  printf("%s",destination);
  decode(0x18141001, destination);
  printf("%s",destination);
  decode(0x67664001, destination);
  printf("%s",destination);
  decode(0x9091E0FF, destination);
  printf("%s",destination);
  decode(0x94014006, destination);
  printf("%s",destination);
  decode(0x9081CDD1, destination);
  printf("%s",destination);
  decode(0x86783002, destination);
  printf("%s",destination);
  decode(0x90894001, destination);
  printf("%s",destination);
  decode(0xC2013008, destination);
  printf("%s",destination);
  decode(0x03202D14, destination);
  printf("%s",destination);
}
