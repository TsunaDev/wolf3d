/*
** EPITECH PROJECT, 2016
** wolf3d
** File description:
** wolf's includes
*/

#ifndef			WOLF_3D_
# define		WOLF_3D_

# include               <math.h>
# include               <SFML/Graphics.h>
# include		<SFML/Audio.h>
# include		<SFML/System.h>
# include		<fcntl.h>
# include      		<unistd.h>
# include               <stdlib.h>

# define		SCREEN_WIDTH	896
# define		SCREEN_HEIGHT	504

typedef	struct		s_my_framebuffer
{
  sfUint8		*pixels;
  int			width;
  int			height;
}			t_my_framebuffer;

typedef struct		s_my_mapsize
{
  sfVector2i		mapdim;
  int			tmp;
}			t_mapsize;

typedef struct		s_sfml
{
  sfRenderWindow	*window;
  sfTexture		*texture;
  sfSprite		*sprite;
  sfMusic		*theme;
}			t_sfml;

typedef struct		s_my_player
{
  sfVector2f		pos;
  float			direction;
  float			z_angle;
  sfVector2f		save;
}			t_my_player;

typedef struct		s_raycast
{
  float			distance;
  int			goal;
}			t_raycast;

void			my_put_pixel(t_my_framebuffer *, int, int, sfColor);
void			map_end(int **, t_my_player *, t_sfml *,
				t_mapsize *);
void			my_theme_music(t_sfml *);
void			init_player(t_my_player *, sfVector2f);
void			victory();
void			create_view(int **, t_mapsize *, t_my_framebuffer *,
				    t_my_player *);
void			my_draw_line(t_my_framebuffer *, sfVector2i,
				     sfVector2i, sfColor);
int			leave(t_sfml *);
int			helper(void);
int			errors(int);
int			match(char *, char *);
int			my_checkenv(char **);
int			my_wolf3d(int **, t_mapsize *);
int			check_map(int **, sfVector2i);
int			window_loop(t_sfml *, int **, t_mapsize *,
				    t_my_framebuffer *);
float			raycast(sfVector2f, float, int **, sfVector2i);
float			move_turn(float, float);
sfVector2f		player_pos(int **, sfVector2i);
sfVector2f		move_forward(sfVector2f, float, float);
sfVector2f		will_i_move_forward(t_my_player *, int **,
					    sfVector2i, float);
sfRenderWindow		*window_open(int, int);
t_my_framebuffer	*my_framebuffer_create(int, int);
t_raycast		*raycast_u(sfVector2f, float, int **, sfVector2i);

#endif /* !WOLF_3D_ */
