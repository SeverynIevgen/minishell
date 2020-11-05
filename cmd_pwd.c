/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdawnsta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 14:45:00 by zdawnsta          #+#    #+#             */
/*   Updated: 2020/11/05 14:45:06 by zdawnsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

int		cmd_pwd(void)
{
	char	buff[200];

	if (!getcwd(buff, 200))
		return (errno);
	ft_putstr_fd(buff, 1);
    write(1, "\n", 1);
	return (0);
}
