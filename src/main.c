/*
** main.c for wolf3D in /home/tsuna/Epitech/projects/Infograph/wolf3d
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Fri Dec 23 14:23:43 2016 Martin Van Elslande
** Last update Sun Jan 15 22:35:36 2017 Martin Van Elslande
*/

#include	"wolf3d.h"

int		map_to_inttab(char *buffer, int ***map, t_mapsize *mapsize)
{
  int		i;
  int		j;
  int		n;

  i = 0;
  j = 0;
  n = 0;
  (*map)[0] = malloc(sizeof(int) * mapsize->mapdim.x);
  while (buffer[n] != '\0')
    {
      if (buffer[n] >= '0' && buffer[n] <= '4')
	(*map)[i][j] = buffer[n] - 48;
      else if (buffer[n] == '\n')
	{
	  i++;
	  j = -1;
	}
      else
	return (errors(5));
      j++;
      n++;
    }
  return (0);
}

int		get_size(t_mapsize *mapsize, char *buffer)
{
  int		i;

  i = 0;
  mapsize->mapdim.y = 0;
  mapsize->mapdim.x = 0;
  while (buffer[i] != '\0')
    {
      mapsize->tmp = 0;
      while (buffer[i] != '\n' && buffer[i] != '\0')
	{
	  mapsize->tmp++;
	  i++;
	}
      if (mapsize->mapdim.y != 0 && mapsize->mapdim.x != mapsize->tmp
	  && buffer[i - mapsize->tmp] >= '0' &&
	  buffer[i -mapsize->tmp] <= '4')
	return (errors(4));
      mapsize->mapdim.x = mapsize->tmp;
      mapsize->mapdim.y++;
      i++;
    }
  return (0);
}

int		create_buffer(char *av, t_mapsize *mapsize, char **buffer)
{
  int		fd;
  int		bytes;

  if ((fd = open(av, O_DIRECTORY)) == -1)
    if ((fd = open(av, O_RDONLY)) != -1)
      {
	bytes = read(fd, (*buffer), 29999);
	(*buffer)[bytes] = '\0';
      }
    else
      return (errors(3));
  else
    return (errors(2));
  if (get_size(mapsize, (*buffer)) == 84)
    return (84);
  return (0);
}

int		set_map(int ***map, t_mapsize *mapsize)
{
  int		i;

  i = 0;
  while (i < mapsize->mapdim.y)
    {
      if (((*map)[i] = malloc(sizeof(int) * mapsize->mapdim.x)) == NULL)
	return (errors(0));
      i++;
    }
  return (0);
}

int		main(int ac, char **av, char **env)
{
  int		**map;
  t_mapsize	*mapsize;
  char		*buffer;
  int		i;

  i = 0;
  if (ac == 1)
    return (helper());
  while (i++ < ac - 1)
    {
      if ((buffer = malloc(sizeof(char) * 30000)) == NULL)
	return (errors(0));
      if ((mapsize = malloc(sizeof(t_mapsize))) == NULL)
	return (errors(0));
      if (my_checkenv(env) == 84)
 	return (errors(6));
      if (create_buffer(av[i], mapsize, &buffer) == 84)
	return (84);
      map = malloc(sizeof(int*) * mapsize->mapdim.y);
      if (set_map(&map, mapsize) == 84 || map_to_inttab(buffer, &map, mapsize)
	  == 84 || my_wolf3d(map, mapsize) == 84)
	return (84);
    }
  victory();
  return (0);
}
