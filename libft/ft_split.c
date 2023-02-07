/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 19:12:30 by ccaballe          #+#    #+#             */
/*   Updated: 2023/01/04 13:03:38 by ccaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_num_words(char *s, char c)
{
	int	nw;
	int	i;

	nw = 0;
	i = 0;
	if (ft_strlen(s) == 0)
		return (0);
	while (s[i])
	{
		if ((s[i] == c && i != 0 && s[i - 1] != c))
			nw++;
		i++;
	}
	if (s[i] == '\0' && s[i - 1] != c)
		nw++;
	return (nw);
}

static size_t	ft_lenword(char *s, int i, char c)
{
	size_t	start;

	start = (size_t)i;
	while (s[i] && s[i] != c)
		i++;
	return ((size_t)i - start);
}

static void	*ft_free(char **m)
{
	int	i;

	i = 0;
	while (m[i])
	{
		free(m[i]);
		i++;
	}
	free(m);
	return (NULL);
}

char	**ft_split(char *s, char c)
{
	char	**m;
	int		row;
	int		i;

	row = 0;
	m = (char **)malloc(sizeof(char *) * (ft_num_words(s, c) + 1));
	if (!m || !s)
		return (NULL);
	i = 0;
	while (row < ft_num_words(s, c) && s[i])
	{
		if (s[i] != c)
		{
			m[row] = ft_substr(s, i, ft_lenword(s, i, c));
			if (!m[row])
				return (ft_free(m));
			i += ft_lenword(s, i, c) + 1;
			row++;
		}
		else
			i++;
	}
	m[row] = 0;
	return (m);
}
/*
int	main(void)
{	
	char	**tab;

	tab = ft_split("xxxxxxxxhello!", 'x');
	printf("%d\n", ft_num_words("xxxxxxxxhello!", 'x'));
	printf("%s\n", tab[0]);
	return (0);
}*/