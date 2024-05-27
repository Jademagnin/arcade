##
## EPITECH PROJECT, 2024
## Arcade [WSL: Ubuntu]
## File description:
## Makefile
##

OUT = libcore.a
COMP = g++
SRC = $(wildcard *.cpp */*.cpp */*/*.cpp)
COMP_FLAGS = -Wall -Wextra -Werror -fPIC
OBJ = $(SRC:.cpp=.o)

all: $(OUT)

$(OBJ): %.o: %.cpp
	@ $(COMP) $(COMP_FLAGS) -o $@ -c $<

$(OUT): $(OBJ)
	@ ar rcs $(OUT) $^

debug: COMP_FLAGS += -g -pedantic
debug: re

clean:
	@ rm -f $(OBJ)

fclean: clean
	@ rm -f $(OUT)

re : fclean all

.PHONY: all clean fclean debug re
