/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:20:49 by tchevrie          #+#    #+#             */
/*   Updated: 2022/11/10 14:01:12 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>

#include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>
	#include <stdio.h>
typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

/* get_next_line_utils.c */
size_t	ft_strlen(char *str);
t_list	*ft_lstnew(void);
int		ft_lstsize(t_list *lst);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	free_elements(t_list **begin, t_list *current);

/* get_next_line.c */
char	*get_next_line(int fd);

#endif