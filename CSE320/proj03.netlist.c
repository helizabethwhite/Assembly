
/******************************************************************************
  Project #3 
******************************************************************************/

#include <Sim.h>

void circuits( SD, Signal, Signal, Signal, Signal, 
  Signal, Signal, Signal, Signal, Signal, Signal, Signal, Signal );


/******************************************************************************
  Function "simnet"   -- test bed for student circuits
******************************************************************************/

void simnet()
{
  Signal w, x, y, z, Present, a, b, c, d, e, f, g;

  Signal Strobe (1);       // Counter strobe input
  Signal ResetA (1);       // Counter reset signal (before complemented)
  Signal ResetB (1);       // Counter reset signal (after complemented)
  Signal Output (4);       // Counter output

  // Code to generate four input signals

  Pulser ((SD("1a"), "r -- Reset counter"), ResetA, 'r', 10000);
  Pulser ((SD("5a"), "s -- Strobe counter"), Strobe, 's', 10000);

  Not (SD("1b"), ResetA, ResetB);

  Counter ((SD("2a-4a"), "4-bit counter"), (ResetB, Strobe),(w,x,y,z));

  circuits( SD("2b-4c"), w, x, y, z, Present, a, b, c, d, e, f, g);

  // Code to display eight output signals
  Probe ((SD("1e"), "Present"), Present);
  Probe ((SD("2e"), "a"), a);
  Probe ((SD("3f"), "b"), b);
  Probe ((SD("5f"), "c"), c);
  Probe ((SD("6e"), "d"), d);
  Probe ((SD("5d"), "e"), e);
  Probe ((SD("3d"), "f"), f);
  Probe ((SD("4e"), "g"), g);
}


/******************************************************************************
  Function "circuits" -- implementation of student circuits

  Do not alter the interface -- function "circuits" must receive four
  signals as inputs and return eight signals as outputs.
******************************************************************************/

void circuits( SD sd, Signal w, Signal x, Signal y, Signal z, 
  Signal Present, Signal a, Signal b, Signal c, Signal d, Signal e,
  Signal f, Signal g )    
{
  Module( (sd, "circuits"), (w, x, y, z), (Present, a, b, c, d, e, f, g) );

  // Declarations for any auxiliary Signals
  Signal notw, notx, noty, notz;

  // Circuit implementation (Not, And, Or gates)
  Not (SD(sd,"2b"), w, notw);
  Not (SD(sd,"3b"), x, notx);
  Not (SD(sd,"4b"), y, noty);
  Not (SD(sd,"5b"), z, notz);

  // Present function P() = w'xy' + wx'z' + w'x'z + w'x'y
  Signal Pfirst, Psecond, Pthird, Pfourth;
 
  And (SD(sd,"2c"), (notw, noty,x ), Pfirst);
  And (SD(sd,"3c"), (notx, w, notz), Psecond);
  And (SD(sd,"4c"), (z, notw, notx), Pthird);
  And (SD(sd,"5c"), (y, notx, notw), Pfourth);

  Or (SD(sd,"2d"), (Pfirst, Psecond, Pthird, Pfourth), Present);
 
  ///  a() = y + w + xz + x'z' 
  Signal afirst, asecond;
  And (SD(sd, "3d"), (x,z), afirst);
  And (SD(sd, "4d"), (notx, notz), asecond);
  Or (SD(sd, "5d"), (afirst, asecond, y, w), a);

  /// b() = y + z' + w + x' 
  Or (SD(sd, "3e"), (y, notz, w, notx), b);

  // c() = y' + z + x + w 
  Or (SD(sd, "3f"), (noty, z, x, w), c);

  // d() =wx + yz + w'y + xz + wy' + x'y'z' 
  Signal dfirst, dsecond, dthird, dfourth, dfifth, dsixth;
  And (SD(sd, "3g"), (w, x), dfirst);
  And (SD(sd, "4g"), (y, z), dsecond);
  And (SD(sd, "5g"), (notw, y), dthird);
  And (SD(sd, "6g"), (x, z), dfourth);
  And (SD(sd, "7g"), (w, noty), dfifth);
  And (SD(sd, "8g"), (notx, noty, notz), dsixth);
  Or (SD(sd, "9g"), (dfirst, dsecond, dthird, dfourth, dfifth, dsixth), d);


  // e() = w + yz' + x'z'
  Signal efirst, esecond;
  And (SD(sd, "3h"), (y, notz), efirst);
  And (SD(sd, "4h"), (notx, notz), esecond);
  Or (SD(sd, "5h"), (efirst, esecond, w), e);

  // f() = x + w + y'z' 
  Signal ffirst;
  And (SD(sd, "3i"), (noty, notz), ffirst);
  Or (SD(sd, "4i"), (ffirst, x, w ), f);

  // g() = y + z' + x + w
  Or (SD(sd,"3j"), (y, notz, x, w), g);
}

