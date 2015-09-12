CC = clang++
MODE = release
CMODE = -O3
ifeq ($(MODE), debug)
CMODE = -g
endif
CPP11 = -std=c++11
CFLAGS = -Wall -Werror -Wextra $(CMODE) $(CPP11)
TARGET = tic_tac_toe
INCLUDES = -I./includes
SRC = tic_tac_toe.cpp	\
	  Game.cpp 			\
	  Board.cpp

OBJ = tic_tac_toe.o Game.o Board.o

all: $(TARGET)

$(TARGET) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

tic_tac_toe.o : ./src/tic_tac_toe.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c ./src/tic_tac_toe.cpp

Board.o : ./src/Board.cpp ./includes/Board.hpp
	$(CC) $(CFLAGS) $(INCLUDES) -c ./src/Board.cpp

Game.o : ./src/Game.cpp ./includes/Game.hpp
	$(CC) $(CFLAGS) $(INCLUDES) -c ./src/Game.cpp

re: fclean $(TARGET)

fclean: clean
	rm -rf $(TARGET)

clean:
	rm -rf *.o
