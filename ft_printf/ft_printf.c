/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismirand <ismirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 20:44:50 by ismirand          #+#    #+#             */
/*   Updated: 2023/11/16 20:17:18 by ismirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	info;
	int		i;
	int		ret;

	va_start(info, str);
	i = 0;
	ret = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ret += ft_convert(&str[i], info);
		}
		else
		{
			write(1, &str[i], 1);
			ret++;
		}
		i++;
	}
	va_end(info);
	return (ret);
}

/* 
//cc ft_printf.c ft_convert.c ft_putbase.c ft_putchar.c ft_putnbr.c \
ft_unsint.c ft_putstr.c ft_strlen.c ft_pointer.c
int	main(void)
{
	int	i;
	int	j;
	char	*s = NULL;
	long u = -4294967296;

	i = ft_printf("oi%% %x %s %i %u", 255, s, 42, u);
	printf("\n%i\n", i);
	printf("CONFERE\n");
	j = printf("oi%% %x %s %i %u", 255, s, 42, u);
	printf("\n%i", j);
}
//0 antes do numero transforma em octal
//0x antes transforma em hexadecimal
//%u -> transforma em unsigned int (0 = 4294967295), e vai
// subtraindo o num desse valor, ate o -4294967296 ser 0 dnv */
