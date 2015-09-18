#include <stdio.h>
#include "/user/cse320/Projects/project07.support.h"

/* Name: proj07.support.c
 *
 * Author: Hannah White
 *
 * Brief: code that implements decode module, a module that
 * translates ARC machine instruction into human-readable form.
 *
 */


void decode( unsigned, char[]);
void arithmeticfxn (unsigned, char[]);
void memoryfxn (unsigned, char[]);
void sethifxn (unsigned, char[]);
void callfxn (unsigned, char[]);

int simm = 0;
unsigned int op;
unsigned int op2;
unsigned int op3;
unsigned int rs1;   // first register
unsigned int rs2;   // second register
unsigned int rd;    // register to write to
unsigned int i;

signed int imm22;
signed int simm13;
signed int disp30;

unsigned int sethiop = 0x00000000;
unsigned int sethi = 0x00000004;
unsigned int call = 0x00000001;
unsigned int arithmetic = 0x00000002;
unsigned int memory = 0x00000003;

unsigned int addcc = 0x00000010;
unsigned int andcc = 0x00000011;
unsigned int orcc = 0x00000012;
unsigned int orncc = 0x00000016;
unsigned int srlcc = 0x00000026;

unsigned int ld = 0x00000000;
unsigned int st = 0x00000004;


void decode (unsigned bits, char destination[])
{
  op = bits >> 30;
  if (op == sethiop)
  {
   sethifxn(bits, destination); 
  }
  else if (op == call)
  {
    callfxn(bits, destination);
  }
  else if (op == arithmetic)
  {
   arithmeticfxn(bits, destination); 
  }
  else if (op == memory)
  {
    memoryfxn(bits, destination);
  }
}

void arithmeticfxn (unsigned bits, char destination[])
{
  simm = 0;
  rd = (bits << 2) >> 27;
  op3 = (bits << 7) >> 26;
  rs1 = (bits << 13) >> 27;
  i = (bits << 18) >> 31;
  
  if (i == 0)
  {
    rs2 = (bits << 27) >> 27;
  }
  else if (i == 1)
  {
   simm13 = (bits << 19) >> 19;
   simm = 1; 
  }
  
  if (op3 == addcc)
  {
    if (simm == 0)
    {
      sprintf( destination, "Result: addcc \t%%r%d, %%r%d, %%r%d \n\0",rs1, rs2, rd);
    }
    else
    {
      sprintf( destination, "Result: addcc \t%%r%d, %d, %%r%d \n\0", rs1, simm13, rd);
    } 
  }
  else if (op3 == andcc)
  {
    if (simm == 0)
    {
      sprintf( destination, "Result: andcc \t%%r%d, %%r%d, %%r%d \n\0",rs1, rs2, rd);
    }
    else
    {

      sprintf( destination, "Result: andcc \t%%r%d, %d, %%r%d \n\0", rs1, simm13, rd);
    }
  }
  else if (op3 == orcc)
  {
    if (simm == 0)
    {
      sprintf( destination, "Result: orcc \t%%r%d, %%r%d, %%r%d \n\0",rs1, rs2, rd);
    }
    else
    {

      sprintf( destination, "Result: orcc \t%%r%d, %d, %%r%d \n\0", rs1, simm13, rd);
    }
  }
  else if (op3 == orncc)
  {
    if (simm == 0)
    {
      sprintf( destination, "Result: orncc \t%%r%d, %%r%d, %%r%d \n\0",rs1, rs2, rd);
    }
    else
    {

      sprintf( destination, "Result: orncc \t%%r%d, %d, %%r%d \n\0", rs1, simm13, rd);
    }
  }
  else if (op3 == srlcc)
  {
    if (simm == 0)
    {
      sprintf( destination, "Result: srlcc \t%%r%d, %%r%d, %%r%d \n\0",rs1, rs2, rd);
    }
    else
    {
      sprintf( destination, "Result: srlcc \t%%r%d, %d, %%r%d \n\0", rs1, simm13, rd);
    }
  }
  else
  {
    sprintf( destination, "Invalid bit set \n\0");    
  } 
}

void memoryfxn (unsigned bits, char destination[])
{
  simm = 0;
  rd = (bits << 2) >> 27;
  op3 = (bits << 7) >> 26;
  rs1 = (bits << 13) >> 27;
  i = (bits << 18) >> 31;
  
  if (i == 0)
  {
    rs2 = (bits << 27) >> 27;
  }
  else if (i == 1)
  {
   simm13 = (bits << 19) >> 19;
   simm = 1; 
  }

  if (op3 == ld)
  {
    if (simm == 0)
    {
      sprintf( destination, "Result: ld \t[%%r%d+%%r%d], %%r%d \n\0",rs1, rs2, rd);
    }
    else
    {
      sprintf( destination, "Result: ld \t[%%r%d+%d], %%r%d \n\0", rs1, simm13, rd);
    }
  }
  else if (op3 == st)
  {
    if (simm == 0)
    {
      sprintf( destination, "Result: st \t%%r%d, [%%r%d+%%r%d] \n\0",rd, rs1, rs2);
    }
    else
    {
      sprintf( destination, "Result: st \t[%%r%d+%d], %%r%d \n\0", rs1, simm13, rd);
    }
  }
  else
  {
    sprintf( destination, "Invalid bit set \n\0");    
  } 
}

void sethifxn(unsigned bits, char destination[])
{
  rd = (bits << 2) >> 27;
  op2 = (bits << 7) >> 29;
  imm22 = (bits << 10) >> 10;
  if (op2 == sethi)
  {
    sprintf( destination, "Result: sethi \t%#6x, %%r%d \n\0", imm22, rd);
  }
  else
  {
    sprintf( destination, "Invalid bit set \n\0");
  }
}

void callfxn(unsigned bits, char destination[])
{
  disp30 = (bits << 2);
  sprintf( destination, "Result: call \tPC+%#8x \n\0", disp30);
}
