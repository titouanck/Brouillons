/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:04:48 by tchevrie          #+#    #+#             */
/*   Updated: 2022/11/10 15:50:52 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	char	*r;
	int		fd;

	// fd = 0;
	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		return (0);
	r = (void *) 1;
	while (r)
	{
		// r = get_next_line(0);
		// printf("-> %s\n", r);
		// if (r)
		// 	free(r);
		r = get_next_line(fd);
		printf("-> %s\n", r);
		if (r)
			free(r);
	}
}
