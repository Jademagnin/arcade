##
## EPITECH PROJECT, 2024
## Arcade [WSL: Ubuntu]
## File description:
## Makefile
##

OUT = ../../../../lib/arcade_sfml.so
COMP = g++
INCLUDES = -I..
SRC = $(wildcard *.cpp) $(LIBCORE)
OBJ = $(SRC:.cpp=.o)
PATHLIBCORE = ../../core
LIBCORE = $(wildcard $(PATHLIBCORE)/*.cpp $(PATHLIBCORE)/*/*.cpp $(PATHLIBCORE)/*/*/*.cpp)
SFML_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system
CPPFLAGS = -Wall -Wextra -Werror -fPIC

all: $(OUT)

$(OUT): $(OBJ)
	@ $(COMP) -shared -o $@ $^ $(SFML_FLAGS)

debug: COMP_FLAGS += -g
debug: re

clean:
	@ rm -f $(OBJ)

fclean: clean
	@ rm -f $(OUT)

re : fclean all

.PHONY: all clean fclean debug re
