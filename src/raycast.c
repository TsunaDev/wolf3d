/*
** raycast.c for bs_wolf3d in /home/tsuna/Epitech/projects/Infograph/wolf3d
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Thu Dec 15 16:19:17 2016 Martin Van Elslande
** Last update Thu Jan  5 15:30:54 2017 Martin Van Elslande
*/

#include	"wolf3d.h"

float		raycast(sfVector2f pos, float direction, int **map,
			sfVector2i mapSize)
{
  sfVector2f	moves;
  float		distance;

  distance = 0.0;
  moves.x = pos.x;
  moves.y = pos.y;
  while ((int)(moves.x) < mapSize.x && (int)(moves.y) < mapSize.y &&
	 moves.x >= 0.0 && moves.y >= 0.0)
    {
      moves = move_forward(moves, direction, 0.01f);
      distance += 0.01f;
      if ((int)(moves.x + 0.01f) < mapSize.x &&
	  (int)(moves.y + 0.01f) < mapSize.y &&
	  map[(int)(moves.y + 0.01f)][(int)(moves.x + 0.01f)] == 1)
	return (distance);
    }
  return (distance);
}
