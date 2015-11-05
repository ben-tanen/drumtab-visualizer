#
#  Makefile for SimFishy project
#

SimFishy: SimFishy.o FishTank.o Fish.o
	g++ -g -o DrumTabVisual SimFishy.o FishTank.o Fish.o

SimFishy.o:  SimFishy.cpp FishTank.h
	g++ -g -Wall -Wextra -o SimFishy.o SimFishy.cpp -c

FishTank.o:  FishTank.cpp FishTank.h Fish.h
	g++ -g -Wall -Wextra -o FishTank.o FishTank.cpp -c

Fish.o:  Fish.cpp Fish.h
	g++ -g -Wall -Wextra -o Fish.o Fish.cpp -c

clean:
	rm -rf DrumTabVisual SimFishy.o FishTank.o Fish.o
