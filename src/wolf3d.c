/*
** wolf3d.c for wolf3d in /home/tsuna/Epitech/projects/Infograph/wolf3d/wolf/wolf3d
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Fri Dec 23 18:15:23 2016 Martin Van Elslande
** Last update Fri Dec 23 20:01:54 2016 Martin Van Elslande
*/

#include	"wolf3d.h"

int		my_wolf3d(int **map, t_mapsize *mapsize)
{
  sfVector2i	mapsize1;
  float		direction;
  sfVector2f	pos;

  pos.x = 1.5;
  pos.y = 2.5;
  mapsize1.x = mapsize->x;
  mapsize1.y = mapsize->y;
  direction = 90.0;
  printf("%f\n", raycast(pos, direction, map, mapsize1));
}
