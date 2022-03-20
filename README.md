# Connect Four

Connect Four console game developed in C++ using Object Oriented principles.

## How to compile
```
g++ -std=c++14 -c -o gamedriver.o gamedriver.cpp
g++ -std=c++14 -c -o Board.o Board.cpp
g++ -std=c++14 -c -o Chip.o Chip.cpp
g++ -std=c++14 -c -o Player.o Player.cpp
g++ -std=c++14 -o connect-4 gamedriver.o Board.o Chip.o Player.o
```

## How to run
```
./connect-4
```

## Video demo
Link: https://youtu.be/tUb1y23Y5f0

## General description of the source files
- Chip.h contains the Chip class definition and functions.
- Chip.cpp contains the Chip class implementation.
- Board.h contains the Board class definition and functions.
- Board.cpp contains the Board class implementation.
- Player.h contains the Player class definition and functions.
- Player.cpp contains the Player class implementation.
- gamedriver.cpp contains the main function that runs the program.
