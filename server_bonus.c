/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismirand <ismirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:15:30 by ismirand          #+#    #+#             */
/*   Updated: 2024/06/04 14:56:44 by ismirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (i < n)
		str[i++] = c;
	return (s);
}

void	handler_bonus(int signal, siginfo_t *info, void *context)
{
	static char	c = 0;
	static int	index = 0;

	(void)context;
	if (signal == SIGUSR1)
		c = (c | 1 << index);
	index++;
	if (index == 8)
	{
		ft_printf("%c", c);
		if (c == '\0')
			kill(info->si_pid, SIGUSR2);
		c = 0;
		index = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(int argc, char *argv[])
{
	struct sigaction	sa;

	(void)argv;
	if (argc == 1)
	{
		ft_memset(&sa, 0, sizeof(sa));
		sa.sa_sigaction = &handler_bonus;
		sa.sa_flags = SA_SIGINFO;
		sigemptyset(&sa.sa_mask);
		ft_printf(MAGENTA "Server PID: %i\n" END, getpid());
		while (1)
		{
			sigaction(SIGUSR1, &sa, NULL);
			sigaction(SIGUSR2, &sa, NULL);
			pause();
		}
	}
	else
		ft_printf(RED "!!WRONG INPUT!! Try \"./server\" instead\n" END);
	return (0);
}
