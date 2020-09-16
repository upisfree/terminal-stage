cc=gcc
src=src/main.c
out=build/main

all:
	$(cc) $(src) -lncurses -o ${out}

dev:
	clear && $(cc) $(src) -lncurses -o ${out} && ./${out}