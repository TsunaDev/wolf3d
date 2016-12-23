/*
** wolf3d.h for wolf3D in /home/tsuna/Epitech/projects/Infograph/wolf3d/wolf/wolf3d
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Fri Dec 23 18:03:36 2016 Martin Van Elslande
** Last update Fri Dec 23 20:00:13 2016 Martin Van Elslande
*/

#ifndef			WOLF_3D_
# define		WOLF_3D_

# include               <math.h>
# include               <SFML/Graphics.h>
# include		<SFML/Audio.h>
# include		<fcntl.h>
# include      		<unistd.h>
# include               <stdlib.h>

# define		SCREEN_WIDTH	1920
# define		SCREEN_HEIGHT	1080

typedef	struct		s_my_framebuffer
{
  sfUint8		*pixels;
  int			width;
  int			height;
}			t_my_framebuffer;

typedef struct		s_my_mapsize
{
  int			x;
  int			y;
  int			tmp;
}			t_mapsize;

void			my_draw_line(t_my_framebuffer *framebuffer,
				     sfVector2i from, sfVector2i to,
				     sfColor color);
sfRenderWindow		*window_open(int width, int height);
t_my_framebuffer	*my_framebuffer_create(int width, int height);
void			window_loop(sfRenderWindow *window, sfSprite *sprite);
void			my_put_pixel(t_my_framebuffer *framebuffer, int x,
				     int y, sfColor color);
sfVector2f		move_forward(sfVector2f pos, float direction,
				     float distance);
int			errors(int errnb);
float			raycast(sfVector2f pos, float direction,
				int **map, sfVector2i mapSize);
int			my_getnbr(char *str);
int			match(char *str1, char *str2);
int			my_checkenv(char **env);

#endif			/* !WOLF_3D_ */
