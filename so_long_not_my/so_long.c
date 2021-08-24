#include "include/so_long.h"

int	main(int argc, char **argv)
{
	t_lon	*lon;

	if (argc == 2)
	{
		lon = (struct s_lon *)malloc(sizeof(t_lon));
		read_file(argv[1], lon);
		if (check_map(lon) == 1)
		{
			draw_map(lon);
		}
	}
	return (1);
}
