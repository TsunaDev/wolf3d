/*
** window.c for wolf3d in /home/tsuna/Epitech/projects/Infograph/wolf3d
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Fri Dec 23 20:09:15 2016 Martin Van Elslande
** Last update Sat Jan 14 20:01:48 2017 Martin Van Elslande
*/

#include                "wolf3d.h"

t_my_framebuffer        *my_framebuffer_create(int width, int height)
{
  int                   i;
  t_my_framebuffer      *framebuffer;

  i = 0;
  if ((framebuffer = malloc(sizeof(t_my_framebuffer))) == NULL)
    return (NULL);
  framebuffer->width = width;
  framebuffer->height = height;
  if ((framebuffer->pixels = malloc
       (width * height * 4 * sizeof(framebuffer->pixels))) == NULL)
    return (NULL);
  while (i < width * height * 4)
    {
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
  window = sfRenderWindow_create(mode, "Best Coach Ever",
				 sfResize | sfClose, NULL);
  if (window == NULL)
    return (NULL);
  return (window);
}

void	       		game_manager(int **map, t_mapsize *mapsize,
				     t_my_framebuffer *framebuffer,
				     t_my_player *player)
{
  int			i;

  i = 0;
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
  while (i < framebuffer->height * framebuffer->width * 4)
    {
      framebuffer->pixels[i] = 0;
      i++;
    }
}

void			init_player(t_my_player *player, sfVector2f pos)
{
  player->pos = pos;
  player->direction = 45.0f;
  player->z_angle = 2.0f;
}

int			window_loop(t_sfml *sfml, int **map,
				    t_mapsize *mapsize,
				    t_my_framebuffer *framebuffer)
{
  t_my_player		*player;
  sfEvent		event;

  player = malloc(sizeof(t_my_player));
  init_player(player, player_pos(map, mapsize->mapdim));
  my_theme_music(sfml);
  sfRenderWindow_setVerticalSyncEnabled(sfml->window, sfTrue);
  while (sfRenderWindow_isOpen(sfml->window))
    {
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
