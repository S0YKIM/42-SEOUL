/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 18:17:46 by sokim             #+#    #+#             */
/*   Updated: 2021/06/09 20:27:08 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			add_hashtag_prefix(t_tag *tag, char **buf)
{
	if (tag->type == 'o')
	{
		if (!(*buf = ft_strjoin("0", *buf, 'R')))
			return (ERROR);
		return (1);
	}
	else if (tag->type == 'x')
	{
		if (!(*buf = ft_strjoin("0x", *buf, 'R')))
			return (ERROR);
		return (2);
	}
	else if (tag->type == 'X')
	{
		if (!(*buf = ft_strjoin("0X", *buf, 'R')))
			return (ERROR);
		return (2);
	}
	return (0);
}

static int	add_small_hex(int buf_len, t_tag *tag, char **buf)
{
	if (buf_len >= tag->width)
	{
		if (!(*buf = ft_strjoin("0x", *buf, 'R')))
			return (ERROR);
		return (2);
	}
	else if (buf_len == tag->width - 1)
	{
		(*buf)[0] = 'x';
		if (!(*buf = ft_strjoin("0", *buf, 'R')))
			return (ERROR);
		return (1);
	}
	else if (buf_len < tag->width - 1)
	{
		(*buf)[0] = '0';
		(*buf)[1] = 'x';
	}
	return (0);
}

static int	add_big_hex(int buf_len, t_tag *tag, char **buf)
{
	if (buf_len >= tag->width)
	{
		if (!(*buf = ft_strjoin("0X", *buf, 'R')))
			return (ERROR);
		return (2);
	}
	else if (buf_len == tag->width - 1)
	{
		(*buf)[0] = 'X';
		if (!(*buf = ft_strjoin("0", *buf, 'R')))
			return (ERROR);
		return (1);
	}
	else if (buf_len < tag->width - 1)
	{
		(*buf)[0] = '0';
		(*buf)[1] = 'X';
	}
	return (0);
}

int			add_hashtag_prefix_with_zero(int buf_len, t_tag *tag, char **buf)
{
	int		result;

	result = 0;
	if (tag->type == 'o')
	{
		if (buf_len >= tag->width)
		{
			if (!(*buf = ft_strjoin("0", *buf, 'R')))
				return (ERROR);
			result = 1;
		}
		else
			(*buf)[0] = '0';
	}
	else if (tag->type == 'x')
		result = add_small_hex(buf_len, tag, buf);
	else if (tag->type == 'X')
		result = add_big_hex(buf_len, tag, buf);
	return (result);
}
