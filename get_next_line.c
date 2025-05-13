/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 21:36:21 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/13 18:01:52 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	ssize_t		readed;
	char		*line;
	int			bk;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	line = NULL;
	readed = 0;
	bk = 0;
	while (!bk)
	{
		if (!buffer[0])
			readed = read(fd, buffer, BUFFER_SIZE);
		if (!buffer[0] && readed == 0)
			break ;
		if (!buffer[0] && readed == -1)
			return (free(line), NULL);
		line = (ft_linejoin(line, buffer));
		if (!line)
			return (NULL);
		bk = ft_changebuffer(buffer);
	}
	return (line);
}
