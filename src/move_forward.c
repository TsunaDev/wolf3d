/*
** EPITECH PROJECT, 2016
** wolf3d
** File description:
** move a position forward
*/

#include	"wolf3d.h"

sfVector2f	move_forward(sfVector2f pos, float direction,
			     float distance)
{
	float		x = cos(direction / 180 * M_PI) * distance;
	float		y = sin(direction / 180 * M_PI) * distance;

	pos.x += x;
	pos.y += y;
	return (pos);
}
