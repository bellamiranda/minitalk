/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismirand <ismirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:26:06 by ismirand          #+#    #+#             */
/*   Updated: 2024/06/04 14:58:49 by ismirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>//write, getpid
# include <stdlib.h>//malloc, free, exit
# include <signal.h>//sigaction, siginfo_t
# include <sys/types.h>
# include <locale.h>//setlocale   
# include "ft_printf/ft_printf.h"

//COLORS
# define RED     "\033[1;31m"
# define GREEN   "\033[1;32m"
# define YELLOW  "\033[1;33m"
# define BLUE    "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define CYAN    "\033[1;36m"
# define END	 "\033[0m"

//SERVER
void	*ft_memset(void *s, int c, size_t n);
void	handler(int signal, siginfo_t *info, void *context);

//CLIENT
int		ft_atoi(const char *str);
void	c_handler(int signal);
void	char_to_signal(char c, int pid);

#endif