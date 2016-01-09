# Compiler, I use g++ 4.9
CC=g++-4.9
CPPFLAGS=-O3

ifdef DEBUG
CPPFLAGS=-g
endif

MKDIR = mkdir -p bin
LIBFOLD = -L"/usr/local/lib"
INCFOLD = -I"/usr/local/include"

BINFOLD = bin/

FRAMEWORKS = -ltbb -std=c++11

BINNAME = tbbRaytracer

FILES = $(wildcard src/*.cpp)


all: compile

compile: $(FILES)
	$(CC) $(CPPFLAGS) $(FILES) -o $(BINFOLD)$(BINNAME) $(LIBFOLD) $(INCFOLD) $(FRAMEWORKS)
.PHONY: all

run:
	./$(BINFOLD)$(BINNAME)
.PHONY: run

clean:
	rm -f *.o main