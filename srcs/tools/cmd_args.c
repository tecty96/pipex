/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetre <apetre@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:54:39 by apetre            #+#    #+#             */
/*   Updated: 2023/09/14 19:28:08 by apetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

char	***cmd_args(t_data *data, char **av, int ac)
{
	int		i;
	int		cmd_start;
	char	***cmd_args;
	int		acx;

	i = 0;
	acx = ac - 3;
	cmd_start = 2;
	if (ft_strncmp(av[1], "here_doc", 9) == 0)
	{
		acx = ac -5;
		cmd_start = 3;
	}
	cmd_args = (char ***) malloc((ac - 3 + 1) * sizeof(char **));
	if (!cmd_args)
		error_or_end(data, NULL, 1);
	while (i < acx)
	{
		cmd_args[i] = ft_split(av[cmd_start], ' ');
		i++;
		cmd_start++;
	}
	cmd_args[i] = NULL;
	return (cmd_args);
}
