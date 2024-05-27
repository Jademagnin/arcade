##
## EPITECH PROJECT, 2024
## arcade_test
## File description:
## Makefile
##

all:
	@ make -C ncurses
	@ make -C sdl2
	@ make -C sfml

debug:
	@ make -C ncurses debug
	@ make -C sdl2 debug
	@ make -C sfml debug

clean:
	@ make -C ncurses clean
	@ make -C sdl2 clean
	@ make -C sfml clean

fclean: clean
	@ make -C ncurses fclean
	@ make -C sdl2 fclean
	@ make -C sfml fclean

re : fclean all

.PHONY: all clean fclean re debug
