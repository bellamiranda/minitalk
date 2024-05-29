/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismirand <ismirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:08:50 by ismirand          #+#    #+#             */
/*   Updated: 2023/11/16 20:17:03 by ismirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert(const char *str, va_list info)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	if (str[i] == 'c')
		ret += ft_putchar(va_arg(info, int));
	if (str[i] == 's')
		ret += ft_putstr(va_arg(info, char *));
	if (str[i] == 'i' || str[i] == 'd')
		ret += ft_putnbr(va_arg(info, int));
	if (str[i] == 'u')
		ret += ft_unsint(va_arg(info, unsigned int));
	if (str[i] == '%')
		ret += write (1, "%%", 1);
	if (str[i] == 'p')
		ret += ft_pointer(va_arg(info, void *));
	if (str[i] == 'x')
		ret += ft_putbase("0123456789abcdef", va_arg(info, unsigned int));
	if (str[i] == 'X')
		ret += ft_putbase("0123456789ABCDEF", va_arg(info, unsigned int));
	return (ret);
}
