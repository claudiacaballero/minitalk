/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:19:56 by ccaballe          #+#    #+#             */
/*   Updated: 2023/02/13 16:34:42 by ccaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

int		valid_pid(char *s);
void	char_to_byte(char *s, pid_t pid);
void	get_byte(int sig);
void	byte_to_char(int *bits);

#endif