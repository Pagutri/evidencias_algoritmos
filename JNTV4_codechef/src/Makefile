CC = gcc
CFLAGS   = -O3 -lm -Wall -Wstrict-prototypes -ansi -pedantic
COMMONSRC = libraries.h
EXECUTABLE = ../bin/adp_merge


$(EXECUTABLE): adp_merge.o simple_random.o parsing.o\
               output.o $(COMMONSRC)
	$(CC) -o $(EXECUTABLE) adp_merge.o simple_random.o\
                               output.o parsing.o $(CFLAGS)


adp_merge.o: adp_merge.c $(COMMONSRC)
	$(CC) -c -o adp_merge.o adp_merge.c $(CFLAGS)

simple_random.o: simple_random.c simple_random.h $(COMMONSRC)
	$(CC) -c -o simple_random.o simple_random.c $(CFLAGS)

output.o: output.c output.h $(COMMONSRC)
	$(CC) -c -o output.o output.c $(CFLAGS)

parsing.o: parsing.c parsing.h $(COMMONSRC)
	$(CC) -c -o parsing.o parsing.c $(CFLAGS)


clean:
	rm -f *.o $(EXECUTABLE)
