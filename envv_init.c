/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envv_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdawnsta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 14:45:35 by zdawnsta          #+#    #+#             */
/*   Updated: 2020/11/05 14:45:42 by zdawnsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

void    envv_init(t_env *env, char **envv)
{
    int i;

    i = -1;
    env->home = NULL;
    env->pwd = NULL;
    while (envv[++i])
    {
        if (!ft_strncmp(envv[i], "HOME=", 5))
            env->home = ft_strdup(envv[i] + 5);
        if (!ft_strncmp(envv[i], "PWD=", 4))
            env->pwd = ft_strdup(envv[i] + 4);
    }
    env->size = i;
    env->envv = (char **)malloc(sizeof(char *) * (env->size + 1));
    i = -1;
    while (++i < env->size)
        env->envv[i] = ft_strdup(envv[i]);
    env->envv[i] = NULL;
}
