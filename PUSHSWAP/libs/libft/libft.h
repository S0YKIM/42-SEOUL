/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:01:44 by sokim             #+#    #+#             */
/*   Updated: 2022/02/21 20:41:06 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

/* Print function */
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

/* String function */
size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlcat(char *dest, const char *src, size_t size);
char		*ft_strdup(const char *s1);

/* Memory manage function */
void		*ft_calloc(size_t count, size_t size);
void		*ft_bzero(void *ptr, size_t num);

/* Change data type */
int			ft_atoi(const char *str);
char		*ft_itoa(int n);
char		*ft_itoa_binary(int num);
long long	ft_atol(const char *str);

/* Split one line into several lines */
char		**ft_split(char const *s, char c);

/* Etc */
int			ft_isdigit(int c);
void		*ft_memset(void *ptr, int value, size_t num);

#endif
