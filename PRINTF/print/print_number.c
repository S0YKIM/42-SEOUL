/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 20:53:32 by sokim             #+#    #+#             */
/*   Updated: 2021/06/12 15:53:40 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_buf_len(t_tag *tag, int nbr_len)
{
	int		buf_len;

	if (tag->precision > nbr_len)
		buf_len = tag->precision;
	else
		buf_len = nbr_len;
	return (buf_len);
}

static int	add_plus_or_minus(t_tag *tag, char **buf)
{
	if (tag->nbr_sign == -1)
	{
		if (!(*buf = ft_strjoin("-", *buf, 'R')))
			return (ERROR);
		return (1);
	}
	else if ((tag->nbr_sign == 1) && (tag->plus == 1))
	{
		if (!(*buf = ft_strjoin("+", *buf, 'R')))
			return (ERROR);
		return (1);
	}
	else if ((tag->nbr_sign == 1) && (tag->space == 1))
	{
		if (!(*buf = ft_strjoin(" ", *buf, 'R')))
			return (ERROR);
		return (1);
	}
	return (0);
}

static int	add_plus_or_minus_with_zero(int nbr_len, t_tag *tag, char **buf)
{
	if (tag->nbr_sign == -1)
	{
		if (nbr_len >= tag->width)
		{
			if (!(*buf = ft_strjoin("-", *buf, 'R')))
				return (ERROR);
			return (1);
		}
		else
			(*buf)[0] = '-';
	}
	else if ((tag->nbr_sign == 1) && (tag->plus == 1))
	{
		if (nbr_len >= tag->width)
		{
			if (!(*buf = ft_strjoin("+", *buf, 'R')))
				return (ERROR);
			return (1);
		}
		else
			(*buf)[0] = '+';
	}
	else if ((tag->nbr_sign == 1) && (tag->space == 1))
		return (add_space(nbr_len, tag, buf));
	return (0);
}

static int	add_prec_to_nbr(unsigned long long nbr, t_tag *tag, char **buf)
{
	int		nbr_len;
	int		buf_len;
	int		i;

	nbr_len = count_len_of_number(nbr, tag);
	buf_len = get_buf_len(tag, nbr_len);
	if (!(*buf = (char *)malloc(sizeof(char) * (buf_len + 1))))
		return (ERROR);
	i = 0;
	(*buf)[buf_len] = '\0';
	while (nbr_len + i < buf_len)
		(*buf)[i++] = '0';
	if (!nbr && tag->precision && buf_len)
		(*buf)[buf_len - 1] = '0';
	i = 1;
	while (nbr)
	{
		(*buf)[buf_len - i] = convert_number_to_base(nbr, tag);
		nbr /= tag->nbr_base;
		++i;
	}
	return (nbr_len);
}

int			print_number(unsigned long long nbr, t_tag *tag)
{
	char	*buf;
	int		nbr_len;
	int		result;

	set_nbr_base(tag);
	nbr = abs_nbr(nbr, tag);
	nbr_len = add_prec_to_nbr(nbr, tag, &buf);
	if ((buf) && (tag->type == 'd' || tag->type == 'i') && (tag->zero == 0))
		nbr_len += add_plus_or_minus(tag, &buf);
	if ((buf) && (tag->hashtag == 1) && (tag->zero == 0) && (nbr))
		nbr_len += add_hashtag_prefix(tag, &buf);
	if (buf)
		nbr_len += add_pointer_prefix(tag, &buf);
	if (buf)
		result = add_width_to_buf(&buf, tag);
	if ((buf) && (tag->type == 'd' || tag->type == 'i') && (tag->zero == 1))
		result += add_plus_or_minus_with_zero(nbr_len, tag, &buf);
	if ((buf) && (tag->hashtag == 1) && (tag->zero == 1) && (nbr))
		result += add_hashtag_prefix_with_zero(nbr_len, tag, &buf);
	if (!buf)
		return (ERROR);
	ft_putstr(buf);
	free(buf);
	return (result);
}
