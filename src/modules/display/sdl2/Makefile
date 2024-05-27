##
## EPITECH PROJECT, 2024
## Arcade [WSL: Ubuntu]
## File description:
## Makefile
##

OUT = ../../../../lib/arcade_sdl2.so
COMP = g++
INCLUDES = -I../
SRC = $(wildcard *.cpp) $(LIBCORE)
OBJ = $(SRC:.cpp=.o)
PATHLIBCORE = ../../core
LIBCORE = $(wildcard $(PATHLIBCORE)/*.cpp $(PATHLIBCORE)/*/*.cpp $(PATHLIBCORE)/*/*/*.cpp)
CPPFLAGS = -Wall -Wextra -Werror -fPIC
SDL_FLAGS = `sdl2-config --libs` -lSDL2_ttf

all: $(OUT)

$(OUT): $(OBJ)
	@ $(COMP) -shared -o $@ $^ $(SDL_FLAGS)

debug: COMP_FLAGS += -g
debug: re

clean:
	@ rm -f $(OBJ)

fclean: clean
	@ rm -f $(OUT)

re : fclean all

.PHONY: all clean fclean debug re
