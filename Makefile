CC = gcc
OBJ = test.o deck.o linklist.o

test: $(OBJ)
	$(CC) $(INCDIR) $(LIBDIR) -o $(@) $(OBJ) $(LIB) $(FLAG) -g -O0

.cpp.o:
	$(CC) $(INCDIR) $(LIBDIR) -c -g -O0 $<

clean:
	rm -rf *.o
	rm -rf test
