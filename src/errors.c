/*
** errors.c for wold3D in /home/tsuna/Epitech/projects/Infograph/wolf3d/wolf/wolf3d
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Fri Dec 23 17:23:28 2016 Martin Van Elslande
** Last update Fri Dec 23 17:54:24 2016 Martin Van Elslande
*/

int	errors(int errnb)
{
  if (errnb == 0)
    write(2, "malloc error\n", 13);
  else if (errnb == 1)
    write(2, "One argument needed not more, not less.\n", 40);
  else if (errnb == 2)
    write(2, "Argument is a directory.\n", 25);
  else if (errnb == 3)
    write(2, "Unable to find or read this file.\n", 34);
  else if (errnb == 4)
    {
      write(2, "Invalid map, please use a rectangular map ", 42);
      write(2, "(fill holes with 1).\n", 21);
    }
  else if (errnb == 5)
    write(2, "Invalid character in map, only 0,1 and 2 are enabled.\n", 54);
  else if (errnb == 6)
    write(2, "Invalid environment.\n", 21);
  else
    write(2, "Error that I hold without knowing.\n", 35);
  return (84);
}
