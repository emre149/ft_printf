/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 11:04:14 by ededemog          #+#    #+#             */
/*   Updated: 2024/01/06 16:10:16 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);

int		print_format(char specifier, va_list ptr);

int		ft_putchar(int c);

int		ft_putstr(char *str);

int		ft_putdigit(long n, int base, char specifier);

int		ft_putudigit(unsigned long n);

#endif