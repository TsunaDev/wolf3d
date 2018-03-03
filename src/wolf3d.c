/*
** EPITECH PROJECT, 2016
** wolf3d
** File description:
** display's main functions
*/

#include	"wolf3d.h"

void			draw_floor(t_my_framebuffer *framebuffer,
				sfVector2i from, sfVector2i to)
{
	int		i;
	sfColor		color;

	color.r = 200;
	color.g = 173;
	color.b = 127;
	color.a = 200;
	i = from.y;
	while (i < to.y) {
		my_put_pixel(framebuffer, from.x, i, color);
		i++;
	}
}

void			draw_vertical_line(t_my_framebuffer *framebuffer,
					   sfVector2i from, sfVector2i to,
					   t_raycast *raycast)
{
	int		i;
	sfColor		color;

	if (raycast->goal == 0)
		color = sfRed;
	else
		color = sfGreen;
	if (raycast->distance > 12.0)
		color.a = 0;
	else
		color.a = 255 - raycast->distance * 20;
	i = from.y;
	if (from.y < 0)
		from.y = 0;
	if (to.y > SCREEN_HEIGHT)
		to.y = SCREEN_HEIGHT;
	while (i < to.y) {
		my_put_pixel(framebuffer, from.x, i, color);
		i++;
	}
}

void			create_view(int **map, t_mapsize *mapsize,
				    t_my_framebuffer *framebuffer,
				    t_my_player *player)
{
	sfVector2i		from;
	sfVector2i		to;
	float			diff;
	float			dir;
	t_raycast		*raycast;

	raycast = malloc(sizeof(t_raycast));
	dir = player->direction - 30;
	for (int i = 0; i < SCREEN_WIDTH; i++) {
		raycast = raycast_u(player->pos, dir, map, mapsize->mapdim);
		raycast->distance *= cos((dir - player->direction) * M_PI / 180);
		if (raycast->distance < 0.0)
			raycast->distance = 0.01;
		diff = (1.0 / raycast->distance) * (float)SCREEN_WIDTH;
		from.x = i;
		from.y = (int)(((float)SCREEN_HEIGHT / player->z_angle) - (diff / 2.0));
		to.y = (int)(((float)SCREEN_HEIGHT / player->z_angle) + (diff / 2.0));
		draw_vertical_line(framebuffer, from, to, raycast);
		dir += (60.0 / SCREEN_WIDTH);
	}
}

int                    all_tasks(int **map, t_mapsize *mapsize)
{
	t_sfml		*sfml;
	t_my_framebuffer      *framebuffer;
	sfEvent		event;

	if ((sfml = malloc(sizeof(t_sfml))) == NULL)
		return (errors(0));
	if ((framebuffer = malloc(sizeof(t_my_framebuffer))) == NULL)
		return (errors(0));
	sfml->window = window_open(SCREEN_WIDTH, SCREEN_HEIGHT);
	sfRenderWindow_pollEvent(sfml->window, &event);
	sfml->sprite = sfSprite_create();
	sfml->texture = sfTexture_create(SCREEN_WIDTH, SCREEN_HEIGHT);
	framebuffer = my_framebuffer_create(SCREEN_WIDTH, SCREEN_HEIGHT);
	sfSprite_setTexture(sfml->sprite, sfml->texture, sfTrue);
	if (window_loop(sfml, map, mapsize, framebuffer) == 84)
		return (84);
	sfSprite_destroy(sfml->sprite);
	sfTexture_destroy(sfml->texture);
	free(framebuffer->pixels);
	sfRenderWindow_destroy(sfml->window);
	return (0);
}

int		my_wolf3d(int **map, t_mapsize *mapsize)
{
	if (check_map(map, mapsize->mapdim) == 84)
		return (84);
	return (all_tasks(map, mapsize));
}
