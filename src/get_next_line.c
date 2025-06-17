/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 21:36:21 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/17 10:14:13 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer[FD_SIZE];
	ssize_t		readed;
	char		*line;
	int			findbl;
	int			i;

	if (!buffer[fd - 3])
	{
		buffer[fd - 3] = malloc(BUFFER_SIZE + 1);
		if (!buffer[fd - 3])
			return (NULL);
		i = 0;
		while (i <= BUFFER_SIZE + 1)
			buffer[fd - 3][i++] = '\0';
	}
	if (BUFFER_SIZE <= 0 || (fd < 0 || fd > FD_SIZE))
		return (NULL);
	line = NULL;
	readed = 0;
	findbl = 0;
	while (!findbl)
	{
		if (!buffer[fd - 3][0])
			readed = read(fd, buffer[fd - 3], BUFFER_SIZE);
		if (!buffer[fd - 3][0] && readed == 0)
			break ;
		if (!buffer[fd - 3][0] && readed == -1)
			return (ft_clear(line));
		line = ft_linejoin(line, buffer[fd - 3]);
		if (!line)
			return (NULL);
		findbl = ft_changebuffer(buffer[fd - 3]);
	}
	if (!buffer[fd - 3][0])
		free(buffer[fd - 3]);
	return (line);
}
