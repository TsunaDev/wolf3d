/*
** EPITECH PROJECT, 2016
** wolf3d
** File description:
** util functions
*/

#include		"wolf3d.h"

int			my_checkenv(char **env)
{
	int			i = 0;

	while (env[i] != NULL) {
		if (match(env[i], "DISPLAY*") == 1)
			return 0;
		i++;
	}
	return (84);
}
