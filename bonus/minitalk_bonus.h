/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:02:52 by ccaballe          #+#    #+#             */
/*   Updated: 2023/03/07 17:49:15 by ccaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <signal.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

int		valid_pid(char *s);
void	char_to_byte(char *s, pid_t pid);
void	handler_server(int signo, siginfo_t *info, void *other);
void	handler_client(int signo, siginfo_t *info, void *other);

#endif