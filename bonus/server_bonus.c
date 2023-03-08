/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:04:32 by ccaballe          #+#    #+#             */
/*   Updated: 2023/03/07 18:04:54 by ccaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	main(void)
{
	pid_t				pid_server;
	struct sigaction	sa;

	pid_server = getpid();
	if (ft_printf("%i\n", pid_server) == -1)
		exit(1);
	sa.sa_sigaction = &handler_server;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		exit(1);
	if (sigaction(SIGUSR2, &sa, NULL))
		exit(1);
	while (1)
		pause();
	return (0);
}

void	handler_server(int signo, siginfo_t *info, void *other)
{
	static int	c = 0;
	static int	num_bit = 0;

	(void)other;
	if (signo == SIGUSR1)
		c = (c | (128 >> num_bit));
	num_bit++;
	if (kill(info->si_pid, SIGUSR1) == -1)
		exit(1);
	if (num_bit == 8)
	{
		if (c == '\0')
		{
			if (kill(info->si_pid, SIGUSR2) == -1)
				exit(1);
		}
		ft_printf("%c", c);
		num_bit = 0;
		c = 0;
	}
}
