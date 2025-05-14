/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 21:36:21 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/14 14:40:13 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[FD_SIZE][BUFFER_SIZE + 1];
	ssize_t		readed;
	char		*line;
	int			findbl;

	if (BUFFER_SIZE <= 0 || (fd < 0 || fd > FD_SIZE))
		return (NULL);
	line = NULL;
	readed = 0;
	findbl = 0;
	while (!findbl)
	{
		if (!buffer[fd][0])
			readed = read(fd, buffer[fd], BUFFER_SIZE);
		if (!buffer[fd][0] && readed == 0)
			break ;
		if (!buffer[fd][0] && readed == -1)
			return (free(line), NULL);
		line = ft_linejoin(line, buffer[fd]);
		if (!line)
			return (NULL);
		findbl = ft_changebuffer(buffer[fd]);
	}
	return (line);
}
