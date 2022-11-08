/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:22:37 by tchevrie          #+#    #+#             */
/*   Updated: 2022/10/05 05:35:03 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);

size_t	ft_putadress(void *adress);
size_t	ft_putchar(const char c);
size_t	ft_puthexa_lower(const unsigned int n);
size_t	ft_puthexa_upper(const unsigned int n);
size_t	ft_putnbr(const int n);
size_t	ft_putstr(const char *str);
size_t	ft_putunbr(const unsigned int n);
size_t	ft_strlen(const char *s);

#endif