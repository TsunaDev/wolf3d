/*
** help.c for wolf3d in /home/tsuna/Epitech/projects/Infograph/wolf3d/wolf/wolf3d
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Sun Jan 15 22:18:46 2017 Martin Van Elslande
** Last update Sun Jan 15 23:30:17 2017 Martin Van Elslande
*/

#include	<unistd.h>

int		helper(void)
{
  write(1, "Welcome on wolf3D !\n\n", 22);
  write(1, "How to play ?\n", 14);
  write(1, "You just have to type ./wolf3d.sh followed by :\n", 48);
  write(1, "campaign : play the campaign mode.\n", 35);
  write(1, "easy : play on easy maps mode.\n", 31);
  write(1, "medium : play on medium maps mode.\n", 35);
  write(1, "hard : play on hard maps mode.\n", 32);
  write(1, "custom : you can add your own maps in the maps/custom ", 54);
  write(1, "and then play on it (max size: 170x170)\n\n", 41);
  write(1, "Controls :\n", 11);
  write(1, "Up and Down arrows to move in the up or down.\n", 46);
  write(1, "Right and Left arrows to rotate the camera.\n", 44);
  write(1, "Space bar to go back to the initial position.\n", 46);
  write(1, "Escape to leave.\n\n\n", 19);
  write(1, "Good luck, have fun !\n", 22);
  return (0);
}
