/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismirand <ismirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:24:27 by ismirand          #+#    #+#             */
/*   Updated: 2024/05/29 17:24:52 by ismirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
	while ((str[i] == '-' || str[i] == '+') && \
		(str[i + 1] >= '0' && str[i + 1] <= '9'))
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

//envia sinais ao processo especificado com o pid, bit a bit
//(c & (1 << bit)) == 0 (verifica o valor de um bit especifico em um byte)
// & (operador AND) so preserva onde tiver 1 no bit E no c
//kill envia sinais especificos para determinado pid
void	char_to_signal(char c, int pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (1 << bit)) == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		bit++;
		usleep(50);
	}
}

int main(int argc, char *argv[])
{
    int     i;
    int     pid;
    char    *str;

    if (argc == 3)
    {
        pid = ft_atoi(*(argv + 1));
        if (pid < 0)
		    return (ft_printf(RED"PID incorrect\n"END));
        str = *(argv + 2);
        i = -1;
	    while (str[++i])
	    	char_to_signal(str[i], pid);
	    ft_printf(GREEN"Message transmited\n"END);
    }
    else
        ft_printf(RED"!!WRONG INPUT!! Try \"./client  PID \"message\"\" instead\n"END);
    return (0);
}

/*
SIGUSR1
SIGUSR2
standard signals that can be sent to processes using system calls
    like 'kill', 'raise' or 'sigqueue'
signal > sets a function to handle a specific signal
    signal(SIGUSR1, void (*func)(int))
                    SIG_IGN > ignore the signal
                    SIG_DFL > restore default handling
sigemptyset > initializes a signal set to exclude all signals
    sigemptyset(sigset_t *set)
    set > pointer to the signal set to be initialized
    return 0 on success or -1 on error
sigaddset > adds a specific signal to a signal set
    sigaddset(sigset_t *set, SIGUSR1)
    return 0 on success or -1 on error
sigaction > examines or changes the action associated to the signal
    sigaction(SIGUSR1, act, oact)
    act > const struct sigaction *restrict act
        pointer to a struct sigaction that has the new action
    oact > struct sigaction *restrict oact
        struct where the old action will be stored (can be NULL)
    struct sigaction {
        void (*sa_handler)(int);
        void (*sa_sigaction)(int, siginfo_t *, void *);
            signal handling function
        sigset_t sa_mask;
            signals to block during execution of the function (used in sigemptyset)
        int sa_flags;
            modify the behavior os te signal (SA_RESTART, SA_SIGINFO)
        void (*sa_restorer)(void);
    };


launch server and get it's PID
./client PID "string to send"
>>RECEIVE STRINGS FROM SEVERAL CLIENTS WITHOUT NEEDING TO RESTART<<
PID = Process Identifier (process management)
    Number assigned by the operating system to each process running on a system
    ps > lists running processes with PIDs
    kill <PID> > sends termination signal to the process
    kill -USR1 <PID> > send SIGUSR1 to a process
 */