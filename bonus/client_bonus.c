/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:05:28 by ccaballe          #+#    #+#             */
/*   Updated: 2023/03/02 17:37:09 by ccaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"


int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
		return (0);
	if (!valid_pid(argv[1]))
		return (0);
	pid = ft_atoi(argv[1]);
	char_to_byte(argv[2], pid);
	while (1)
	{
		signal(SIGUSR2, get_signal);
		signal(SIGUSR1, get_signal);
		pause();
	}
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

void	char_to_byte(char *s, pid_t pid)
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
				if (kill(pid, SIGUSR1) == -1)
					exit (1);
				s[i] -= base;
			}
			else
				if (kill(pid, SIGUSR2) == -1)
					exit(1);
			base = base / 2;
			usleep(100);
		}
	}
}

void	get_signal(int sig)
{
	static long int i;

	i = 0;
	if (sig == SIGUSR1)
	{
		usleep(100);
		ft_printf("\r recieved bits [%d]\n\r", ++i);
	}
	else if (sig == SIGUSR2)
	{
		usleep(100);
		ft_printf("done :)\n");
		exit(0);
	}
}
