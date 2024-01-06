/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 11:23:19 by ededemog          #+#    #+#             */
/*   Updated: 2024/01/06 16:32:13 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(char specifier, va_list ptr)
{
	int	i;

	i = 0;
	if (specifier == 'c')
		i += ft_putchar(va_arg(ptr, int));
	else if (specifier == 's')
		i += ft_putstr(va_arg(ptr, char *));
	else if (specifier == 'd' || specifier == 'i')
		i += ft_putdigit((long)va_arg(ptr, int), 10, specifier);
	else if (specifier == 'x' || specifier == 'X')
		i += ft_putdigit((long)va_arg(ptr, unsigned int), 16, specifier);
	else if (specifier == 'u')
		i += ft_putudigit(va_arg(ptr, unsigned int));
	else if (specifier == 'p')
		i += ft_putptr(va_arg(ptr, unsigned int), 16)
	else
		i += write(1, &specifier, 1);
	return (i);
}

/*

pointer = p 
unsigned = u
hexa en maj = X

*/