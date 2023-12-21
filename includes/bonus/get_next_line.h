/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetre <apetre@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 01:28:21 by apetre            #+#    #+#             */
/*   Updated: 2023/09/15 00:17:42 by apetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 69
# endif

char	*join(char *buffer, char *read);
char	*work_buffer(int fd, char *buffer);
char	*getnl(char *buffer);
char	*remove_line(char *buffer);
char	*get_next_line(int fd, int fin);

#endif
