#include <unistd.h>

int		main(int argc, char **argv)
{
	static int	ascii[256];
	int			i;
	int			j;

	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = -1;
	while (argv[1][++i])
	{
		if (ascii[(int)argv[1][i]] == 0)
		{
			++ascii[(int)argv[1][i]];
			write(1, &argv[1][i], 1);
		}
	}
	j = -1;
	while (argv[2][++j])
	{
		if (ascii[(int)argv[2][j]] == 0)
		{
			++ascii[(int)argv[2][j]];
			write(1, &argv[2][j], 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}
