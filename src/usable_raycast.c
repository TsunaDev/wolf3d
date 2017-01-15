/*
** usable_raycast.c for wolf3d in /home/tsuna/Epitech/projects/Infograph/wolf3d
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Tue Dec 27 20:52:55 2016 Martin Van Elslande
** Last update Fri Jan 13 16:52:47 2017 Martin Van Elslande
*/

#include        "wolf3d.h"

t_raycast	*raycast_u(sfVector2f pos, float direction, int **map,
			   sfVector2i mapSize)
{
  sfVector2f    moves;
  t_raycast	*raycast;

  raycast = malloc(sizeof(t_raycast));
  raycast->goal = 0;
  raycast->distance = 0.0f;
  moves = pos;
  while ((int)(moves.x) < mapSize.x && (int)(moves.y) < mapSize.y &&
         moves.x >= 0.0f && moves.y >= 0.0f)
    {
      moves = move_forward(moves, direction, 0.01f);
      raycast->distance += 0.01f;
      if ((int)(moves.x + 0.01f) < mapSize.x &&
          (int)(moves.y + 0.01f) < mapSize.y &&
	  map[(int)(moves.y + 0.01f)][(int)(moves.x + 0.01f)] == 3)
        raycast->goal = 1;
      if (((int)(moves.x + 0.01f) < mapSize.x &&
          (int)(moves.y + 0.01f) < mapSize.y &&
	   map[(int)(moves.y + 0.01f)][(int)(moves.x + 0.01f)] == 1)
	  || raycast->distance >= 12.0f)
        return (raycast);
    }
  return (raycast);
}
