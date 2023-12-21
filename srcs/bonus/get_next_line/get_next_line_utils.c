/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetre <apetre@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 02:37:22 by apetre            #+#    #+#             */
/*   Updated: 2023/09/14 23:35:04 by apetre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

char	*join(char *buffer, char *read)
{
	char	*new;
	size_t	len;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	len = ft_strlen(buffer);
	new = (char *) malloc((len + ft_strlen(read) + 1) * sizeof(char));
	while (i < len && len > 0)
	{
		new[i] = buffer[i];
		i++;
	}
	len = ft_strlen(read);
	while (j < len)
	{
		new[i] = read[j];
		i++;
		j++;
	}
	new[i] = '\0';
	free(buffer);
	return (new);
}

char	*work_buffer(int fd, char *buffer)
{
	char	*temp_read;
	int		read_size;

	temp_read = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp_read)
		return (NULL);
	read_size = 1;
	while (!ft_strchr(buffer, '\n'))
	{
		read_size = read(fd, temp_read, BUFFER_SIZE);
		if (read_size < 1)
		{
			free(temp_read);
			if (buffer)
				return (buffer);
			else
				return (NULL);
		}
		temp_read[read_size] = '\0';
		buffer = join(buffer, temp_read);
	}
	free(temp_read);
	return (buffer);
}
