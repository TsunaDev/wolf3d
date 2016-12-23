/*
** main.c for wolf3D in /home/tsuna/Epitech/projects/Infograph/wolf3d/wolf/wolf3d
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Fri Dec 23 14:23:43 2016 Martin Van Elslande
** Last update Fri Dec 23 18:21:23 2016 Martin Van Elslande
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
  (*map)[0] = malloc(sizeof(int) * mapsize->x);
  while (buffer[n] != '\0')
    {
	if (buffer[n] >= '0' && buffer[n] <= '2')
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
  int		j;

  i = 0;
  mapsize->y = 0;
  mapsize->x = 0;
  while (buffer[i] != '\0')
    {
      mapsize->tmp = 0;
      while (buffer[i] != '\n' && buffer[i] != '\0')
	{
	  mapsize->tmp++;
	  i++;
	}
      if (mapsize->y != 0 && mapsize->x != mapsize->tmp)
	return (errors(4));
      mapsize->x = mapsize->tmp;
      mapsize->y++;
      i++;
    }
  return (0);
}

int		create_buffer(char **av, t_mapsize *mapsize, char **buffer)
{
  int		fd;
  int		bytes;

  if ((fd = open(av[1], O_DIRECTORY)) == -1)
    if ((fd = open(av[1], O_RDONLY)) != -1)
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
  while (i < mapsize->y)
    {
      if (((*map)[i] = malloc(sizeof(int) * mapsize->x)) == NULL)
	return (errors(0));
      i++;
    }
}

void		print_map(int **map, t_mapsize *mapsize)
{
  int	i = 0;
  int	j;

  while (i < mapsize->y)
    {
      j = 0;
      while (j < mapsize->x)
	{
	  printf("%d", map[i][j]);
	  j++;
	}
      printf("\n");
      i++;
    }
}

int		main(int ac, char **av, char **env)
{
  int		**map;
  t_mapsize	*mapsize;
  char		*buffer;

  if ((buffer = malloc(sizeof(char) * 30000)) == NULL)
    return (errors(0));
  if ((mapsize = malloc(sizeof(t_mapsize))) == NULL)
    return (errors(0));
  if (my_checkenv(env) == 84)
    return (errors(6));
  if (ac != 2)
    return (errors(1));
  if (create_buffer(av, mapsize, &buffer) == 84)
    return (84);
  map = malloc(sizeof(int*) * mapsize->y);
  if (set_map(&map, mapsize) == 84)
    return (84);
  if (map_to_inttab(buffer, &map, mapsize) == 84)
    return (84);
  my_wolf3d(map, mapsize);
}
