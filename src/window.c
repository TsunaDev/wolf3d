/*
** EPITECH PROJECT, 2016
** wolf3d
** File description:
** window management
*/

#include                "wolf3d.h"

t_my_framebuffer        *my_framebuffer_create(int width, int height)
{
	int                   i = 0;
	t_my_framebuffer      *framebuffer = malloc(sizeof(t_my_framebuffer));

	if (!framebuffer)
		return (NULL);
	framebuffer->width = width;
	framebuffer->height = height;
	framebuffer->pixels = malloc(width * height * 4 *
				     sizeof(framebuffer->pixels));
	if (!framebuffer->pixels)
		return (NULL);
	while (i < width * height * 4) {
		framebuffer->pixels[i] = 0;
		i++;
	}
	return (framebuffer);
}

sfRenderWindow          *window_open(int width, int height)
{
	sfVideoMode           mode;
	sfRenderWindow*       window;

	mode.width = width;
	mode.height = height;
	mode.bitsPerPixel = 32;
	window = sfRenderWindow_create(mode, "Wolf3D",
				       sfResize | sfClose, NULL);
	if (!window)
		return (NULL);
	return (window);
}

void	       		game_manager(int **map, t_mapsize *mapsize,
				     t_my_framebuffer *framebuffer,
				     t_my_player *player)
{
	int			i = 0;

	if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue)
		player->pos = will_i_move_forward(player, map, mapsize->mapdim, 0.1f);
	if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue)
		player->pos = will_i_move_forward(player, map, mapsize->mapdim, -0.1f);
	if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue)
		player->direction = move_turn(player->direction, (3.0f * (-1)));
	if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue)
		player->direction = move_turn(player->direction, 3.0f);
	if (sfKeyboard_isKeyPressed(sfKeyZ) == sfTrue && player->z_angle > 0.7f)
		player->z_angle -= 0.1f;
	if (sfKeyboard_isKeyPressed(sfKeyS) == sfTrue && player->z_angle < 4.5f)
		player->z_angle += 0.1f;
	while (i < framebuffer->height * framebuffer->width * 4) {
		framebuffer->pixels[i] = 0;
		i++;
	}
}

void			init_player(t_my_player *player, sfVector2f pos)
{
	player->pos = pos;
	player->direction = 0.0f;
	player->z_angle = 2.0f;
}

int			window_loop(t_sfml *sfml, int **map,
				    t_mapsize *mapsize,
				    t_my_framebuffer *framebuffer)
{
	t_my_player	*player = malloc(sizeof(t_my_player));
	sfEvent		event;

	init_player(player, player_pos(map, mapsize->mapdim));
	my_theme_music(sfml);
	sfRenderWindow_setVerticalSyncEnabled(sfml->window, sfTrue);
	while (sfRenderWindow_isOpen(sfml->window)) {
		sfRenderWindow_pollEvent(sfml->window, &event);
		map_end(map, player, sfml, mapsize);
		sfRenderWindow_clear(sfml->window, sfBlack);
		sfRenderWindow_drawSprite(sfml->window, sfml->sprite, NULL);
		game_manager(map, mapsize, framebuffer, player);
		create_view(map, mapsize, framebuffer, player);
		sfTexture_updateFromPixels(sfml->texture, framebuffer->pixels,
					   SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
		sfRenderWindow_display(sfml->window);
		if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
			return (leave(sfml));
	}
	return (0);
}
