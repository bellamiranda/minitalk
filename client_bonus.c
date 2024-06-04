/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismirand <ismirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:15:06 by ismirand          #+#    #+#             */
/*   Updated: 2024/06/04 15:39:09 by ismirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	g_received = 0;

int	ft_atoi(const char *str)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while ((str[i] == '-' || str[i] == '+')
		&& (str[i + 1] >= '0' && str[i + 1] <= '9'))
	{
		if (str[i] == '-')
			k = k * (-1);
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		j = j * 10 + str[i] - '0';
		i++;
	}
	return (j * k);
}

void	signal_handler(int signal)
{
	if (signal == SIGUSR1)
		g_received = 1;
	if (signal == SIGUSR2)
	{
		ft_printf(GREEN "Message received!\n" END);
		exit(0);
	}
}

void	char_to_signal(char c, int pid)
{
	int	bit;
	int	error;

	bit = 0;
	while (bit < 8)
	{
		g_received = 0;
		signal(SIGUSR1, signal_handler);
		signal(SIGUSR2, signal_handler);
		if ((c & (1 << bit)) == 0)
			error = kill(pid, SIGUSR2);
		else
			error = kill(pid, SIGUSR1);
		if (error == -1)
			exit(1);
		bit++;
		while (!g_received)
			pause();
	}
}

int	main(int argc, char *argv[])
{
	int		i;
	int		pid;
	char	*str;

	if (argc == 3)
	{
		pid = ft_atoi(*(argv + 1));
		if (pid < 0)
			return (ft_printf(RED "PID incorrect\n" END));
		str = *(argv + 2);
		i = -1;
		while (str[++i])
			char_to_signal(str[i], pid);
		char_to_signal('\0', pid);
	}
	else
	{
		ft_printf(RED "!!WRONG INPUT!! Try \"./client "END);
		ft_printf(RED"PID \"message\"\" instead\n" END);
	}
	return (0);
}
