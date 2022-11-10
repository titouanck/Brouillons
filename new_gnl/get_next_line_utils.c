/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:30:06 by tchevrie          #+#    #+#             */
/*   Updated: 2022/11/10 09:39:30 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*new;
	size_t	i;

	if (nmemb && size && nmemb > (size_t) -1 / size)
		return (NULL);
	new = (void *) malloc(nmemb * size);
	if (!new)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		*(unsigned char *)(new + i) = '\0';
		i++;
	}
	return (new);
}

t_bufferList	*ftlst_new_buffer(void)
{
	t_bufferList	*new;

	new = ft_calloc(sizeof(t_bufferList), 1);
	if (!new)
		return (NULL);
	new->content = calloc(BUFFER_SIZE + 1, 1);
	if (!(new->content))
	{
		free(new);
		return (NULL);
	}
	new->next = 0;
	return (new);
}

t_fdList	*ftlst_new_fd(int fd)
{
	t_fdList	*new;

	new = ft_calloc(sizeof(t_fdList), 1);
	if (!new)
		return (NULL);
	new->fd = fd;
	new->begin = ftlst_new_buffer();
	if (!(new->begin))
	{
		free(new);
		return (NULL);
	}
	new->next_fd = 0;
	return (new);
}

int	end_of_line(char *content)
{
	size_t	i;

	i = 0;
	while (content[i])
	{
		if (content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
