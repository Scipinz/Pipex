/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/23 18:39:58 by kblok         #+#    #+#                 */
/*   Updated: 2022/03/24 15:55:55 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include "libft/libft.h"

typedef struct s_vars
{
    int     status;
    int     i;
    int     f1;
    int     f2;
    char    *cmd;
    char    *envp_path;
    char    **paths;
    char    **cmdargs;
    int     end[2];
    int     status;
    pid_t   parent;
    pid_t   child1;
    pid_t   child2;
} t_vars;

#endif