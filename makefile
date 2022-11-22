CFLAGS = -Wall -lm -g
CC = gcc
AR = ar
all: loops recursives loopd recursived mains maindloop maindrec
%.o: %.c
	$(CC) -c $<
loops: libclassloops.a
libclassloops.a: basicClassification.o advancedClassificationLoop.o 
	$(AR) rcu libclassloops.a basicClassification.o advancedClassificationLoop.o
	ranlib libclassloops.a	
recursives: libclassrec.a
libclassrec.a: basicClassification.o advancedClassificationRecursion.o 
	$(AR) rc libclassrec.a basicClassification.o advancedClassificationRecursion.o
	ranlib libclassrec.a
loopd: libclassloops.so
libclassloops.so: basicClassification.o advancedClassificationLoop.o 
	$(CC) $(CFLAGS) -fPIC -c basicClassification.c advancedClassificationLoop.c
	$(CC) -shared basicClassification.o advancedClassificationLoop.o -o libclassloops.so
recursived: libclassrec.so	
libclassrec.so: basicClassification.o advancedClassificationRecursion.o 
	$(CC) $(CFLAGS) -fPIC -c basicClassification.c advancedClassificationRecursion.c
	$(CC) -shared basicClassification.o advancedClassificationRecursion.o -o libclassrec.so
mains: mains.o libclassrec.a
	$(CC) -o mains mains.o libclassrec.a $(CFLAGS)
mains.o: main.c
	$(CC) -c main.c -o mains.o $(CFLAGS)
maindloop: maindloop.o 
	 $(CC) -o maindloop maindloop.o ./libclassloops.so $(CFLAGS)
maindloop.o: main.c
	$(CC) -c main.c -o maindloop.o $(CFLAGS)
maindrec: maindrec.o 
	 $(CC) -o maindrec maindrec.o ./libclassrec.so $(CFLAGS)
maindrec.o: main.c
	$(CC) -c main.c -o maindrec.o $(CFLAGS)
.PHONY: clean all
clean: 
	rm -f *.o *.a *.so loops recursives loopd recursived mains maindloop maindrec
