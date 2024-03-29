/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:41:26 by ededemog          #+#    #+#             */
/*   Updated: 2024/01/06 18:22:02 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	va_list	pointer;
	int		counter;

	counter = 0;
	va_start(pointer, format);
	while (*format)
	{
		if (*format == '%')
			counter += print_format(*(++format), pointer);
		else
			counter += write(1, format, 1);
		++format;
	}
	va_end(pointer);
	return (counter);
}
