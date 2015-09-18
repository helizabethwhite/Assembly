proj11: proj11.driver.o proj11.support.o
	gcc -o proj11 proj11.driver.c proj11.support.o

proj11.driver.o: proj11.driver.c
	gcc -c proj11.driver.c

prok11.support.o: proj11.driver.s
	gcc -s proj11.driver.s

