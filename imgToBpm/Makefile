##
## EPITECH PROJECT, 2024
## Arcade [WSL: Ubuntu]
## File description:
## Makefile
##

OUT = imgToBpm
COMP = g++
SRC_DIR = src
SRC = $(wildcard $(SRC_DIR)/*.cpp $(SRC_DIR)/*/*.cpp $(SRC_DIR)/*/*/*.cpp)
OBJ = $(SRC:.cpp=.o)
COMP_FLAGS = -Wall -Wextra -Werror `pkg-config --cflags --libs opencv4`

all: $(OUT)

$(OBJ): %.o: %.cpp
	@ $(COMP) $(COMP_FLAGS) -o $@ -c $<

$(OUT): $(OBJ)
	@ $(COMP) -o $(OUT) $^ $(COMP_FLAGS)

debug: COMP_FLAGS += -g
debug: fclean all

clean:
	@ rm -f $(OBJ)

fclean: clean
	@ rm -f $(OUT)

re : fclean all

.PHONY: all clean fclean debug re


