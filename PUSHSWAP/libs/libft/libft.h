/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:01:44 by sokim             #+#    #+#             */
/*   Updated: 2022/02/21 01:37:06 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

size_t				ft_strlen(const char *s);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putstr_fd(char *s, int fd);
void				*ft_calloc(size_t count, size_t size);
void				*ft_bzero(void *ptr, size_t num);
int					ft_isdigit(int c);
long long			ft_atol(const char *str);
void				*ft_memset(void *ptr, int value, size_t num);

#endif
