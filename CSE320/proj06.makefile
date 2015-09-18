project: proj06.driver.c proj06.support.c  
				gcc proj06.driver.c proj06.support.c 

proj06.driver.o: proj06.driver.c
				gcc -c proj06.driver.c

proj06.support.o: proj06.support.c
				gcc -c proj06.support.c
