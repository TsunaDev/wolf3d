/*
** EPITECH PROJECT, 2016
** wolf3d
** File description:
** errors management
*/

#include	<unistd.h>

int	errors(int errnb)
{
	if (errnb == 0)
		write(2, "malloc error\n", 13);
	else if (errnb == 1)
		write(2, "One argument needed not more, not less.\n", 40);
	else if (errnb == 2)
		write(2, "Argument is a directory.\n", 25);
	else if (errnb == 3)
		write(2, "Unable to find or read this file.\n", 34);
	else if (errnb == 4) {
		write(2, "Invalid map, please use a rectangular map ", 42);
		write(2, "(fill holes with 1).\n", 21);
	}
	else if (errnb == 5)
		write(2, "Invalid character in map, only 0,1 and 2 are enabled.\n", 54);
	else if (errnb == 6)
		write(2, "Invalid environment.\n", 21);
	else if (errnb == 7) {
		write(2, "Invalid number of players (4) or goals (3) in the map,", 54);
		write(2, " only one of each allowed\n", 26);
	}
	return (84);
}
