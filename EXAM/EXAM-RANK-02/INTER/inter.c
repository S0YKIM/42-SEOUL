#include <unistd.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	int			i;
	int			j;
	static int	ascii[256];

	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = -1;
	while (argv[1][++i])
	{
		if (ascii[(int)argv[1][i]] == 1)
			continue ;
		j = -1;
		while (argv[2][++j])
		{
			if (argv[1][i] == argv[2][j])
			{
				++ascii[(int)argv[1][i]];
				write(1, &argv[1][i], 1);
				break ;
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}
