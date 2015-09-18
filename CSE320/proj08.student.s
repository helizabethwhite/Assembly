/*
 * Author: Hannah White
 *
 * Title: proj08.student.s
 *
 * Brief: Code that implements an assembly program that
 * reads from a file or lines entered by a user and gives
 * a summary of the characters
 */

.global main

.section ".text"
.align   4

main: save  %sp, -96, %sp

      clr   %r16        ! number of upper case letters
      clr   %r17        ! number of lower case letters
      clr   %r18        ! number of decimal digits
      clr   %r19        ! number of hex digits
      clr   %r20        ! number of newline characters
      clr   %r21        ! number of whitespace characters
      clr   %r22        ! number of control characters
      clr   %r23        ! Total number of characters

loop: call  getchar     ! Read one character (returned in %r8)
      nop

      cmp   %r8, -1     ! Compare return value to EOF
      be    end         ! If EOF found, exit loop
      nop

if:  
      cmp   %r8, 'A'    ! Compare character to 'A'
      blt   endif2
      nop
      cmp   %r8, 'Z'    ! Compare character to 'Z'
      bgt   endif2      
      nop
then:
      inc   %r16        ! Increment {A-Z} character count
      inc   %r23
if1:
      cmp   %r8, 'F'    ! Compare character to 'F', looking for hex chars
      bgt   endif1
      nop
then1:
      inc   %r19        ! Increment hexadecimal character count
endif1:
      ba    loop
      nop
endif2:
      
if2:
      cmp   %r8, 'a'    ! Compare character to 'a'
      blt   endif4
      nop
      cmp   %r8, 'z'    ! Compare character to 'z'
      bgt   endif4
      nop
then2:
      inc   %r17        ! Increment {a-z} character count
      inc   %r23
if3:
      cmp   %r8, 'f'    ! Compare character to 'f', looking for hex chars
      bgt   endif3
      nop
then3:
      inc   %r19        ! Increment hexadecimal character count      
endif3:
      ba    loop
      nop
endif4:

if4:
      cmp   %r8, '0'    ! Compare character to '0'
      blt   endif6
      nop
      cmp   %r8, '9'    ! Compare character to '9'
      bgt   endif6
      nop
then4:
      inc   %r18        ! Increment {0-9} character count
      inc   %r19        ! Increment hexidecimal character count
      inc   %r23
endif5:
      ba    loop
      nop
endif6:

if5:
      cmp   %r8, 0x0A   ! Compare character to '0x0A'
      bne   endif8
      nop
then5:
      inc   %r20        ! Increment (0x0A) character count
      inc   %r21        ! Increment whitespace character count
      inc   %r23
endif7:
      ba    loop
      nop
endif8:

if6:
      cmp   %r8, 0x09   ! Compare character to '0x09'
      bne   endif10
      nop
then6:
      inc   %r21        ! Increment whitespace character count
      inc   %r23
endif9:
      ba    loop
      nop
endif10:

if7:
      cmp   %r8, 0x20   ! Compare character to '0x20'
      bne   endif12
      nop
then7:
      inc   %r21        ! Increment whitespace character count
      inc   %r23
endif11:
      ba    loop
      nop
endif12:

if8:
      cmp   %r8, 0x7F   ! Compare character to '0x00'
      bne   endif14
      nop
then8:
      inc   %r22        ! Increment control characters
      inc   %r23
endif13:
      ba    loop
      nop
endif14:

if9:
      cmp   %r8, 0x1F   ! Compare character to '0x00'
      bgt   endif16
      nop
then9:
      inc   %r22        ! Increment control characters
      inc   %r23
endif15:
      ba    loop
      nop
endif16:
      ba    loop
      nop
end:
      set   fmt1, %r8
      mov   %r16, %r9
      call  printf
      nop
      set   fmt2, %r8
      mov   %r17, %r9
      call  printf
      nop
      set   fmt3, %r8
      mov   %r18, %r9
      call  printf
      nop
      set   fmt4, %r8
      mov   %r19, %r9
      call  printf
      nop
      set   fmt5, %r8
      mov   %r20, %r9
      call  printf
      nop
      set   fmt6, %r8
      mov   %r21, %r9
      call  printf
      nop
      set   fmt7, %r8
      mov   %r22, %r9
      nop
      set   fmt8, %r8
      mov   %r23, %r9
      call  printf
      nop 
       

      ret
      restore
      

fmt1: .asciz  "\nNumber of upper case letters: %d\n"
fmt2: .asciz  "\nNumber of lower case letters: %d\n"
fmt3: .asciz  "\nNumber of decimal digits: %d\n"
fmt4: .asciz  "\nNumber of hexadecimal digits: %d\n"
fmt5: .asciz  "\nNumber of newline characters: %d\n"
fmt6: .asciz  "\nNumber of whitespace characters: %d\n"
fmt7: .asciz  "\nNumber of control characters: %d\n"
fmt8: .asciz  "\nTotal number of characters: %d\n"
