/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetre <apetre@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 13:24:39 by apetre            #+#    #+#             */
/*   Updated: 2023/09/15 00:17:55 by apetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft.h"
# include "get_next_line.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>

typedef struct s_data
{
	char	**path_slash;
	char	**cmd_no_args;
	char	***cmd_args;
	int		*pipex;
	int		i;
}			t_data;

char	**find_path_and_join(t_data *data, char **envp);
char	**cmd_no_args(t_data *data, char **av, int cmd_nb);
char	***cmd_args(t_data *data, char **av, int ac);
char	*access_check(t_data *data, char *cmd);
void	do_it_all_baby(t_data *data, char **envp, int cmd_nb, char **av);
void	child_attack(t_data *data, char **envp, char **av, int ac);
void	parent(t_data *data, int pid, int ac);
void	free_dp(char **str);
void	error_or_end(t_data *data, char *msg, int exit_end);
char	*ft_strjoin_free(char *s1, char *s2);
char	*get_next_line(int fd, int fin);
void	here_doc(t_data *data, char *stop);

#endif
