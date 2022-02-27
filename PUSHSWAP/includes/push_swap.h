/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 20:22:04 by sokim             #+#    #+#             */
/*   Updated: 2022/02/20 20:22:04 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "deque.h"
# include "push_swap_macro.h"

/* Create deque A(w/numbers) and B(empty) */
void	create_deque_with_arguments(int argc, char **argv, t_push_swap *data);

/* Check validation */
int		check_validate_integer(char **str);
int		check_duplicates(t_deque *deque);
int		check_deque_sorted(t_deque *deque);

/* Change integer into index and change it to binary*/
void	add_index_and_binary(t_deque *deque);

/* Operation (pa, pb, sa, sb, ra, rb, ...) */
int		operator(char *op, t_push_swap *data);

/* Sort functions */
int		sort_three(t_push_swap *data);
void	sort_five(t_push_swap *data);
void	sort_many(t_push_swap *data);

/* Util functions */
int		get_minimum_number(t_deque *deque);
int		get_maximum_number(t_deque *deque);

/* Print deque */
void	print_deque_ab(t_deque *a, t_deque *b);

/* Error handling */
void	exit_with_error_message(char *msg);
void	exit_with_memory_free(char *msg, t_deque *a, t_deque *b, char **str);

/* Memory Free */
void	free_double_char(char **str);
void	free_all(t_push_swap *data);

#endif