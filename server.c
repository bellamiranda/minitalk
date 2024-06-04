/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismirand <ismirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:23:29 by ismirand          #+#    #+#             */
/*   Updated: 2024/06/04 15:34:15 by ismirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

/*
manipulador de sinais que interpreta SIGUSR1 e SIGUSR2 como bits
de um caractere ASCII, recebendo bit a bit, e imprime o caractere
resultante ao final de 1 byte (8 bits)
c > armazena os bits recebidos
index > conta quantos bits foram recebidos
c = (c | 1 << index) (define um bit especifico para 1 sem alterar os outros)
| (operador OR) se ambos forem 0 o resultado e 0
		se qualquer um for 1 o resultado vai ser 1
nao precisa alterar c para SIGUSR2 pq o bit ja e 0
*/
void	handler(int signal, siginfo_t *info, void *context)
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
		c = 0;
		index = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

/* 
ft_memset garante que tudo vai estar 0 na struct
pause no while espera pelos sinais
 */
int	main(int argc, char *argv[])
{
	struct sigaction	sa;

	(void)argv;
	if (argc == 1)
	{
		ft_memset(&sa, 0, sizeof(sa));
		sa.sa_sigaction = &handler;
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

/*
SIGACTION funcao usada para examinar e modificar o comportamento de sinais
	permite especificar varias opcoes e controles 
		(definir um manipulador de sinal e especificar a maneira
		como sao entregues ao processo)
	int sigaction(int signum, const struct sigaction *act, 
			struct sigaction *oldact);
		n do sinal, ponteiro p/ struct com nova acao, ponteiro para
		armazenar antiga acao (pode ser NULL)
	struct sigaction {
	void (*sa_handler)(int);
		*ponteiro p funcao que manipula sinal simples*
	void (*sa_sigaction)(int, siginfo_t *, void *);
		*manipula sinais adicionais (usada com flag SA_SIGINFO)*
	sigset_t sa_mask;
		*mascara de sinais que serao bloqueados durante a execucao*
	int sa_flags; 
		*flags que alteram o comprtamento do sinal (SA_RESTART, SA_SIGINFO)*
};
sigemptyset - define a mascara de sinais vazia
	(nao bloqueia nenhum sinal adicional)
SA_SIGINFO - flag para especificar que o manipulador de sinal
		vai usar sa_sigaction ao inves de sa_handler
	tem que usar a *void handler(int signum, siginfo_t *info, void *context)*
		n do sinal, ponteiro para struct com infos add, ponteiro
			para contexto do sinal (usado internamente pelo sistema)
		info->si_pid - contem o PID do client
*/