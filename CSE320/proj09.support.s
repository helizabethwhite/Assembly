/*
 * Author: Hannah White
 *
 * Title: proj09.student.s
 *
 * Brief: Code that implements an assembly program that
 * determines whether a double value is normal, inf, NaN, zero 
 * or denormal, and returns a description string
 */

.global is_infinity
.section ".text"
.align 4
is_infinity:
            save      %sp, -96, %sp
            
            mov       %i0, %l0
            mov       0, %i0

            if:
                cmp   %l0, 0x7ff
                be    endif1
                nop
                mov   0, %i0            ! Exp not all 1's, returning 0
                ba    break
                nop

            endif:
                cmp   %i1, 0x00000000
                be    endif1
                nop
                mov   0, %i0            ! Fraction not all 0's, returning 0
                ba    break
                nop

            endif1:
                mov   1, %i0            ! Found an inf number, returning 1
            
            break:
                ret
                restore
            
                  
            .global is_nan
            .section ".text"
            .align 4
is_nan:
            save      %sp, -96, %sp

            mov       %i0, %l0
            mov       0, %i0

            if1:
                cmp   %l0, 0x7ff
                blt   break1            ! Exp not all 1's, returning 0
                nop

            then1:
                cmp   %i1, 0x00000000
                bgt   endif2
                nop
                mov   0, %i0            ! Fraction all 0's, returning 0
                ba    break1
                nop

            endif2:
                mov   1, %i0            ! Found a non-number, returning 1 
            
            break1:
                ret
                restore


            .global is_zero
            .section ".text"
            .align 4
is_zero:
            save      %sp, -96, %sp
            
            mov       %i0, %l0
            mov       %i0, %l1

            mov       %i1, %l2

            mov       0, %i0

            srl       %l1, 27, %l1

            sll       %l0, 1, %l0
            srl       %l0, 21, %l0      ! Biased exp

            sll       %l2, 12, %l2
            srl       %l2, 20, %l2      ! Fraction

            if2:
                cmp   %l1, 8
                be    then2
                nop

                cmp   %l0, 0             
                be    endif4
                nop
                ba    break2            ! Exp not all 0's, returning 0
                nop

            endif3:
                cmp   %i1, 0            ! Fraction all 0's, returning 1
                be    endif4
                nop
                ba    break2            ! Fraction not all 0's, returning 0
                nop

            endif4:
                mov   1, %i0            ! Found a number that is 0, returning 1
                ba    break2
                nop

            then2:                      ! Checking for negative zero

                cmp   %i1, 0            ! Fraction not all 0's, returning 0
                bne   break2
                nop
                ba    endif4            ! Fraction all 0's, returning 1
                nop

            break2:

                ret
                restore

            .global is_denormal
            .section ".text"
            .align 4
is_denormal:
            save      %sp, -96, %sp

            ret
            restore 



            .global negate
            .section ".text"
            .align 4
negate:
            save      %sp, -96, %sp
            mov       %i0, %l0
            clr       %l1

            if3:
                sll   %l0, 15, %l0      ! Shift to the left 15 times
                cmp   %l0, 1            ! Check if sign bit is 1
                be    endif5
                nop
            
            then3:
                orn   %i0, %i0, %l1     ! Sign bit is 0, or it with its complement to get 1
                st    %l1, [%i2+0]
                st    %i1, [%i2+4]
                ba    break3
                nop

            endif5:
                andn  %i0, %i0, %l1     ! Sign bit is 1, and it with its complement to get 0
                st    %l1, [%i2+0]
                st    %i1, [%i2+4]
                ba    break3
                nop

            break3:
                ret
                restore 

            .global absolute
            .section ".text"
            .align 4
absolute:
            save      %sp, -96, %sp

            mov       %i0, %l0
            clr       %l1

            if4:
                sll   %l0, 15, %l0      ! Shift to the left 15 times
                cmp   %l0, 1            ! Check if sign bit is 1
                be    endif6
                nop
            
            then4:
                st   %i0, [%i2+0]       ! Sign bit is 1, do nothing but return orig value
                st   %i1, [%i2+4]
                ba    break4
                nop

            endif6:
                andn  %i0, %i0, %l1     ! Sign bit is 0, and it with complement to get 1
                st   %l1, [%i2+0]
                st   %i1, [%i2+4]
                ba    break4
                nop    
                
            break4:
                ret
                restore

            .global classify
            .section ".text"
            .align 4
classify:
            save      %sp, -96, %sp
            
            mov       %i0, %o0
            mov       %i1, %o1

            call      is_infinity
            nop

            if5:
                cmp   %o0, 1
                be    endif7
                nop


            mov       %i0, %o0            

            call      is_nan
            nop

            if6:
                cmp   %o0, 1
                be    endif8
                nop


            mov       %i0, %o0

            call      is_zero
            nop

            if7:
                cmp   %o0, 1
                be    endif9
                nop
           

            mov       %i0, %o0

            call      is_denormal
            nop
            
            if8:
                cmp   %o0, 1
                be    endif10
                nop
            then8:
                set   fmt5, %l0           ! Normal
                ba    loop
                nop

            endif7:
                set   fmt6, %l0           ! Infinity
                ba    loop
                nop

            endif8:
                set   fmt7, %l0           ! NaN
                ba    loop
                nop
                  
            endif9:
                set   fmt8, %l0           ! Zero
                ba    loop
                nop

            endif10:
                set   fmt9, %l0           ! Denormal
                ba    loop
                nop 

            loop:
                clr   %l1

                ldub  [%l0], %l1          ! Copy string to address
                stb   %l1, [%i2] 
                
                cmp   %l1, '\0'
                be    endloop
                nop

                inc   %l0
                inc   %i2

                ba    loop
                nop

            endloop:

                ret
                restore
                

fmt5: .asciz  "normal\n"
fmt6: .asciz  "infinity\n"
fmt7: .asciz  "not-a-number\n"
fmt8: .asciz  "zero\n"
fmt9: .asciz  "denormal\n"
