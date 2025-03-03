#####################################################################
#       (c) Copyright 2015, Hogeschool voor de Kunsten Utrecht
#                       Hilversum, the Netherlands
#####################################################################
#
# Description   : Makefile for osc server and client
#
# Author        : Marc_G
# E-mail        : marcg@dinkum.nl
#
####################################################################/

CC = g++ -g
CFLAGS = -Wall -std=c++1z -I/opt/homebrew/Cellar/liblo/0.32/include
LDFLAGS = -llo -L/opt/homebrew/lib

all: osc_client osc_server

osc_client: osc_client.o
	$(CC) -o $@ $(CFLAGS) osc_client.o $(LDFLAGS)

osc_server: osc_server.o osc.o
	$(CC) -o $@ $(CFLAGS) osc_server.o osc.o $(LDFLAGS)


.cpp.o:
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f osc_client osc_server

