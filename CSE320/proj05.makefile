project: proj05.driver.c proj05.support.c /user/cse320/lib/bitlib.o
		gcc proj05.driver.c proj05.support.c /user/cse320/lib/bitlib.o

proj05.driver.o: proj05.driver.c
		gcc -c proj05.driver.c

proj05.support.o: proj05.support.c
		gcc -c proj05.support.c
