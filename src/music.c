/*
** music.c for wolf3d in /home/tsuna/Epitech/projects/Infograph/wolf3d
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Thu Dec 29 14:56:09 2016 Martin Van Elslande
** Last update Thu Dec 29 21:16:21 2016 Martin Van Elslande
*/

#include	"wolf3d.h"

void		victory()
{
  sfMusic	*victory;

  if ((victory = sfMusic_createFromFile("sound/won.ogg")) != NULL)
    sfMusic_play(victory);
  sfSleep(sfMusic_getDuration(victory));
  sfMusic_destroy(victory);
  write (1, "\nYou won !\n\n", 12);
}

void		my_theme_music(t_sfml *sfml)
{
  if ((sfml->theme = sfMusic_createFromFile("sound/theme.ogg")) != NULL)
    {
      sfMusic_play(sfml->theme);
      sfMusic_setLoop(sfml->theme, sfTrue);
    }
}

void            map_end(int **map, t_my_player *player, t_sfml *sfml,
                        t_mapsize *mapsize)
{
  sfMusic       *music;

  if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue)
        init_player(player, player_pos(map, mapsize->mapdim));
  if (map[(int)player->pos.y][(int)player->pos.x] == 3)
    {
      sfMusic_stop(sfml->theme);
      sfMusic_destroy(sfml->theme);
      if ((music = sfMusic_createFromFile("sound/map.ogg")) != NULL)
        sfMusic_play(music);
      sfSleep(sfMusic_getDuration(music));
      sfRenderWindow_close(sfml->window);
      sfMusic_destroy(music);
      write(1, "Level finished !\n", 17);
    }
}
