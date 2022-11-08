/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:03:45 by tchevrie          #+#    #+#             */
/*   Updated: 2022/10/04 22:59:57 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	conversion(const char *c, size_t *i, va_list *ap)
{
	if (*c != '%')
		return (ft_putchar(*c));
	*i = *i + 1;
	if (*(c + 1) == 'c')
		return (ft_putchar((char) va_arg(*ap, int)));
	else if (*(c + 1) == 's')
		return (ft_putstr(va_arg(*ap, const char *)));
	else if (*(c + 1) == 'p')
		return (ft_putadress(va_arg(*ap, void *)));
	else if (*(c + 1) == 'd' || *(c + 1) == 'i')
		return (ft_putnbr(va_arg(*ap, int)));
	else if (*(c + 1) == 'u')
		return (ft_putunbr(va_arg(*ap, unsigned int)));
	else if (*(c + 1) == 'x')
		return (ft_puthexa_lower(va_arg(*ap, int)));
	else if (*(c + 1) == 'X')
		return (ft_puthexa_upper(va_arg(*ap, int)));
	else if (*(c + 1))
		return (ft_putchar(*(c + 1)));
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	va_list	ap;
	size_t	i;

	len = 0;
	va_start(ap, str);
	i = 0;
	while (str[i])
	{
		len += conversion(str + i, &i, &ap);
		i++;
	}
	va_end(ap);
	return (len);
}
