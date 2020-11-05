/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdawnsta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:45:08 by zdawnsta          #+#    #+#             */
/*   Updated: 2020/11/05 15:45:22 by zdawnsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

char    **del_env_var(t_env *env, int i)
{
    int     j;
    int     k;
    char    **new_arr;

    j = 0;
    k = -1;
    new_arr = (char **)malloc(sizeof(char) * env->size);
    while (++k < env->size)
    {
        if(k != i)
        {
            new_arr[j] = ft_strdup(env->envv[k]);
            printf("--- %s ---\n", new_arr[j]);
            //free(env->envv[k]);
            j++;
        }
    }
    k = 0;
    while (++k < env->size)
        free(env->envv[k]);
    free(env->envv);
    new_arr[j] = NULL;
    env->size--;
    return (new_arr);
}

void     check_env_arr(t_env *env, char *value)
{
    int i;

    i = -1;
    while (++i < env->size)
    {
        if(!ft_strncmp(env->envv[i], value, ft_strlen(value)))
        {
            env->envv = del_env_var(env, i);
        }
    }
}

void    cmd_unset(t_env *env, char **values)
{
    int i;

    i = -1;
    while (values[++i])
    {
        check_env_arr(env, values[i]);
    }
    cmd_env(env);
}