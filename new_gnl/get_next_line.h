/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:30:31 by tchevrie          #+#    #+#             */
/*   Updated: 2022/11/11 15:52:42 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100000
# endif

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_bufferList
{
	char				*content;
	struct s_bufferList	*next;	
}						t_bufferList;

typedef struct s_fdList
{
	int					fd;
	t_bufferList		*begin;
	struct s_fdList		*next_fd;	
}					t_fdList;

/* get_next_line_c */
char			*get_next_line(int fd);

/* get_next_line_utils.c */
t_bufferList	*ftlst_new_buffer(void);
t_fdList		*ftlst_new_fd(int fd);
int				end_of_line(char *content);
size_t			count_memory(t_bufferList *current);
t_fdList		*clean_fd_list(t_fdList *fd_list, t_fdList *current);

#endif