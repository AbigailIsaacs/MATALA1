CFLAGS = -Wall -lm -g
CC = gcc
AR = ar
all: mains maindloop maindrec libclassloops.a
# %.o: %.c $(CC) $(CFLAGS) -fPIC -c $<

BasicClassification.o: BasicClassification.c
	$(CC) $(CFLAGS) -fPIC -c BasicClassification.c -o BasicClassification.o

advancedClassificationLoop.o: advancedClassificationLoop.c
	$(CC) $(CFLAGS) -fPIC -c advancedClassificationLoop.c -o advancedClassificationLoop.o

advancedClassificationRecursion.o: advancedClassificationRecursion.c
	$(CC) $(CFLAGS) -fPIC -c advancedClassificationRecursion.c -o advancedClassificationRecursion.o

loops: libclassloops.a

libclassloops.a: basicClassification.o advancedClassificationLoop.o 
	$(AR) -rcs libclassloops.a basicClassification.o advancedClassificationLoop.o
	
recursives: libclassrec.a

libclassrec.a: basicClassification.o advancedClassificationRecursion.o 
	$(AR) -rcs libclassrec.a basicClassification.o advancedClassificationRecursion.o
	
loopd: libclassloops.so

libclassloops.so: basicClassification.o advancedClassificationLoop.o 
	$(CC) -shared basicClassification.o advancedClassificationLoop.o -o libclassloops.so

recursived: libclassrec.so	

libclassrec.so: basicClassification.o advancedClassificationRecursion.o 
	$(CC) $(CFLAGS) -shared basicClassification.o advancedClassificationRecursion.o -o libclassrec.so

mains: mains.o libclassrec.a
	$(CC) -o mains mains.o libclassrec.a $(CFLAGS)

mains.o: main.c
	$(CC) -c main.c -o mains.o $(CFLAGS)

maindloop: maindloop.o libclassloops.so
	 $(CC) -o maindloop maindloop.o ./libclassloops.so $(CFLAGS)

maindloop.o: main.c
	$(CC) -c main.c -o maindloop.o $(CFLAGS)

maindrec: maindrec.o libclassrec.so
	 $(CC) -o maindrec maindrec.o ./libclassrec.so $(CFLAGS)

maindrec.o: main.c
	$(CC) -c main.c -o maindrec.o $(CFLAGS)

.PHONY: clean all

clean: 
	rm -f *.o *.a *.so mains maindloop maindrec
