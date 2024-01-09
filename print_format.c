/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 11:23:19 by ededemog          #+#    #+#             */
/*   Updated: 2024/01/09 10:29:04 by ededemog         ###   ########.fr       */
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
	else if (specifier == 'p' || specifier == 'P')
		i += ptr_null(va_arg(ptr, unsigned long long), specifier);
	else
		i += write(1, &specifier, 1);
	return (i);
}
