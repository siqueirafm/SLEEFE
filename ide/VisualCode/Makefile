CC = g++
AR = ar

CFLAGS = -O2 -std=c++17 -Wall -Wextra -pedantic -c
LFLAGS =

INC1 = ../../src/lib
INC2 = ../../src/demo

INCS = -I$(INC1) -I$(INC2)
LIBS = -L../../lib -lsleefe -lm

LIBOBJS = UniSleefeBuilder.o UniSleefeTables.o UniSleefe.o

OBJ = main.o
LIB = libsleefe.a
EXE = sleefe-demo

UniSleefeBuilder.o:	$(INC1)/UniSleefeBuilder.hpp $(INC1)/UniSleefeBuilder.cpp
	$(CC) $(CFLAGS) $(INCS) $(INC1)/UniSleefeBuilder.cpp

UniSleefeTables.o:	$(INC1)/UniSleefeBuilder.hpp $(INC1)/UniSleefeTables.cpp
	$(CC) $(CFLAGS) $(INCS) $(INC1)/UniSleefeTables.cpp

UniSleefe.o:	$(INC1)/UniSleefeBuilder.hpp $(INC1)/UniSleefeBuilder.cpp $(INC1)/UniSleefeTables.cpp \
		$(INC1)/UniSleefe.hpp $(INC1)/UniSleefe.cpp
	$(CC) $(CFLAGS) $(INCS) $(INC1)/UniSleefe.cpp

lib: 		$(LIBOBJS)
	$(AR) rc $(LIB) $(LIBOBJS)
	ranlib $(LIB)
	mv $(LIB) ../../lib

sleefe-demo: 	$(OBJ)
	$(CC) $(LFLAGS) $(OBJ) -o $(EXE) $(LIBS)
	mv $(EXE) ../../bin

main.o:		$(INC1)/Sleefe.hpp $(INC1)/UniSleefe.hpp $(INC1)/UniSleefeBuilder.hpp \
		$(INC1)/UniSleefe.cpp $(INC1)/UniSleefeBuilder.cpp $(INC1)/UniSleefeTables.cpp \
		$(INC2)/main.cpp
	$(CC) $(CFLAGS) $(INCS) $(INC2)/main.cpp

clean:
	rm -f *.o *~

realclean:
	rm -f *.o *~ ../../lib/$(LIB) ../../bin/$(EXE)
