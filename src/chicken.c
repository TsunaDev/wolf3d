/*
** EPITECH PROJECT, 2016
** wolf3d
** File description:
** If you quit you're a chicken
*/

#include	"wolf3d.h"

int		leave(t_sfml *sfml)
{
	sfMusic	*chicken;

	if (sfml->theme != NULL) {
		sfMusic_stop(sfml->theme);
		sfMusic_destroy(sfml->theme);
	}
	chicken = sfMusic_createFromFile("sound/chicken.ogg");
	if (chicken != NULL) {
		sfMusic_play(chicken);
		sfSleep(sfMusic_getDuration(chicken));
		sfMusic_destroy(chicken);
	}
	sfRenderWindow_close(sfml->window);
	write(1, "You chickened out !\n", 20);
	return (84);
}
