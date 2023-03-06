/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:04:32 by ccaballe          #+#    #+#             */
/*   Updated: 2023/03/06 15:16:40 by ccaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

// server envia sigusr1
// quan rebi '\0' envia un sigusr2
// quan el client rebi sigusr2 exit(0)
// el client fa un printf amb \r dels bits enviats

int	main(void)
{
	pid_t				pid_server;
	struct sigaction	sa;

	pid_server = getpid();
	if (ft_printf("%i\n", pid_server) == -1)
		exit(1);
	sa.sa_sigaction = &handler;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		exit(1);
	if (sigaction(SIGUSR2, &sa, NULL))
		exit(1);
	while (1)
		pause();
	return (0);
}

void	handler(int signo, siginfo_t *info, void *other)
{
	(void)other;
	get_byte(signo, info->si_pid);
}

void	get_byte(int sig, pid_t pid_client)
{
	static int	bits[8];
	static int	i = 0;

	if (kill(pid_client, SIGUSR1) == -1)
		exit(1);
	if (sig == SIGUSR1)
		bits[i] = 1;
	else
		bits[i] = 0;
	i++;
	if (i == 8)
	{
		byte_to_char(bits, pid_client);
		i = 0;
	}
}

void	byte_to_char(int *bits, pid_t pid_client)
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
	if (c == '\0')
		if (kill(pid_client, SIGUSR2) == -1)
			exit(1);
	ft_printf("%c", c);
}
