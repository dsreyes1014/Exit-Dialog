CC=gcc
CFLAGS=-Wall -c -std=c99 
GTK=`pkg-config --cflags gtk+-3.0 --libs gtk+-3.0`
PROGRAM=exit-dialog

all: $(PROGRAM)
$(PROGRAM): exit_dialog.o
	$(CC) $(GTK) exit_dialog.o -o $(PROGRAM)	
exit_dialog.o: exit_dialog.c
	$(CC) $(CFLAGS) $(GTK) exit_dialog.c 
	
install: check
	cp -v $(PROGRAM) /usr/local/bin
check:
	ls /usr/local/bin
	
clean:
	rm -v *.o *~ $(PROGRAM)