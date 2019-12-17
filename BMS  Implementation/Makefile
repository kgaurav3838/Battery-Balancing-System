# Welcome to Battery balancing algorithm during the discharge cycle.!!!
# bmscell is the executable file. We have here only signle dependency i.e. bms.o 
# Make is used to do faster compilation . It can compile multiple file at once.

all: bms

bms : bms.o 
	gcc bms.c -o bms

bms.o : bms.c        
	gcc bms.c


clean : 
	rm -rf *o bmscell

