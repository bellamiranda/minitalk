/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismirand <ismirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 21:43:54 by ismirand          #+#    #+#             */
/*   Updated: 2023/11/16 20:17:26 by ismirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count(int n)
{
	int				i;
	unsigned int	numb;

	numb = n;
	i = 0;
	if (n == 0)
		i = 1;
	if (n < 0)
	{
		i++;
		numb = -n;
	}
	while (numb > 0)
	{
		numb = numb / 10;
		i++;
	}
	return (i);
}

int	ft_putnbr(int nb)
{
	int	i;

	i = ft_count(nb);
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(-nb);
	}
	else if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else if (nb < 10)
		ft_putchar(nb + '0');
	return (i);
}
