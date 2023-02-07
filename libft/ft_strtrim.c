/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 19:21:31 by ccaballe          #+#    #+#             */
/*   Updated: 2023/01/04 13:04:35 by ccaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cmpchr(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char *s1, char *set)
{
	int		i;
	int		l;
	char	*res;

	i = 0;
	l = ft_strlen(s1);
	if (!s1)
		return (NULL);
	while (i < l)
	{
		if (ft_cmpchr(s1[i], set))
			i++;
		else if (ft_cmpchr(s1[l - 1], set))
			l--;
		else
			break ;
	}
	res = (char *)malloc(sizeof(char) * (l - i + 1));
	if (!res)
		return (NULL);
	if (l - i > 0)
		ft_memcpy(res, &s1[i], l - i);
	res[l - i] = '\0';
	return (res);
}
