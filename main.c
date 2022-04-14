/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/13 15:23:48 by kblok         #+#    #+#                 */
/*   Updated: 2022/04/14 13:50:25 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static bool files(int argc, char **argv, int *f1, int *f2)
{
    *f1 = open(argv[1], O_RDONLY);
    *f2 = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (*f1 < 0 || *f2 < 0)
        return (false);
    dup2(*f1, STDIN_FILENO);
    dup2(*f2, STDOUT_FILENO);
    return (true);
}

int main(int argc, char **argv, char **envp)
{
    t_vars  vars;

    if (argc < 5)
        exit(EXIT_FAILURE);
    if(!files(argc, argv, &vars.f1, &vars.f2))
        return (1);
	vars.path = parser(envp, vars);
	pipex(vars, argc, argv, envp);
    close(vars.f1);
    close(vars.f2);
	exit(EXIT_SUCCESS);
}
