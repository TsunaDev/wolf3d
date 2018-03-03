/*
** EPITECH PROJECT, 2016
** wolf3d
** File description:
** raycast function
*/

#include        "wolf3d.h"

t_raycast	*raycast_u(sfVector2f pos, float direction, int **map,
			sfVector2i mapSize)
{
	sfVector2f	moves = pos;
	t_raycast	*raycast = malloc(sizeof(t_raycast));

	raycast->goal = 0;
	raycast->distance = 0.0f;
	while ((int)(moves.x) < mapSize.x && (int)(moves.y) < mapSize.y &&
	moves.x >= 0.0f && moves.y >= 0.0f) {
		moves = move_forward(moves, direction, 0.01f);
		raycast->distance += 0.01f;
		if ((int)(moves.x + 0.01f) < mapSize.x &&
		(int)(moves.y + 0.01f) < mapSize.y &&
		map[(int)(moves.y + 0.01f)][(int)(moves.x + 0.01f)] == 3)
			raycast->goal = 1;
		if (((int)(moves.x + 0.01f) < mapSize.x &&
		(int)(moves.y + 0.01f) < mapSize.y &&
		map[(int)(moves.y + 0.01f)][(int)(moves.x + 0.01f)] == 1)
		|| raycast->distance >= 12.0f)
			return (raycast);
	}
	return (raycast);
}
