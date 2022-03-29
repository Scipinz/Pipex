/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/23 18:19:22 by kblok         #+#    #+#                 */
/*   Updated: 2022/03/24 16:25:02 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void    middle_child(t_vars vars, char argv[], char envp[])
{
    vars.i = -1;
    while (vars.paths[++vars.i])
    {
        vars.cmd = ft_strjoin(vars.paths[vars.i], argv[2]);
        execve(vars.cmd, vars.cmdargs, envp);
        //perror("Error"); //use for debugging.
        free(vars.cmd);
    }
    dup2(f1, STDIN_FILENO);
    dup2(vars.end[1], STDOUT_FILENO);
    close(vars.end[0]);
    close(f1);
    exit(EXIT_FAILURE);
}

static void    first_child(t_vars vars, char argv[], char envp[])
{
    vars.i = -1;
    while (vars.paths[++vars.i])
    {
        vars.cmd = ft_strjoin(vars.paths[vars.i], argv[2]);
        execve(vars.cmd, vars.cmdargs, envp);
        //perror("Error"); //use for debugging.
        free(vars.cmd);
    }
    dup2(f1, STDIN_FILENO);
    dup2(vars.end[1], STDOUT_FILENO);
    close(vars.end[0]);
    close(f1);
    exit(EXIT_FAILURE);
}

static void    parent(t_vars vars, char argv[], char envp[])
{
    vars.envp_path = ft_substr(envp, ....);
    vars.paths = ft_split(vars.envp_path, ":");
    vars.cmdargs = ft_split(argv[2], " ");
    waitpid(-1, &vars.status, 0);
    dup2(f2, ...);
    dup2(vars.end[0], ...);
    close(vars.end[1]);
    close(f2);
    exit(EXIT_FAILURE);
}

static void    pipex(t_vars vars, char *cmd1, char *cmd2~)
{
    t_vars  vars;

    pipe(vars.end);
    vars.child1 = fork();
    if (vars.child1 < 0)
        return (perror("Fork: "));
    vars.child2 = fork();
    if (vars.child2 < 0)
        return (perror("Fork: "));
    if (!parent) // if no parent then run child process
        child_process(f1, cmd1);
    else
        parent_process(f2, cmd2);
}

int main(int argc, char **argv, char **envp)
{
    t_vars  vars;

    vars.f1 = open(argv[1], O_RDONLY);
    vars.f1 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
    if (vars.f1 < 0 || vars.f2 < 0)
        return(-1);
    pipex(vars.f1, vars.f2, argv, envp);
    return(0);
}