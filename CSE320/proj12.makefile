proj12: proj12.driver.o proj12.support.o
	  gcc -o proj12 proj12.driver.c proj12.support.o

proj12.driver.o: proj12.driver.c
	  gcc -c proj12.driver.c

prok12.support.o: proj12.driver.s
	  gcc -s proj12.driver.s
