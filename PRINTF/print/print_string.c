/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 16:37:17 by sokim             #+#    #+#             */
/*   Updated: 2021/06/12 17:44:11 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*trim_string(char *str, int len)
{
	int		i;
	char	*buf;

	if (!(buf = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		buf[i] = str[i];
		++i;
	}
	buf[i] = '\0';
	return (buf);
}

int			add_width_to_buf(char **buf, t_tag *tag)
{
	char	*width;
	int		len;

	len = tag->width - (int)ft_strlen(*buf);
	if (len <= 0)
		return ((int)ft_strlen(*buf));
	if (!(width = (char *)malloc(sizeof(char) * (len + 1))))
		return (-1);
	width[len] = '\0';
	while (len--)
	{
		if (tag->zero == 1)
			width[len] = '0';
		else
			width[len] = ' ';
	}
	if (tag->minus == 1)
		*buf = ft_strjoin(*buf, width, 'B');
	else if (tag->minus == 0)
		*buf = ft_strjoin(width, *buf, 'B');
	if (!*buf)
		return (-2);
	return (tag->width);
}

int			print_string(char *str, t_tag *tag)
{
	int		result;
	int		len;
	char	*buf;

	result = 0;
	if (!str)
		str = "(null)";
	len = (int)ft_strlen(str);
	if ((tag->precision != -1) && (tag->precision < len))
		len = tag->precision;
	if (!(buf = trim_string(str, len)))
		return (ERROR);
	result = add_width_to_buf(&buf, tag);
	if (result == -1)
	{
		free(buf);
		return (ERROR);
	}
	else if (result == -2)
		return (ERROR);
	ft_putstr(buf);
	free(buf);
	return (result);
}
