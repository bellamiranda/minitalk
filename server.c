/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismirand <ismirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:23:29 by ismirand          #+#    #+#             */
/*   Updated: 2024/05/29 17:37:45 by ismirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

void	handler(int signal)
{
	static char	c = 0;
	static int	index = 0;

	if (signal == SIGUSR1)
		c = (c | 1 << index);
    index++;
	if (index == 8)
	{
        ft_printf("%c", c);
		c = 0;
		index = 0;
	}
}

int main(int argc, char *argv[])
{
    int pid;
    
    (void)argv;
    if (argc == 1)
    {
        pid = getpid();
        ft_printf(MAGENTA"Server PID: %i\n"END, pid);
        signal(SIGUSR1, handler);
        signal(SIGUSR2, handler);
	    while (1)
            pause();//espera pelos sinais
    }
    else
        ft_printf(RED"!!WRONG INPUT!! Try \"./server\" instead\n"END);
    return (0);
}
