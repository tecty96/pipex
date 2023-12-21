/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetre <apetre@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 19:06:19 by apetre            #+#    #+#             */
/*   Updated: 2023/09/12 02:20:12 by apetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

char	*access_check(t_data *data, char *cmd)
{
	char	*join_temp;
	int		i;

	join_temp = NULL;
	i = 0;
	while (data->path_slash[i])
	{
		join_temp = ft_strjoin(data->path_slash[i], cmd);
		if (access(join_temp, X_OK) == 0)
			break ;
		else
		{
			free(join_temp);
			join_temp = NULL;
			i++;
		}
	}
	return (join_temp);
}
