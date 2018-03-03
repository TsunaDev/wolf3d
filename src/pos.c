/*
** EPITECH PROJECT, 2016
** wolf3d
** File description:
** position manager
*/

#include	"wolf3d.h"

float		move_turn(float direction, float angle)
{
	direction = (int)(direction + angle) % 360;
	if (direction < 0)
		direction += 360;
	return (direction);
}

sfVector2f      will_i_move_forward(t_my_player *player, int **map,
				sfVector2i map_size,
				float dist)
{
	sfVector2f	tmp;
	sfVector2f	save;

	save = player->pos;
	tmp = move_forward(player->pos, player->direction, dist);
	if (tmp.y >= (float)map_size.y - 0.1f || tmp.x >= (float)map_size.x - 0.1f
	|| tmp.y < 0.1f || tmp.x < 0.1f ||
	map[(int)(tmp.y)][(int)(tmp.x)] == 1 ||
	map[(int)(tmp.y + 0.1f)][(int)(tmp.x + 0.1f)] == 1)
		return (save);
	return (tmp);
}

int		check_map(int **map, sfVector2i mapdim)
{
	int		i = 0;
	int		j;
	int		p = 0;
	int		goal = 0;

	while (i < mapdim.y) {
		j = 0;
		while (j < mapdim.x) {
			if (map[i][j] == 4)
				p++;
			if (map[i][j] == 3)
				goal++;
			j++;
		}
		i++;
	}
	if (p != 1 || goal != 1)
		return (errors(7));
	else
		return (0);
}

sfVector2f	player_pos(int **map, sfVector2i mapdim)
{
	int		i = 0;
	int		j;
	sfVector2f	player;

	while (i < mapdim.y) {
		j = 0;
		while (j < mapdim.x) {
			if (map[i][j] == 4) {
				player.x = (float)j + 0.5;
				player.y = (float)i + 0.5;
			}
			j++;
		}
		i++;
	}
	return (player);
}
