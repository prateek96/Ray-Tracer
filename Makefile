CC = g++
CCFLAGS = -W -Wall -std=c++1y
SRC = main.cpp traycer.cpp object.cpp
EXE = main

all:	build

clean:
	rm -rf *o ${EXE} *.dSYM

build: 
	${CC} ${CCFLAGS} ${SRC} -o ${EXE} 

run:
	./${EXE}
