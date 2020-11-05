/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdawnsta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 12:12:08 by zdawnsta          #+#    #+#             */
/*   Updated: 2020/11/04 12:15:20 by zdawnsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/param.h>
# include <sys/errno.h>
# include "../libft/libft.h"

extern char **environ;

typedef struct  s_minishell
{
    /* data */
}               t_minishel;

typedef struct  s_env
{
    char    *home;
    char    *pwd;
    char    **envv; /* environment variables */
    int     size; /* number of environment variables */
}               t_env;


void    envv_init(t_env *env, char **envv);
void    cmd_echo(char **argv);
int		cmd_pwd(void);
int     cmd_cd(t_env *env, char **path);
void    cmd_env(t_env *env);
void    cmd_unset(t_env *env, char **values);


#endif
