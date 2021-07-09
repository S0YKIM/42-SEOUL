#include "get_next_line.h"

static int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

static char	*ft_strdup(char *str)
{
	char		*result;
	int			len;
	int			i;

	len = ft_strlen(str);
	result = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (str[i])
	{
		result[i] = str[i];
		++i;
	}
	result[i] = '\0';
	return (result);
}

static char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	int		s1_len;
	int		s2_len;
	int		i;
	int		j;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	i = 0;
	j = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		++i;
	}
	while (s2[j])
	{
		result[i] = s2[j];
		++i;
		++j;
	}
	result[i] = '\0';
	return (result);
}

static int	get_index_of_newline(char *backup)
{
	int		i;

	i = 0;
	while (backup[i])
	{
		if (backup[i] == '\n')
			return (i);
		++i;
	}
	return (-1);
}

int			get_next_line(char **line)
{
	static char	*backup;
	char		buf[1001];
	int			bytes;
	int			index;
	char		*tmp;

	if (!backup)
	{
		backup = ft_strdup("");
		while ((bytes = read(0, buf, 1000)) > 0)
		{
			buf[bytes] = '\0';
			tmp = backup;
			backup = ft_strjoin(backup, buf);
			free(tmp);
		}
	}
	index = get_index_of_newline(backup);
	if (index > 0)
	{
		backup[index] = '\0';
		*line = ft_strdup(backup);
		tmp = backup;
		backup = ft_strdup(backup + index + 1);
		free(tmp);
		return (1);
	}
	else
	{
		*line = backup;
		return (0);
	}
}
