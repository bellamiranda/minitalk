/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismirand <ismirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:00:52 by ismirand          #+#    #+#             */
/*   Updated: 2023/11/16 20:17:11 by ismirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer(void *str)
{
	unsigned long	n;
	char			*base;
	int				i;

	n = (unsigned long)str;
	base = "0123456789abcdef";
	i = 0;
	if (!str)
		return (ft_putstr("(nil)"));
	if (n / 16 == 0)
		i += ft_putstr("0x");
	if (n / 16 != 0)
		i += ft_pointer((void *)(n / 16));
	i += ft_putchar(base[n % 16]);
	return (i);
}

/* int	main(void)
{
	int	i = printf("%p", NULL);
	printf("%i\n", i);
	printf("%i", ft_pointer(NULL));
} */
