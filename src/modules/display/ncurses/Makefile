##
## EPITECH PROJECT, 2024
## Arcade [WSL: Ubuntu]
## File description:
## Makefile
##

OUT = ../../../../lib/arcade_ncurses.so
COMP = g++
INCLUDES = -I.. -I/opt/ncurses-6.2.20210508/include
SRC = $(wildcard *.cpp) $(LIBCORE)
OBJ = $(SRC:.cpp=.o)
PATHLIBCORE = ../../core
LIBCORE = $(wildcard $(PATHLIBCORE)/*.cpp $(PATHLIBCORE)/*/*.cpp $(PATHLIBCORE)/*/*/*.cpp)
NCURSES = -lncurses -L/opt/ncurses-6.2.20210508/lib
CPPFLAGS = -Wall -Wextra -Werror -fPIC

all: $(OUT)

$(OUT): $(OBJ)
	@ $(COMP) -shared -o $@ $^ $(NCURSES)

debug: COMP_FLAGS += -g
debug: re

clean:
	@ rm -f $(OBJ)

fclean: clean
	@ rm -f $(OUT)

re : fclean all

.PHONY: all clean fclean debug re
