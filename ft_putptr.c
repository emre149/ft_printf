/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:25:31 by ededemog          #+#    #+#             */
/*   Updated: 2024/01/06 18:10:48 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long n, char specifier)
{
	char	*hex;
	int		i;

	i = 0;
	if (specifier == 'p')
		hex = "0123456789abcdef";
	else if (specifier == 'P')
		hex = "0123456789ABCDEF";
	if (n > 15)
	{
		i += ft_putptr(n / 16, specifier);
		i += ft_putptr(n % 16, specifier);
	}
	else if (n < 10)
		i += ft_putchar(n + '0');
	else
		i += ft_putchar(hex[n]);
	return (i);
}

int	ptr_null(unsigned long long p, char specifier)
{
	int	i;

	i = 0;
	if (p == 0)
		i += ft_putstr("(nil)");
	else
	{
		i += ft_putstr("0x");
		i += ft_putptr(p, specifier);
	}

	return (i);
}
