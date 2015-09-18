/*
 * Author: Hannah White
 * 
 * Title: proj12.driver.c
 *
 * Brief: Code that implements a testing module for the code that
 * computes the absolute value, modulo, factorial, power, and cosine
 * of double values (integers for the factorial)
 */



#include "/user/cse320/Projects/project12.support.h"

int main()
{
  union dp_item Test;
  Test.drep = -3.000000000000E+00;

  union dp_item Test1;
  Test1.drep = +1.875000000000E+00;

  union dp_item Test2;
  Test2.drep = 5.1;

  union dp_item Test3;
  Test3.drep = 3.1;

  double number = absolute(Test.drep);
  printf("Testing absolute of -3.0: %08x\n", number);

  double number1 = absolute(Test1.drep);
  printf("Testing absolute of 1.875: %08x\n", number1);

  double number2 = modulo(Test2.drep, Test3.drep);
  printf("Testing 5.1 mod 3.1: %f\n", number2);

  double Test51 = -20.0;
  double Test52 = 3.0;
  double number52 = modulo(Test51, Test52);
  printf("Testing -20 mod 3: %f\n", number52);

  unsigned int Test4 = 4;
  double number3 = factorial(Test4);
  printf("Testing 4! : %f\n", number3);

  unsigned int Test5 = 9;
  double number4 = factorial(Test5);
  printf("Testing 9! : %f\n", number4);

  double Test6 = 3.0;
  unsigned int power1 = 3;
  double number5 = power(Test6, power1);
  printf("Testing 3.0^(3): %f\n", number5);

  double Test7 = 4.25;
  unsigned int power2 = 5;
  double number6 = power(Test7, power2);
  printf("Testing 4.25^(5): %f\n", number6);

  double Test8 = 8.1;
  double number7 = cosine(Test8);
  printf("Testing cos(8.1): %f\n", number7);
}
