#include "philosophers.h"

static int	is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (TRUE);
	return (FALSE);
}

static int	validate_argv(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
		{
			if (!is_num(argv[i][j]))
				return (FALSE);
		}
	}
	return (TRUE);
}

int	check_arguments(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (ERROR);
	if (!validate_argv(argc, argv))
		return (ERROR);
	return (SUCCESS);
}
