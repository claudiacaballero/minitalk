/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:06:35 by ccaballe          #+#    #+#             */
/*   Updated: 2022/09/27 17:28:54 by ccaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_num(int n)
{
	int	l;

	l = 0;
	if (n == -2147483648)
		return (11);
	else if (n < 0)
	{
		l = 1;
		n *= -1;
	}
	while (n > 9)
	{
		l++;
		n /= 10;
	}
	l++;
	return (l);
}

static char	*ft_fill(int n, char *s, int len)
{
	s[len] = '\0';
	len--;
	if (n < 0)
	{
		s[0] = '-';
		n *= -1;
	}
	while (n > 9)
	{
		s[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	s[len] = n + '0';
	return (s);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		len;

	len = ft_len_num(n);
	if (n == -2147483648)
	{
		s = ft_strdup("-2147483648");
		return (s);
	}
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	s = ft_fill(n, s, len);
	return (s);
}
