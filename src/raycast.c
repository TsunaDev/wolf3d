/*
** raycast.c for bs_wolf3d in /home/tsuna/Epitech/projects/Infograph/wolf3d/bootstrap/bswolf3d/src
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Thu Dec 15 16:19:17 2016 Martin Van Elslande
** Last update Tue Dec 20 15:50:26 2016 Martin Van Elslande
*/

#include	<SFML/Graphics.h>
#include	<math.h>

sfVector2f      move_forward(sfVector2f pos, float
			     direction, float distance);


float		raycast(sfVector2f pos, float direction, sfVector2i mapSize)
{
  sfVector2f	moves;
  float		distance;
  int		stop;
  int		xunit;
  int		yunit;

  stop = 0;
  distance = 0;
  moves.x = pos.x;
  moves.y = pos.y;
  while ((int)moves.x < mapSize.x && (int)moves.y < mapSize.y &&
	 (int)moves.x >= 0 && (int)moves.y >= 0)
    {
      moves = move_forward(moves, direction, (2.0 / 100.0));
      distance += (2.0 / 100.0);
      if (map[(int)moves.y][(int)moves.x] == 1)
	return (distance - (2.0 / 100.0));
    }
  return (distance);
}
