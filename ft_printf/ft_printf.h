/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:33:56 by ccaballe          #+#    #+#             */
/*   Updated: 2022/10/19 15:04:01 by ccaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(long long int nb, int c);
int	ft_putnbr_base(unsigned int nb, char c);
int	ft_putptr(unsigned long ptr);
int	ft_print_arg(va_list args, char type);
int	ft_printf(char const *str, ...);

#endif
