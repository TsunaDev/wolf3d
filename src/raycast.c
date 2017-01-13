/*
** raycast.c for bs_wolf3d in /home/tsuna/Epitech/projects/Infograph/wolf3d
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Thu Dec 15 16:19:17 2016 Martin Van Elslande
** Last update Fri Jan 13 16:12:47 2017 Martin Van Elslande
*/

#include	"wolf3d.h"

float		raycast(sfVector2f pos, float direction, int **map,
			sfVector2i mapSize)
{
  sfVector2f	moves;
  float		distance;

  (void)mapSize;
  distance = 0.0f;
  moves.x = pos.x;
  moves.y = pos.y;
  while (map[(int)moves.y][(int)moves.x] == 0)
    moves = move_forward(moves, direction, 0.001f);
  distance = sqrt(pow(fabs(moves.x - pos.x), 2) + pow(fabs(moves.y - pos.y), 2));
  return (distance);
}
