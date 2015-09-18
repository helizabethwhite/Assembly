/*
 * Author: Hannah White
 *
 * Title: proj12.support.s
 *
 * Brief: Code that implements an assembly program that
 * computes the absolute value, modulo, factorial, power, and cosine 
 * of double values (integers for the factorial)
 */


.global absolute
.section ".text"
.align 4
absolute:

      save    %sp, -112, %sp

      mov     %i0, %l0
     
      st      %i1, [%sp+104]
      ld      [%sp+104], %f1

      set     0x80000000, %l4

      srl     %l0, 31, %l1            ! Get the sign bit

      cmp     %l1, 1
      be      then
      nop

      st      %i0, [%sp+104]          ! Number not negative, returning as-is
      ld      [%sp+104], %f0
      ba      endif
      nop

      then:                           ! Found a neg number, computing abs value
        
      xor     %l0, %l4, %l3

      st      %l3, [%sp+108]
      ld      [%sp+108], %f0

      endif:

      ret
      restore

.global modulo
.section ".text"
.align 4
modulo:

      save    %sp, -96, %sp

      mov     %i2, %l0
      mov     %i2, %l1

      srl     %l0, 28, %l0

      sll     %l1, 1, %l1       ! Biased exp
      srl     %l1, 21, %l1

      st      %i0, [%sp+100]
      ld      [%sp+100], %f0

      st      %i1, [%sp+104]
      ld      [%sp+104], %f1

      st      %i2, [%sp+108]
      ld      [%sp+108], %f2

      st      %i3, [%sp+112]
      ld      [%sp+112], %f3

      if1:
        cmp   %l0, 8            ! Might be negative zero
        be    elseif1 
        nop

        cmp   %l1, 0            
        be    elseif1           ! biased exp all 0's
        nop

      notzero:
        fdivd %f0, %f2, %f4     ! Find the actual value of the division
        fdtoi %f4, %f6          ! Convert that into an integer (round down)
        fitod %f6, %f6
        fmuld %f2, %f6, %f8     ! Get the remainder
        fsubd %f0, %f8, %f8

        st    %f8, [%sp+104] 
        ld    [%sp+104], %f0
        st    %f9, [%sp+108]
        ld    [%sp+108], %f1  
        ba    endif1
        nop

      elseif1:
        cmp   %i3, 0            ! Checking fraction for 0's
        be    iszero
        nop
        ba    notzero
        nop

      iszero:
        set   0xffffffff, %l6   ! Return "NaN"
        set   0xffffffff, %l7

        st    %l6, [%sp+100]
        ld    [%sp+100], %f0
        
        st    %l7, [%sp+104]
        ld    [%sp+104], %f1
        
      endif1:
        ret
        restore
        

.global factorial
.section ".text"
.align 4
factorial:
      save    %sp, -96, %sp

      mov     %i0, %l0
      mov     1, %l1          ! Initialize count 
      mov     %l0, %l2
      dec     %l2
      
      st      %i0, [%sp+100]
      ld      [%sp+100], %f0
      fitod   %f0, %f0

      st      %l1, [%sp+104]
      ld      [%sp+104], %f2
      fitod   %f2, %f2
      fmuld   %f0, %f2, %f4
  
      inc     %l1

      loop:
      
      cmp     %l1, %l0
      be      endloop
      nop
      
      st      %l1, [%sp+104]
      ld      [%sp+104], %f2
      fitod   %f2, %f2
      fmuld   %f4, %f2, %f4

      inc     %l1
      ba      loop
      nop

      endloop:

      st      %f4, [%sp+100]
      ld      [%sp+100], %f0

      st      %f5, [%sp+104]
      ld      [%sp+104], %f1

      ret
      restore
      
.global power
.section ".text"
.align 4
power:
      save    %sp, -96, %sp

      
      st      %i0, [%sp+100]
      ld      [%sp+100], %f0

      st      %i1, [%sp+104]
      ld      [%sp+104], %f1

      mov     2, %l0            ! Initialize count
      
      fmuld   %f0, %f0, %f2

      beginloop:

      cmp     %l0, %i2
      be      endloop1
      nop

      fmuld   %f0, %f2, %f2
      
      inc     %l0

      ba      beginloop
      nop

      endloop1:

      st      %f2, [%sp+100]
      ld      [%sp+100], %f0

      st      %f3, [%sp+104]
      ld      [%sp+104], %f1

      ret
      restore

.global cosine
.section ".text"
.align 4
cosine:
      save    %sp, -96, %sp

      clr     %l3                 ! Set epsilon
      
      set     epsilon, %l2
      st      %l2, [%sp+96]
      ld      [%sp+96], %f26 
      
      st      %l3, [%sp+100]
      ld      [%sp+100], %f27 

      mov     1,  %l2             ! For beginning of sum
      st      %l2, [%sp+100]
      ld      [%sp+100], %f28
      fitod   %f28, %f28

      mov     1, %l0              ! Initialize count
      mov     2, %l1
      mov     1, %l3              ! Used for alternating b/w 1 and -1

      mov     %i0, %l4            ! Store 'X' 
      mov     %i1, %l5

    loop1:

      neg     %l3                 ! 1 or -1
    

      st      %l1, [%sp+108]      ! Load this into a float reg 
      ld      [%sp+108], %f22
      fitod   %f22, %f22


      clr     %l2
      umul    %l0, %l1, %l2       ! 2*k
      mov     %l2, %o0


      call    factorial
      nop

      st      %f0, [%sp+128]      ! Store factorial results
      st      %f1, [%sp+132]

      mov     %l4, %o0
      mov     %l5, %o1
      mov     %l2, %o2
      
      call    power
      nop

      st      %f0, [%sp+136]
      st      %f1, [%sp+140]

      ld      [%sp+128], %f0        ! Load factorial results
      ld      [%sp+132], %f1
      

      ld      [%sp+136], %f2
      ld      [%sp+140], %f3
      
      fdivd   %f2, %f0, %f4       
     

      fcmpd   %f4, %f26           ! Make sure the result is not too small
      nop
      ble     endloop2
      nop

      fmuld   %f22, %f4, %f4       ! Negate answer if necessary 

      faddd   %f28, %f4, %f28      ! Add to sum 

      inc     %l0

      ba      loop1
      nop

    endloop2:
      
      st    %f28, [%sp+100]
      ld    [%sp+100], %f0

      st    %f29, [%sp+104]
      ld    [%sp+104], %f1

      ret
      restore

epsilon:  .double 0r1.0e-9
pi:       .double 0r3.14159265358979323846
