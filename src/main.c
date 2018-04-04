/*
** EPITECH PROJECT, 2016
** wolf3d
** File description:
** main program function
*/

#include	"wolf3d.h"

int		map_to_inttab(char *buffer, int ***map, t_mapsize *mapsize)
{
	int		i = 0;
	int		j = 0;
	int		n = 0;

	(*map)[0] = malloc(sizeof(int) * mapsize->mapdim.x);
	while (buffer[n] != '\0') {
		if (buffer[n] >= '0' && buffer[n] <= '4')
			(*map)[i][j] = buffer[n] - 48;
		else if (buffer[n] == '\n') {
			i++;
			j = -1;
		} else
			return (errors(5));
		j++;
		n++;
	}
	return (0);
}

int		get_size(t_mapsize *mapsize, char *buffer)
{
	int		i = 0;

	mapsize->mapdim.y = 0;
	mapsize->mapdim.x = 0;
	while (buffer[i]) {
		mapsize->tmp = 0;
		while (buffer[i] != '\n' && buffer[i] != '\0') {
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
	int		fd = open(av, O_DIRECTORY);
	int		bytes;

	if (fd == -1) {
		fd = open(av, O_RDONLY);
		if (fd != -1) {
			bytes = read(fd, (*buffer), 29999);
			(*buffer)[bytes] = '\0';
		} else
			return (errors(3));
	} else
		return (errors(2));
	if (get_size(mapsize, (*buffer)) == 84)
		return (84);
	return (0);
}

int		set_map(int ***map, t_mapsize *mapsize)
{
	int		i = 0;

	while (i < mapsize->mapdim.y) {
		(*map)[i] = malloc(sizeof(int) * mapsize->mapdim.x);
		if (!((*map)[i]))
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
	int		i = 0;

	if (ac == 1)
		return (helper());
	while (i++ < ac - 1) {
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
