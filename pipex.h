/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/23 18:39:58 by kblok         #+#    #+#                 */
/*   Updated: 2022/04/21 15:10:13 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_vars
{
	int		f1;
	int		f2;
	int		i;
	char	**path;
	char	**cmd;
	int		end[2];
	pid_t	child_process;
}	t_vars;

int		main(int argc, char **argv, char **envp);
void	pipex(t_vars vars, int argc, char **argv, char **envp);
char	**parser(char **envp, t_vars vars);

#endif