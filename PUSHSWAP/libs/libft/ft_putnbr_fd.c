/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 15:23:41 by sokim             #+#    #+#             */
/*   Updated: 2021/12/16 16:50:56 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_print_number(int n, int fd)
{
	long long int	nbr;
	char			c;

	nbr = (long long int)n;
	if (nbr < 0)
		nbr *= -1;
	if (nbr >= 10)
		ft_print_number(nbr / 10, fd);
	c = nbr % 10 + '0';
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
		return ;
	if (n < 0)
		write(fd, "-", 1);
	ft_print_number(n, fd);
}
