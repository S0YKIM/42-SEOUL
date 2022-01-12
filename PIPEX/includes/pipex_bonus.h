/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 20:19:22 by sokim             #+#    #+#             */
/*   Updated: 2021/07/03 14:33:25 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/libft.h"
# include "get_next_line.h"
# include <stdio.h>

/*
 *** Struct ***
*/

typedef struct s_path
{
	const char	*path[6];
	char *const	*argv;
}				t_path;

/*
 *** Functions ***
*/

void			redirect_stdin(const char *file);
void			redirect_stdout(const char *file);
void			redirect_stdout_add(const char *file);
void			connect_pipe(int pipefd[2], int io);
void			run_command(const char *command);

/*
 *** Bonus Functions ***
*/

void			heredoc(const char *limiter);

#endif
