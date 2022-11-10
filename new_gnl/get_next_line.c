/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:30:09 by tchevrie          #+#    #+#             */
/*   Updated: 2022/11/10 15:54:18 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_fdList	*find_fdbegin(int fd)
{
	static t_fdList		*fd_list;
	t_fdList			*current_fd;

	if (!fd_list)
		fd_list = ftlst_new_fd(0);
	if (!fd_list)
		return (NULL);
	current_fd = fd_list;
	while (current_fd->next_fd && current_fd->fd != fd)
		current_fd = current_fd->next_fd;
	if (current_fd->fd != fd)
	{
		current_fd->next_fd = ftlst_new_fd(fd);
		current_fd = current_fd->next_fd;
	}
	return (current_fd);
}

static int	read_file(int fd, t_bufferList *current, t_bufferList *begin)
{
	if (!begin)
		return (0);
	while (read(fd, current->content, BUFFER_SIZE))
	{
		if (end_of_line(current->content))
			break ;
		current->next = ftlst_new_buffer();
		current = current->next;
	}
	if (!(begin->content[0]))
		return (0);
	return (1);
}

static char	*join_buffers(t_bufferList *begin, t_bufferList *current)
{
	size_t			buffers;
	char			*line;
	size_t			i;
	size_t			j;

	buffers = 1;
	while (current->next)
	{
		current = current->next;
		buffers++;
	}
	line = ft_calloc(buffers, BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	i = 0;
	current = begin;
	while (current && current->content)
	{
		j = 0;
		while ((current->content)[j] && (i == 0 || line[i - 1] != '\n'))
			line[i++] = (current->content)[j++];
		current = current->next;
	}
	line[i] = '\0';
	printf("buffers * (BUFFER_SIZE + 1) : %lu, i = %lu | [%s]\n", buffers * (BUFFER_SIZE + 1), i, line);
	return (line);
}

// static void	clean_buffers(t_bufferList *begin, t_bufferList *current)
// {
// 	size_t			i;
// 	size_t			j;
// 	t_bufferList	*next;

// 	while (current && current->next && current->next->content[0])
// 		current = current->next;
// 	i = 0;
// 	while ((current->content)[i])
// 		if ((current->content)[i++] == '\n')
// 			break ;
// 	j = 0;
// 	while ((current->content)[i])
// 		(begin->content)[j++] = (current->content)[i++];
// 	(begin->content)[j] = '\0';
// 	next = begin->next;
// 	begin->next = 0;
// 	begin = next;
// 	while (begin)
// 	{
// 		next = begin->next;
// 		free(begin->content);
// 		free(begin);
// 		begin = next;
// 	}
// }

static void	clean_buffers(t_bufferList *current, t_fdList *current_fd)
{
	size_t			i;
	size_t			j;
	t_bufferList	*next;

	while (current->next)
	{
		next = current->next;
		free(current->content);
		free(current);
		current = next;
		current_fd->begin = next;
	}
	i = 0;
	while ((current->content)[i])
	{
		i++;
		if ((current->content)[i - 1] == '\n')
			break ;
	}
	j = 0;
	while ((current->content)[i])
		(current->content)[j++] = (current->content)[i++];
	(current->content)[j] = '\0';
}


char	*get_next_line(int fd)
{
	t_fdList			*current_fd;
	t_bufferList		*begin;
	t_bufferList		*current;
	char				*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	current_fd = find_fdbegin(fd);
	if (!current_fd)
		return (NULL);
	begin = current_fd->begin;
	current = begin;
	if (begin && (begin->content[0]))
	{
		begin->next = ftlst_new_buffer();
		current = begin->next;
	}
	if (!(read_file(fd, current, begin)))
		return (NULL);
	line = join_buffers(begin, current);
	clean_buffers(begin, current_fd);
	return (line);
}
