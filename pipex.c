/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/23 18:19:22 by kblok         #+#    #+#                 */
/*   Updated: 2022/04/21 14:57:27 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child(t_vars vars, int argc, char *argv, char **envp)
{
	char	**cmd;

	vars.i = 0;
	cmd = ft_split(argv, ' ');
	while (vars.path[vars.i])
	{
		if (access(ft_strjoin(vars.path[vars.i], cmd[0]), X_OK) == 0)
			execve(ft_strjoin(vars.path[vars.i], cmd[0]), cmd, envp);
		vars.i++;
	}
	exit(127);
}

void	pipex(t_vars vars, int argc, char **argv, char **envp)
{
	vars.i = 2;
	while (vars.i <= argc - 3)
	{
		if (pipe(vars.end) < 0)
			exit(EXIT_FAILURE);
		vars.child_process = fork();
		if (vars.child_process < 0)
			exit(EXIT_FAILURE);
		if (vars.child_process == 0)
		{
			dup2(vars.end[1], STDOUT_FILENO);
			close(vars.end[0]);
			child(vars, argc, argv[vars.i], envp);
		}
		else
		{
			dup2(vars.end[0], STDIN_FILENO);
			close(vars.end[1]);
		}
		vars.i++;
	}
	child(vars, argc, argv[vars.i], envp);
}
