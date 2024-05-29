/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismirand <ismirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 16:10:50 by ismirand          #+#    #+#             */
/*   Updated: 2023/11/16 20:17:20 by ismirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putbase(char *base, unsigned int n)
{
	int		i;

	i = 0;
	if (n / ft_strlen(base) != 0)
		i += ft_putbase(base, (n / ft_strlen(base)));
	i += ft_putchar(base[n % ft_strlen(base)]);
	return (i);
}

/* 
//printa int em qualquer base e retorna a quantidade de nums printados
int	main(void)
{
	//ft_putbase('x', 255);
	printf("%i\n", ft_putbase("0123456789abcdef", 255));
} */
