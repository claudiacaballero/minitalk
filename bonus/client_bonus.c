/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:05:28 by ccaballe          #+#    #+#             */
/*   Updated: 2023/03/06 15:36:42 by ccaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	main(int argc, char **argv)
{
	pid_t				pid_server;
	struct sigaction	sa;

	if (argc != 3)
		return (0);
	if (!valid_pid(argv[1]))
		return (0);
	pid_server = ft_atoi(argv[1]);
	sa.sa_sigaction = &handler_client;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		exit(1);
	if (sigaction(SIGUSR2, &sa, NULL))
		exit(1);
	char_to_byte(argv[2], pid_server);
	while (1)
		pause();
	return (0);
}

void	handler_client(int signo, siginfo_t *info, void *other)
{
	static long int	i = 0;

	(void)other;
	(void)info;
	if (signo == SIGUSR1)
	{
		i++;
		ft_printf("\r sent bits = %d\r", i);
	}
	else if (signo == SIGUSR2)
	{
		ft_printf("done :)\n");
		exit(0);
	}
}

int	valid_pid(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		if (!ft_isdigit(s[i]))
			return (0);
	if (ft_strlen(s) < 3 || ft_strlen(s) > 5)
		return (0);
	return (1);
}

void	char_to_byte(char *s, pid_t pid_server)
{
	int	base;
	int	i;

	i = -1;
	while (s[++i])
	{
		base = 128;
		while (base >= 1)
		{
			if (s[i] >= base)
			{
				if (kill(pid_server, SIGUSR1) == -1)
					exit (1);
				s[i] -= base;
			}
			else
				if (kill(pid_server, SIGUSR2) == -1)
					exit(1);
			base = base / 2;
			usleep(60);
		}
	}
}
