/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 21:39:07 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/13 17:56:25 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	char	*string;
	int		fd;

	fd = open("text", O_RDONLY);
	string = get_next_line(fd);
	printf("Line [1] => %s", string);
	free(string);
	// string = get_next_line(fd);
	// printf("Line [2] => %s", string);
	// free(string);
	// string = get_next_line(fd);
	// printf("Line [3] => %s", string);
	// free(string);
	// string = get_next_line(fd);
	// printf("Line [4	] => %s", string);
	// free(string);
	printf("\n");
}
