/*
** my_utils.c for wolf3D in /home/tsuna/Epitech/projects/Infograph/wolf3d/wolf/wolf3d
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Fri Dec 23 14:25:18 2016 Martin Van Elslande
** Last update Fri Dec 23 18:14:59 2016 Martin Van Elslande
*/

#include		"wolf3d.h"

int			my_checkenv(char **env)
{
  int			i;
  int			n;

  i = 0;
  n = 0;
  while (env[i] != NULL)
    {
      if (match(env[i], "DISPLAY*") == 1)
	n++;
      else if (match(env[i], "LIBRARY_PATH=*") == 1)
	n++;
      else if (match(env[i], "LD_LIBRARY_PATH=*") == 1)
	n++;
      else if (match(env[i], "CPATH=*") == 1)
	n++;
      i++;
    }
  if (n != 4)
    return (84);
  else
    return (0);
}
