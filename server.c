/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:50:18 by ccaballe          #+#    #+#             */
/*   Updated: 2023/02/13 17:56:30 by ccaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

//fer funcio pel pid

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	if (ft_printf("%i\n", pid) == -1)
		exit(1);
	while (1)
	{
		signal(SIGUSR2, get_byte);
		signal(SIGUSR1, get_byte);
		pause();
	}
	return (0);
}

void	get_byte(int sig)
{
	static int	bits[8];
	static int	i = 0;

	if (sig == SIGUSR1)
		bits[i] = 1;
	else
		bits[i] = 0;
	i++;
	if (i == 8)
	{
		byte_to_char(bits);
		i = 0;
	}
}

void	byte_to_char(int *bits)
{
	int	base;
	int	c;
	int	i;

	base = 128;
	c = 0;
	i = 0;
	while (base >= 1)
	{
		if (bits[i++] == 1)
			c += base;
		base = base / 2;
	}
	ft_printf("%c", c);
}
