/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_parent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetre <apetre@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 02:17:03 by apetre            #+#    #+#             */
/*   Updated: 2023/09/14 23:51:45 by apetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

void	parent(t_data *data, int pid, int ac)
{
	int	i;

	i = data->i;
	waitpid(pid, NULL, 0);
	if (i == ac - 4)
		error_or_end(data, NULL, 0);
	close(data->pipex[1]);
	dup2(data->pipex[0], STDIN_FILENO);
	close(data->pipex[0]); // Added after!
}

void	last_cmd(char **av, int ac)
{
	int	output_fd;

	if (ft_strncmp(av[1], "here_doc", 9) == 0)
		output_fd = open(av[ac - 1], O_CREAT | O_RDWR | O_APPEND, 0644);
	else
		output_fd = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	dup2(output_fd, STDOUT_FILENO);
	close(output_fd);
}

void	child_attack(t_data *data, char **envp, char **av, int ac)
{
	int		i;
	char	*exists;
	int		acx;

	i = data->i;
	acx = ac - 4;
	if (ft_strncmp(av[1], "here_doc", 9) == 0)
		acx = ac - 5;
	close(data->pipex[0]);
	if (i == acx)
		last_cmd(av, ac);
	else
		dup2(data->pipex[1], STDOUT_FILENO);
	exists = access_check(data, (data->cmd_no_args)[i]);
	if (!exists)
	{
		write(2, "Command not found : ", 20);
		write(2, data->cmd_no_args[i], ft_strlen(data->cmd_no_args[i]));
		write(2, "\n", 1);
		error_or_end(data, "1", 1);
	}
	execve(exists, data->cmd_args[i], envp);
	exit(126);
}
