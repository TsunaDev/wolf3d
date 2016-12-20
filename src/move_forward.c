/*
** move_forward.c for bsw3d in /home/tsuna/Epitech/projects/Infograph/wolf3d/bootstrap/bswolf3d
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Thu Dec 15 15:04:01 2016 Martin Van Elslande
** Last update Thu Dec 15 15:46:07 2016 Martin Van Elslande
*/

#include	<SFML/Graphics.h>
#include	<math.h>

sfVector2f      move_forward(sfVector2f pos, float direction, float distance)
{
  float         x;
  float		y;

  x = cos(direction / 180 * M_PI) * distance;
  y = sin(direction / 180 * M_PI) * distance;
  pos.x += x;
  pos.y += y;
  return (pos);
}
