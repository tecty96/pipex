/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetre <apetre@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 02:37:03 by apetre            #+#    #+#             */
/*   Updated: 2023/09/15 00:31:34 by apetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

char	*getnl(char *buffer)
{
	size_t	i;
	size_t	len;
	char	*new;

	i = 0;
	len = 0;
	while (buffer[len] != '\n')
		len++;
	if (buffer[len] == '\n')
		len++;
	new = (char *) malloc((len + 1) * sizeof(char));
	while (i < len)
	{
		new[i] = buffer[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*remove_line(char *buffer)
{
	char	*p;
	char	*new;
	int		i;

	i = 0;
	p = ft_strchr(buffer, '\n') + 1;
	new = (char *) malloc((ft_strlen(p) + 1) * sizeof(char));
	while (p[i])
	{
		new[i] = p[i];
		i++;
	}
	new[i] = '\0';
	free(buffer);
	return (new);
}

int	check(char **buffer, int fd, int fin)
{
	if (fin == 1)
	{
		if (buffer[fd])
			free(buffer[fd]);
		buffer[fd] = NULL;
		return (0);
	}
	if (fd == -1 || BUFFER_SIZE <= 0 || fd > 1024)
		return (0);
	return (1);
}

char	*get_next_line(int fd, int fin)
{
	static char	*buffer[1024];
	char		*next;

	if (!check(buffer, fd, fin))
		return (NULL);
	if (!ft_strchr(buffer[fd], '\n'))
		buffer[fd] = work_buffer(fd, buffer[fd]);
	if (ft_strchr(buffer[fd], '\n'))
	{
		next = getnl(buffer[fd]);
		buffer[fd] = remove_line(buffer[fd]);
		return (next);
	}
	else if (buffer[fd] && buffer[fd][0] != '\0')
	{
		next = ft_strdup(buffer[fd]);
		buffer[fd] = NULL;
		return (next);
	}
	else
	{
		free(buffer[fd]);
		return (NULL);
	}
}
