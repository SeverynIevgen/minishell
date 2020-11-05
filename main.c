/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdawnsta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 12:15:36 by zdawnsta          #+#    #+#             */
/*   Updated: 2020/11/04 12:31:26 by zdawnsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

int		main(int argc, char **argv, char **envv)
{
	t_env	env;
	
	//int i = 0;
	if (argc < 1 && argv[0])
		return (-1);
	envv_init(&env, envv); /* initialization of environment variables */
	//printf("Ret = %d", cmd_cd(&env, argv));
	printf("OK!\n");
	cmd_env(&env);
	printf("\n\n");
	cmd_unset(&env, ++argv);
	// write (1, "\n", 1);

	// int i = 0;
    // while (environ[i] != NULL)
	// {
    //     printf("%s\n", environ[i]);
    //     i++;
    // }
	return (0);
}
