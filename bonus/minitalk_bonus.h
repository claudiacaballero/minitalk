/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:02:52 by ccaballe          #+#    #+#             */
/*   Updated: 2023/02/22 18:26:27 by ccaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <signal.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

void	get_byte(int sig, pid_t pid);
int		valid_pid(char *s);
void	char_to_byte(char *s, pid_t pid);
void	byte_to_char(int *bits, pid_t pid);


#endif