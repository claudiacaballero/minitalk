/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:50:18 by ccaballe          #+#    #+#             */
/*   Updated: 2023/02/08 18:15:17 by ccaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//fer funcio pel pid

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	if (ft_printf("%i\n", pid) == -1)
		exit(1);
	signal(SIGUSR1, &get_byte(SIGUSR1));
	signal(SIGUSR2, &get_byte(SIGUSR2));
	while (1)
		pause();
	return (0);
}

void	get_byte(int sig)
{
	int	bits[8];
	int	i;

	i = 0;
	if (sig == SIGUSR1)
		bits[i] = 1;
	else
		bits[i] = 0;
	i++;
}

/*void	byte_to_char(int *bits)
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
}*/
