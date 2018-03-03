/*
** EPITECH PROJECT, 2016
** wolf3d
** File description:
** game sound theme management
*/

#include	"wolf3d.h"

void		victory()
{
	sfMusic	*victory = sfMusic_createFromFile("sound/won.ogg");

	if (victory) {
		sfMusic_play(victory);
		sfSleep(sfMusic_getDuration(victory));
		sfMusic_destroy(victory);
	}
	write (1, "\nYou won !\n\n", 12);
}

void		my_theme_music(t_sfml *sfml)
{
	sfml->theme = sfMusic_createFromFile("sound/theme.ogg");

	if (sfml->theme) {
		sfMusic_play(sfml->theme);
		sfMusic_setLoop(sfml->theme, sfTrue);
	}
}

void            map_end(int **map, t_my_player *player, t_sfml *sfml,
                        t_mapsize *mapsize)
{
	sfMusic       *music;

	if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue)
		init_player(player, player_pos(map, mapsize->mapdim));
	if (map[(int)player->pos.y][(int)player->pos.x] == 3) {
		if (sfml->theme) {
			sfMusic_stop(sfml->theme);
			sfMusic_destroy(sfml->theme);
		}
		music = sfMusic_createFromFile("sound/map.ogg");
		if (music) {
			sfMusic_play(music);
			sfSleep(sfMusic_getDuration(music));
			sfMusic_destroy(music);
		}
		sfRenderWindow_close(sfml->window);
		write(1, "Level finished !\n", 17);
	}
}
