/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdawnsta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 14:44:08 by zdawnsta          #+#    #+#             */
/*   Updated: 2020/11/05 14:44:18 by zdawnsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

int cmd_cd(t_env *env, char **path)
{
	char	*str;
	char	buff[200];

	str = NULL;
	if (!getcwd(buff, 200))
		return (errno);
	if (ft_strncmp(*path, "~", 1))
	 	str = ft_strdup(env->home);
	if (env->home)
		printf("<home> = %s\n", str);
	if (ft_strncmp(path[1], ".", 1))
	 	str = ft_strdup(env->pwd);
	if (env->pwd)
		printf("<pwd> = %s\n", str);
	chdir(path[1]);
	if (!getcwd(buff, 200))
		return (errno);
	printf("path = %s\n", buff);
	return (0);
}
