/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 21:39:07 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/14 10:35:41 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	char	*string;
	int		fd;
	int		i;

	string = NULL;
	fd = open("text", O_RDONLY);
	i = 1;
	while (i)
	{
		string = get_next_line(fd);
		if (string)
		{
			printf("Line [%d] => %s", i, string);
			free(string);
			i++;
		}
		else
			i = 0;
	}
	printf("\n");
}
