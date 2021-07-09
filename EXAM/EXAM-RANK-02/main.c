#include <stdio.h>
#include "get_next_line.h"

int		main(void)
{
	char	*line;
	int		ret;

	line = 0;
	while ((ret = get_next_line(&line)) > 0)
	{
		printf("return: %i, line: %s\n", ret, line);
		free(line);
		line = 0;
	}
	printf("return: %i, line: %s\n", ret, line);
	free(line);
	line = 0;
	system("leaks a.out");
	return (0);
}
