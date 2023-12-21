/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetre <apetre@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:47:24 by apetre            #+#    #+#             */
/*   Updated: 2023/09/15 00:34:21 by apetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/pipex_bonus.h"

static void	extra(char *str, int *fd, char *stop)
{
	if (str)
	{
		free(str);
		str = get_next_line(0, 1);
	}
	free(stop);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
}

void	here_doc(t_data *data, char *stop)
{
	char	*str;
	int		fd[2];

	if (pipe(fd) == -1)
		error_or_end(data, NULL, 1);
	while (1)
	{
		write(1, "feed me a line > ", 18);
		str = get_next_line(0, 0);
		if (!str)
		{
			write(1, "\n", 1);
			break ;
		}
		if (ft_strncmp(stop, str, ft_strlen(stop) + 1) == 0)
			break ;
		else
		{
			write(fd[1], str, ft_strlen(str));
			free(str);
		}
	}
	extra(str, fd, stop);
}
