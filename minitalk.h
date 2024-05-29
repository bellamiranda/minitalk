/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismirand <ismirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:26:06 by ismirand          #+#    #+#             */
/*   Updated: 2024/05/29 17:59:52 by ismirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include <unistd.h>//write, getpid
#include <stdlib.h>//malloc, free, exit
# include <signal.h>//sigaction, siginfo_t
# include <sys/types.h>
# include <locale.h>//setlocale   
    //setlocale(LC_ALL, "") no inicio da funcao para char unicode
#include "ft_printf/ft_printf.h"

//COLORS
# define RED     "\033[1;31m"
# define GREEN   "\033[1;32m"
# define YELLOW  "\033[1;33m"
# define BLUE    "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define CYAN    "\033[1;36m"
# define END	 "\033[0m"

void    handler(int signal);
void	char_to_signal(char c, int pid);
int 	ft_atoi(const char *str);

void	signal_handler(int sig);
void	handler_bonus(int sig, siginfo_t *info, void *context);


#endif