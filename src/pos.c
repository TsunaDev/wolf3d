/*
** pos.c for wolf3D in /home/tsuna/Epitech/projects/Infograph/wolf3d
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Mon Dec 26 20:47:58 2016 Martin Van Elslande
** Last update Sun Jan 15 17:15:23 2017 Martin Van Elslande
*/

#include	"wolf3d.h"

float		move_turn(float direction, float angle)
{
  direction = (int)(direction + angle) % 360;
  if (direction < 0)
    direction += 360;
  return (direction);
}

sfVector2f      will_i_move_forward(t_my_player *player, int **map,
				    sfVector2i map_size,
				    float dist)
{
  sfVector2f    tmp;
  sfVector2f	save;

  save = player->pos;
  tmp = move_forward(player->pos, player->direction, dist);
  if (tmp.y >= (float)map_size.y - 0.1f || tmp.x >= (float)map_size.x - 0.1f
      || tmp.y < 0.1f || tmp.x < 0.1f ||
      map[(int)(tmp.y)][(int)(tmp.x)] == 1 ||
      map[(int)(tmp.y + 0.1f)][(int)(tmp.x + 0.1f)] == 1)
    return (save);
  else
    return (tmp);
}

int		check_map(int **map, sfVector2i mapdim)
{
  int		i;
  int		j;
  int		p;
  int		goal;

  p = 0;
  i = 0;
  goal = 0;
  while (i < mapdim.y)
    {
      j = 0;
      while (j < mapdim.x)
	{
	  if (map[i][j] == 4)
	    p++;
	  if (map[i][j] == 3)
	    goal++;
	  j++;
	}
      i++;
    }
  if (p != 1 || goal != 1)
    return (errors(7));
  else
    return (0);
}

sfVector2f	player_pos(int **map, sfVector2i mapdim)
{
  int		i;
  int		j;
  sfVector2f	player;

  i = 0;
  while (i < mapdim.y)
    {
      j = 0;
      while (j < mapdim.x)
	{
	  if (map[i][j] == 4)
	    {
	      player.x = (float)j + 0.5;
	      player.y = (float)i + 0.5;
	    }
	  j++;
	}
      i++;
    }
  return (player);
}
