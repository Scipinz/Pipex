/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/13 15:22:32 by kblok         #+#    #+#                 */
/*   Updated: 2022/10/19 16:25:18 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**path(char **envp, t_vars vars)
{
	char	*temp_path;
	int		i;

	i = 0;
	vars.i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[vars.i], "PATH=", ft_strlen(envp[vars.i])))
			break ;
		vars.i++;
		i++;
	}
	if (!envp[i])
		exit(EXIT_FAILURE);
	temp_path = ft_substr(envp[vars.i], 5, ft_strlen(envp[vars.i]));
	return (ft_split(temp_path, ':'));
}

char	**parser(char **envp, t_vars vars)
{
	vars.i = 0;
	vars.path = path(envp, vars);
	if (!vars.path)
		exit(EXIT_FAILURE);
	while (vars.path[vars.i])
	{
		vars.path[vars.i] = ft_strappend(vars.path[vars.i], "/");
		vars.i++;
	}
	return (vars.path);
}
