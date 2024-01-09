/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 12:56:10 by ededemog          #+#    #+#             */
/*   Updated: 2024/01/09 10:34:31 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putdigit(long n, int base, char specifier)
{
	int		i;
	char	*hex;

	i = 0;
	hex = "0123456789abcdef";
	if (specifier == 'X')
		hex = "0123456789ABCDEF";
	if (n < 0)
	{
		write(1, "-", 1);
		return (ft_putdigit(-n, base, specifier) + 1);
	}
	else if (n < base)
		return (ft_putchar(hex[n]));
	else
	{
		i = ft_putdigit(n / base, base, specifier);
		return (i + ft_putdigit(n % base, base, specifier));
	}
}

int	ft_putudigit(unsigned long n)
{
	int		i;

	if (n < 10)
		return (ft_putchar(n + '0'));
	else
	{
		i = ft_putudigit(n / 10);
		return (i + ft_putudigit(n % 10));
	}
}
