CC = gcc
CFLAGS   = -O3 -lm -Wall -Wstrict-prototypes -ansi -pedantic
COMMONSRC = libraries.h
EXECUTABLE = ../bin/adp_merge


$(EXECUTABLE): adp_merge.o output.o $(COMMONSRC)
	$(CC) -o $(EXECUTABLE) adp_merge.o output.o $(CFLAGS)


adp_merge.o: adp_merge.c $(COMMONSRC)
	$(CC) -c -o adp_merge.o adp_merge.c $(CFLAGS)

output.o: output.c output.h $(COMMONSRC)
	$(CC) -c -o output.o output.c $(CFLAGS)


clean:
	rm -f *.o $(EXECUTABLE)
