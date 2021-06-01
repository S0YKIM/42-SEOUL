/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 18:44:57 by sokim             #+#    #+#             */
/*   Updated: 2021/06/01 21:57:22 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_var_args(va_list ap, t_info *info)
{
	int		result;
	char	type;

	result = 0;
	type = info->type;
	if (type == 'c')
		result = print_char(va_arg(ap, int), info);
	else if (type == 's')
		result = print_string(va_arg(ap, char *), info);
	else if (type == 'p')
		result = print_nbr(va_arg(ap, unsigned long long), info);
	else if (type == 'd' || type == 'i')
		result = print_nbr(va_arg(ap, int), info);
	else if (type == 'u' || type == 'x' || type == 'X')
		result = print_nbr(va_arg(ap, unsigned int), info);
	else if (type == '%')
		result = print_char('%', info);
	return (result);
}

static void	store_width_and_prec(va_list ap, char *format, t_info *info, int i)
{
	if (ft_isdigit(format[i]))
	{
		if (info->prec == -1)
			info->width = info->width * 10 + format[i] - '0';
		else
			info->prec = info->prec * 10 + format[i] - '0';
	}
	else if (format[i] == '*')
	{
		if (info->prec == -1)
		{
			info->width = va_arg(ap, int);
			if (info->width < 0)
			{
				info->minus = 1;
				info->width *= -1;
			}
		}
		else
			info->prec = va_arg(ap, int);
	}
}

static void	store_flags(va_list ap, char *format, t_info *info, int i)
{
	if (format[i] == '0' && info->width == 0 && info->prec == -1)
		info->zero = 1;
		// 0 으로 채운다
	if (format[i] == '-')
		info->minus = 1;
		// 좌측정렬
	if (format[i] == '.')
		info->prec = 0;
		// 다음 숫자가 있으면그게 precision
	if (ft_isdigit(format[i]) || format[i] == '*')
		store_width_and_prec(ap, format, info, i);
		// . 뒤에오면 prec . 없으면 width 
		// * 의 경우 첫번째 가변인자가 width
}

static int	print_and_parse_flags(va_list ap, char *format)
{
	int			i;
	int			result;
	t_info		*info;

	i = 0;
	result = 0;
	if (!(info = (t_info *)malloc(size_of(t_info))))
		return (-1);
	while (format[i])
	{
		while (format[i] && format[i] != '%')
			result += ft_putchar(format[i++]);
		if (format[i] == '%')
		{
			init_info(info);
			while (format[++i] && !(ft_strchr(TYPE, format[i])))
				store_flags(ap, format, info, i);
			info->type = format[i++];
			if (((info->minus == 1) || (info->prec > -1)) && (info->type != '%'))
				info->zero = 0;
			result += print_var_args(ap, info);
		}
	}
	free(info);
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
