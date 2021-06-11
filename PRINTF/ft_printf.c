/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 18:44:57 by sokim             #+#    #+#             */
/*   Updated: 2021/06/09 17:34:42 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_var_args(va_list ap, t_tag *tag)
{
	int		result;
	char	type;

	if ((tag->minus == 1) || ((tag->precision > -1) &&
				(tag->type != 'c') && (tag->type != 's') && (tag->type != '%')))
		tag->zero = 0;
	result = 0;
	type = tag->type;
	if (type == 'c')
		result = print_char(va_arg(ap, int), tag);
	else if (type == 's')
		result = print_string(va_arg(ap, char *), tag);
	else if (type == 'p')
		result = print_number(va_arg(ap, unsigned long long), tag);
	else if (type == 'd' || type == 'i')
		result = print_number(va_arg(ap, int), tag);
	else if (type == 'u' || type == 'x' || type == 'X' || type == 'o')
		result = print_number(va_arg(ap, unsigned int), tag);
	else if (type == '%')
		result = print_char('%', tag);
	return (result);
}

static void	store_width_and_prec(va_list ap, char *format, t_tag *tag, int i)
{
	if (ft_isdigit(format[i]))
	{
		if (tag->precision == -1)
		{
			init_width(tag);
			tag->width = tag->width * 10 + format[i] - '0';
		}
		else
			tag->precision = tag->precision * 10 + format[i] - '0';
	}
	else if (format[i] == '*')
	{
		tag->star = 1;
		store_star_flag(ap, format, tag, i);
	}
}

static void	store_flags(va_list ap, char *format, t_tag *tag, int i)
{
	if (format[i] == '0' && tag->width == 0 && tag->precision == -1)
		tag->zero = 1;
	if (format[i] == '-')
		tag->minus = 1;
	if (format[i] == '.')
		tag->precision = 0;
	if (format[i] == '+')
		tag->plus = 1;
	if (format[i] == ' ')
		tag->space = 1;
	if (format[i] == '#')
		tag->hashtag = 1;
	if (ft_isdigit(format[i]) || format[i] == '*')
		store_width_and_prec(ap, format, tag, i);
}

static int	print_and_parse_flags(va_list ap, char *format)
{
	int			i;
	int			result;
	t_tag		*tag;

	i = 0;
	result = 0;
	if (!(tag = (t_tag *)malloc(sizeof(t_tag))))
		return (ERROR);
	while (format[i])
	{
		while (format[i] && format[i] != '%')
			result += ft_putchar(format[i++]);
		if (format[i] == '%')
		{
			init_tag(tag);
			while (format[++i] && !(ft_strchr(TYPE, format[i])))
				store_flags(ap, format, tag, i);
			if (format[i])
				tag->type = format[i++];
			result += print_var_args(ap, tag);
		}
	}
	free(tag);
	return (result);
}

int			ft_printf(const char *format, ...)
{
	int			result;
	va_list		ap;

	va_start(ap, format);
	result = print_and_parse_flags(ap, (char *)format);
	va_end(ap);
	return (result);
}
