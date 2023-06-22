tarage=main.cpp
exe:=testeapi
INCLUDS=-I../include/linux -I../lib/include -I../include 
CFLAGS:=$(CFLAGS) -Wall -W  $(INCLUDS) $(LDFLAGS) 
LIBS += -lEApi -lstdc++

all:
	$(CC) $(CFLAGS) $(tarage) -o $(exe) $(LIBS)
.PHONY:clean
clean:
	rm -f $(tarage)
