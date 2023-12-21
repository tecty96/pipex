/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_no_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetre <apetre@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:29:40 by apetre            #+#    #+#             */
/*   Updated: 2023/09/14 21:00:42 by apetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

static char	**loop(t_data *data, char **av, int cmd_start, int acx)
{
	int		i;
	char	**tmp;
	char	**cmd_no_args;

	i = 0;
	cmd_no_args = (char **) malloc((acx + 1) * sizeof(char *));
	if (!cmd_no_args)
		error_or_end(data, NULL, 1);
	while (i < acx)
	{
		if (ft_strchr(av[cmd_start], ' '))
		{
			tmp = ft_split(av[cmd_start], ' ');
			cmd_no_args[i] = ft_strdup(tmp[0]);
			free_dp(tmp);
			tmp = NULL;
		}
		else
			cmd_no_args[i] = ft_strdup(av[cmd_start]);
		i++;
		cmd_start++;
	}
	cmd_no_args[i] = NULL;
	return (cmd_no_args);
}

char	**cmd_no_args(t_data *data, char **av, int ac)
{
	int		cmd_start;
	int		acx;

	acx = ac - 3;
	cmd_start = 2;
	if (ft_strncmp(av[1], "here_doc", 9) == 0)
	{
		acx = ac -5;
		cmd_start = 3;
	}
	return (loop(data, av, cmd_start, acx));
}
