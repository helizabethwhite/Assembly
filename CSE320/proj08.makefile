proj08: proj08.student.o
		gcc -o proj08 proj08.student.o

proj08.student.o: proj08.student.s
		gcc -s proj08.student.s

