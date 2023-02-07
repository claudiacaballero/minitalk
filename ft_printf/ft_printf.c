/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:35:29 by ccaballe          #+#    #+#             */
/*   Updated: 2023/01/30 14:59:54 by ccaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_print_arg(va_list args, char type)
{
	int	result;

	result = 0;
	if (type == 'c')
		result += ft_putchar(va_arg(args, int));
	else if (type == 's')
		result += ft_putstr(va_arg(args, char *));
	else if (type == 'i' || type == 'd')
		result += ft_putnbr(va_arg(args, int), result);
	else if (type == 'u')
		result += ft_putnbr(va_arg(args, unsigned int), result);
	else if (type == 'x' || type == 'X')
		result += ft_putnbr_base(va_arg(args, unsigned int), type);
	else if (type == 'p')
	{
		if (write(1, "0x", 2) == -1)
			return (-1);
		result = ft_putptr(va_arg (args, unsigned long));
		if (result != -1)
			result += 2;
	}
	else if (type == '%')
		result += ft_putchar('%');
	return (result);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;
	int		result;
	int		aux;

	va_start(args, str);
	i = 0;
	result = 0;
	aux = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '%')
			aux = ft_putchar(str[i]);
		else
			aux = ft_print_arg(args, str[++i]);
		i++;
		if (aux == -1)
			return (-1);
		result += aux;
	}
	va_end(args);
	return (result);
}
