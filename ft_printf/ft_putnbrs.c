/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:17:33 by ccaballe          #+#    #+#             */
/*   Updated: 2023/01/25 13:26:33 by ccaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long long int nb, int c)
{
	if (nb < 0)
	{
		if (ft_putchar('-') != 1)
			return (-1);
		c++;
		nb *= -1;
	}
	if (nb > 9)
		c = ft_putnbr(nb / 10, c);
	if (c == -1)
		return (-1);
	if (write(1, &"0123456789"[nb % 10], 1) != 1)
		return (-1);
	c++;
	return (c);
}

int	ft_putnbr_base(unsigned int nb, char c)
{
	char	*hex;
	int		res;
	int		aux;

	hex = "0123456789abcdef";
	if (c == 'X')
		hex = "0123456789ABCDEF";
	res = 0;
	aux = 0;
	if (nb > 15)
	{
		aux = ft_putnbr_base(nb / 16, c);
		if (aux == -1)
			return (-1);
		res += aux;
	}
	aux = ft_putchar((hex[nb % 16]));
	if (aux == -1)
		return (-1);
	res += aux;
	return (res);
}
