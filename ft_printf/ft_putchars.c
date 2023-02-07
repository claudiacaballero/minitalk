/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:51:39 by ccaballe          #+#    #+#             */
/*   Updated: 2022/10/18 19:46:08 by ccaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	if (write(1, &c, 1) != 1)
		return (-1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		if (write(1, "(null)", 6) != 6)
			return (-1);
		return (6);
	}
	while (s[i])
	{
		if (ft_putchar(s[i]) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_putptr(unsigned long ptr)
{
	char	*hex;
	int		res;
	int		aux;

	hex = "0123456789abcdef";
	res = 0;
	aux = 0;
	if (ptr > 15)
	{
		aux = ft_putptr(ptr / 16);
		if (aux == -1)
			return (-1);
		res += aux;
	}
	aux = ft_putchar((hex[ptr % 16]));
	if (aux == -1)
		return (-1);
	res += aux;
	return (res);
}
