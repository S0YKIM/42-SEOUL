#include "get_next_line.h"

int	get_next_line(char **line)
{
	int		i;
	int		size;
	int		bytes;
	char	c;
	char	*tmp;

	bytes = 0;
	size = 1;
	if (!(*line = malloc(1)))
		return (-1);
	*line[0] = 0;
	while ((bytes = read(0, &c, 1)) && ++size && c != '\n')
	{
		if (!(tmp = malloc(size)))
		{
			free(*line);
			return (-1);
		}
		i = -1;
		while (++i < size - 2)
			tmp[i] = (*line)[i];
		tmp[i] = c;
		tmp[i + 1] = 0;
		free(*line);
		*line = tmp;
	}
	return (bytes);
}
