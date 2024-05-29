/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismirand <ismirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:46:58 by ismirand          #+#    #+#             */
/*   Updated: 2023/11/16 20:17:33 by ismirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i = 1;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_unsint(unsigned int nb)
{
	int	i;

	i = ft_count(nb);
	if (nb >= 10)
	{
		ft_unsint(nb / 10);
		ft_unsint(nb % 10);
	}
	else if (nb < 10)
		ft_putchar(nb + '0');
	return (i);
}
