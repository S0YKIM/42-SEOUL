/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 20:19:22 by sokim             #+#    #+#             */
/*   Updated: 2021/07/01 20:09:18 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

/*
 *** Struct ***
*/

typedef struct	s_path
{
	const char	*path[6];
	char *const	*argv;
}				t_path;

/*
 *** Functions ***
*/

void			redirect_stdin(const char *file);
void			redirect_stdout(const char *file);
void			connect_pipe(int pipefd[2], int io);
void			run_command(const char *command);

#endif
