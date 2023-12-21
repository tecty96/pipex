/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetre <apetre@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:46:27 by apetre            #+#    #+#             */
/*   Updated: 2023/09/14 22:50:16 by apetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/pipex_bonus.h"

/*
	t_data data :
		- path_slash = char * = the path with '/' joined to it
		- cmd_no_args = char ** = each string = name of the cmd
		- cmd_args = char *** = each **'s frist string
								contains the name of the cmd and 
								it's arguments
		NOTE FOR CMD_ARGS = EXECVE IGNORES FRIST STRING IN A char **
		FOR IT'S ARGS FIELD.
*/

static void	init_data(t_data *data, char **envp, char **av, int ac)
{
	data->path_slash = find_path_and_join(data, envp);
	data->cmd_no_args = cmd_no_args(data, av, ac);
	data->cmd_args = cmd_args(data, av, ac);
	data->pipex = (int *) malloc(8);
}

static void	initial_check(char **envp, int ac)
{
	if (!*envp)
		error_or_end(NULL, "Haha, you've tried this with me :P\n", 1);
	if (ac < 5)
		error_or_end(NULL, "Not enough arguments, check yo self :)!\n", 1);
}

static void	define_infile(t_data *data, char **av)
{
	int	file_fd;

	if (ft_strncmp(av[1], "here_doc", 9) == 0)
	{
		here_doc(data, ft_strjoin(av[2], "\n"));
		return ;
	}
	file_fd = open(av[1], O_RDONLY);
	if (pipe(data->pipex) == -1)
		error_or_end(data, NULL, 1);
	dup2(file_fd, STDIN_FILENO);
	close(file_fd);
}

static void	loop(t_data *data, char **envp, char **av, int ac)
{
	int	pid;

	if (pipe(data->pipex) == -1)
		error_or_end(data, NULL, 1);
	pid = fork();
	if (pid == -1)
		error_or_end(data, NULL, 1);
	if (pid == 0)
		child_attack(data, envp, av, ac);
	else
		parent(data, pid, ac);
	data->i++;
}

int	main(int ac, char **av, char **envp)
{
	t_data	*data;
	int		acx;

	acx = ac - 3;
	data = (t_data *) malloc(sizeof(t_data));
	data->i = 0;
	initial_check(envp, ac);
	if (ft_strncmp(av[1], "here_doc", 9) == 0)
	{
		init_data(data, envp, av + 1, ac);
		acx = ac - 4;
	}
	else
		init_data(data, envp, av, ac);
	define_infile(data, av);
	while (data->i < acx)
		loop(data, envp, av, ac);
	error_or_end(data, "1", 0);
}
