##
## EPITECH PROJECT, 2023
## arcade
## File description:
## makefile
##

all:
	@ make -C snake
	@ make -C pacman
	@ make -C testgame
	@ make -C menu

debug:
	@ make -C snake debug
	@ make -C pacman debug
	@ make -C testgame debug
	@ make -C menu debug

clean:
	@ make -C snake clean
	@ make -C pacman clean
	@ make -C testgame clean
	@ make -C menu clean

fclean: clean
	@ make -C snake fclean
	@ make -C pacman fclean
	@ make -C testgame fclean
	@ make -C menu fclean

re : fclean all

.PHONY: all clean fclean re debug
