/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismirand <ismirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:15:30 by ismirand          #+#    #+#             */
/*   Updated: 2024/05/29 18:00:23 by ismirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>

void	handler_bonus(int sig, siginfo_t *info, void *context)
{
	static char	c = 0;
	static int	index = 0;

	(void)context;
	if (sig == SIGUSR1)
		c = (c | 1 << index);
	index++;
	if (index == 8)
	{
		write(1, &c, 1);
		if (c == '\0')
			kill(info->si_pid, SIGUSR1);
		c = 0;
		index = 0;
	}
}

int	main(int argc, char *argv[])
{
	int					pid;
	struct sigaction	act;

    (void)argv;
    if (argc == 1)
    {
        pid = getpid();
        ft_printf(MAGENTA"Server PID: %i\n"END, pid);
		act.sa_sigaction = handler_bonus;
		sigemptyset(&act.sa_mask);
		act.sa_flags = SA_SIGINFO;
		while (1)
		{
			sigaction(SIGUSR1, &act, NULL);
			sigaction(SIGUSR2, &act, NULL);
			pause();
		}
    }
    else
        ft_printf(RED"!!WRONG INPUT!! Try \"./server\" instead\n"END);
    return (0);
}
