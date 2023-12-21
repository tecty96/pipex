/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetre <apetre@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 23:56:34 by apetre            #+#    #+#             */
/*   Updated: 2023/09/14 23:18:17 by apetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

static void	extra_error(t_data *data, int i, int exit_end)
{
	int	j;

	j = 0;
	i = 0;
	if (data && data->cmd_args)
	{
		while (data->cmd_args[i])
		{
			while (data->cmd_args[i][j])
				free(data->cmd_args[i][j++]);
			free(data->cmd_args[i++]);
			j = 0;
		}
		free(data->cmd_args);
	}
	if (data && data->pipex)
	{
		if (read(data->pipex[0], NULL, 0) != -1)
			close(data->pipex[0]);
		if (read(data->pipex[1], NULL, 0) != -1)
			close(data->pipex[1]);
		free(data->pipex);
	}
	free(data);
	exit(exit_end);
}

void	error_or_end(t_data *data, char *msg, int exit_end)
{
	int	i;

	i = 0;
	if (!msg && exit_end != 0)
		perror(NULL);
	else if (msg && msg[0] != '1')
		write(2, msg, ft_strlen(msg));
	if (data && data->path_slash)
	{
		while (data->path_slash[i])
			free(data->path_slash[i++]);
		free(data->path_slash);
	}
	i = 0;
	if (data && data->cmd_no_args)
	{
		while (data->cmd_no_args[i])
			free(data->cmd_no_args[i++]);
		free(data->cmd_no_args);
	}
	extra_error(data, 0, exit_end);
}
