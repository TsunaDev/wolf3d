/*
** move_forward.c for bsw3d in /home/tsuna/Epitech/projects/Infograph/wolf3d
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Thu Dec 15 15:04:01 2016 Martin Van Elslande
** Last update Thu Dec 29 18:59:18 2016 Martin Van Elslande
*/

#include	"wolf3d.h"

sfVector2f	move_forward(sfVector2f pos, float direction,
			     float distance)
{
  float         x;
  float		y;

  x = cos(direction / 180 * M_PI) * distance;
  y = sin(direction / 180 * M_PI) * distance;
  pos.x += x;
  pos.y += y;
  return (pos);
}
