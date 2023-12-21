/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path_and_join.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetre <apetre@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:40:57 by apetre            #+#    #+#             */
/*   Updated: 2023/09/12 02:20:38 by apetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

char	**find_path_and_join(t_data *data, char **envp)
{
	int		i;
	char	**path;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (ft_strncmp(envp[i], "PATH=", 5) != 0)
		error_or_end(data, NULL, 1);
	path = ft_split(&envp[i][5], ':');
	i = 0;
	while (path[i])
	{
		path[i] = ft_strjoin_free(path[i], "/");
		i++;
	}
	return (path);
}
