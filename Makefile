##
## EPITECH PROJECT, 2023
## arcade
## File description:
## makefile
##

OUT = arcade
INCLUDES = -Isrc/ -Isrc/modules -Isrc/handlers -Isrc/utils
COMP = g++
SRC_DIR = src
SRC = $(wildcard $(SRC_DIR)/*.cpp) \
	$(wildcard $(SRC_DIR)/handlers/*.cpp) \
	$(wildcard $(SRC_DIR)/utils/*.cpp) \
	$(SRC_DIR)/modules/core/Input.cpp

OBJ = $(SRC:.cpp=.o)
COMP_FLAGS = -Wall -Wextra -Werror -ldl -fno-gnu-unique -fPIC

all: graphicals games core

$(OBJ): %.o: %.cpp
	@ $(COMP) $(INCLUDES) $(COMP_FLAGS) -o $@ -c $<

core: $(OBJ)
	@ $(COMP) -o $(OUT) $^ $(COMP_FLAGS)

games:
	@ make -C src/modules/games --no-print-directory

graphicals:
	@ make -C src/modules/display --no-print-directory

run: re
	@ ./$(OUT) ./lib/arcade_sfml.so

ru:
	@ ./$(OUT) ./lib/arcade_sfml.so

debug: COMP_FLAGS += -g
debug: fclean core
	@ make -C src/modules/display debug --no-print-directory
	@ make -C src/modules/games debug --no-print-directory
	@ make core --no-print-directory

clean:
	@ rm -f $(OBJ)
	@ make -C src/modules/games clean --no-print-directory
	@ make -C src/modules/display clean --no-print-directory

fclean: clean
	@ rm -f $(OUT)
	@ make -C src/modules/games fclean --no-print-directory
	@ make -C src/modules/display fclean --no-print-directory

re : fclean all

.PHONY: all clean fclean debug re games graphicals core
