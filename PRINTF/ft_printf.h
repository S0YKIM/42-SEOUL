/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 18:34:39 by sokim             #+#    #+#             */
/*   Updated: 2021/06/09 18:24:32 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define TYPE "csdiupxXo%"
# define ERROR -1

typedef struct		s_tag
{
	int				minus;
	int				zero;
	int				star;
	int				plus;
	int				space;
	int				hashtag;
	int				width;
	int				precision;
	char			type;
	int				nbr_base;
	int				nbr_sign;
}					t_tag;

int					ft_printf(const char *format, ...);

int					print_char(int c, t_tag *tag);
int					print_string(char *str, t_tag *tag);
int					add_width_to_buf(char **buf, t_tag *tag);
int					print_number(unsigned long long nbr, t_tag *tag);

void				init_tag(t_tag *tag);
void				init_width(t_tag *tag);

void				store_star_flag(va_list ap,
		char *format, t_tag *tag, int i);
int					add_space(int buf_len, t_tag *tag, char **buf);
int					add_hashtag_prefix(t_tag *tag, char **buf);
int					add_hashtag_prefix_with_zero(int buf_len, t_tag *tag,
		char **buf);

unsigned long long	abs_nbr(unsigned long long nbr, t_tag *tag);
void				set_nbr_base(t_tag *tag);
int					add_pointer_prefix(t_tag *tag, char **buf);
int					count_len_of_number(unsigned long long nbr, t_tag *tag);
char				convert_number_to_base(unsigned long long nbr, t_tag *tag);

#endif
