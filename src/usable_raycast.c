/*
** usable_raycast.c for wolf3d in /home/tsuna/Epitech/projects/Infograph/wolf3d
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Tue Dec 27 20:52:55 2016 Martin Van Elslande
** Last update Thu Dec 29 19:01:11 2016 Martin Van Elslande
*/

#include        "wolf3d.h"

t_raycast	*raycast_u(sfVector2f pos, float direction, int **map,
			   sfVector2i mapSize)
{
  sfVector2f    moves;
  t_raycast	*raycast;

  raycast = malloc(sizeof(t_raycast));
  raycast->goal = 0;
  raycast->distance = 0.0;
  moves = pos;
  while ((int)(moves.x) < mapSize.x && (int)(moves.y) < mapSize.y &&
         moves.x >= 0.0 && moves.y >= 0.0)
    {
      moves = move_forward(moves, direction, (1.0 / 100.0));
      raycast->distance += (1.0 / 100.0);
      if ((int)(moves.x + 0.01) < mapSize.x &&
          (int)(moves.y + 0.01) < mapSize.y &&
	  map[(int)(moves.y + 0.01)][(int)(moves.x + 0.01)] == 3)
        raycast->goal = 1;
      if ((int)(moves.x + 0.01) < mapSize.x &&
          (int)(moves.y + 0.01) < mapSize.y &&
          map[(int)(moves.y + 0.01)][(int)(moves.x + 0.01)] == 1)
        return (raycast);
    }
  return (raycast);
}
