/*
** EPITECH PROJECT, 2016
** wolf3d
** File description:
** raycaster
*/

#include	"wolf3d.h"

float		raycast(sfVector2f pos, float direction, int **map,
			sfVector2i mapSize)
{
	sfVector2f	moves;
	float		distance;

	moves.x = pos.x;
	moves.y = pos.y;
	while ((int)(moves.x) < mapSize.x && (int)(moves.y) < mapSize.y &&
	       moves.x > 0.0f && moves.y > 0.0f) {
		moves = move_forward(moves, direction, 0.0001f);
		if ((int)(moves.x) < mapSize.x &&
		    (int)(moves.y) < mapSize.y &&
		    map[(int)(moves.y)][(int)(moves.x)] == 1)
			return (sqrt(pow((moves.x - pos.x), 2) +
				pow((moves.y - pos.y), 2)));
	}
	distance = sqrt(pow((moves.x - pos.x), 2) + pow((moves.y - pos.y), 2));
	return (distance);
}
