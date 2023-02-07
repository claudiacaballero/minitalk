/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:50:18 by ccaballe          #+#    #+#             */
/*   Updated: 2023/02/07 18:27:24 by ccaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//fer funcio pel pid

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("%i\n", pid);
	while (1)
		pause();
	return (0);
}

void	byte_to_char(int sig)
{
	int	base;
	int	c;

	base = 128;
	c = 0;
	while (base >= 1)
	{
		if (sig == SIGUSR1)
			c += base;
		base = base / 2;
	}
}
