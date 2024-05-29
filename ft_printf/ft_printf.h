/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismirand <ismirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 20:48:26 by ismirand          #+#    #+#             */
/*   Updated: 2023/11/16 20:16:55 by ismirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int	ft_printf(const char *str, ...);
int	ft_convert(const char *str, va_list info);
int	ft_putchar(unsigned int c);
int	ft_putstr(char *str);
int	ft_putnbr(int nb);
int	ft_unsint(unsigned int nb);
int	ft_putbase(char *base, unsigned int n);
int	ft_strlen(const char *str);
int	ft_pointer(void *str);

#endif
