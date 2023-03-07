/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:05:28 by ccaballe          #+#    #+#             */
/*   Updated: 2023/03/07 12:21:43 by ccaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	main(int argc, char **argv)
{
	pid_t				pid_server;
	struct sigaction	sa;
	int					i;

	if (argc != 3)
		return (0);
	if (!valid_pid(argv[1]))
		return (0);
	pid_server = ft_atoi(argv[1]);
	sa.sa_sigaction = &handler_client;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		exit(1);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		exit(1);
	char_to_byte(argv[2], pid_server);
	i = -1;
	while (++i < 8)
	{
		if (kill(pid_server, SIGUSR2) == -1)
			exit(1);
		usleep(60);
	}
	while (1)
		pause();
	return (0);
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

void	handler_client(int signo, siginfo_t *info, void *other)
{
	static unsigned long int	i = 0;

	(void)other;
	(void)info;
	if (signo == SIGUSR1)
	{
		i++;
		usleep(60);
		ft_printf("\r -- sent bits = %d --\r", i);
	}
	if (signo == SIGUSR2)
	{
		usleep(60);
		ft_printf("total bytes printed = %d\n", i / 8);
		exit(0);
	}
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
			usleep(100);
		}
	}
}
