/*
** chicken.c for wolf3d in /home/tsuna/Epitech/projects/Infograph/wolf3d
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Thu Dec 29 19:23:49 2016 Martin Van Elslande
** Last update Thu Dec 29 20:53:47 2016 Martin Van Elslande
*/

#include	"wolf3d.h"

int		leave(t_sfml *sfml)
{
  if (sfml->theme != NULL)
    {
      sfMusic_stop(sfml->theme);
      sfMusic_destroy(sfml->theme);
    }
  sfRenderWindow_close(sfml->window);
  write(1, "You chickened out !\n", 20);
  return (84);
}
