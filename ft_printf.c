/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:26:29 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/01/02 11:27:05 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

static size_t	check_conversion(const char *str, va_list var_args)
{
	int	count;

	count = 0;
	if (*(str + 1) == '%')
	{
		count += write(1, "%", 1);
	}
	if (*(str + 1) == 'i' || *(str + 1) == 'd')
	{
		count += ft_integer(va_arg(var_args, int));
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	var_args;
	size_t	count;

	va_start(var_args, str);
	count = 0;
	while (*str)
	{
		if(*str == '%')
		{
			count += check_conversion(str, var_args);
			str++;
		}
		str++;
	}
	return (count);
}

int main(void)
{
	printf("\n%d\n", ft_printf("%d", -2147483648));
	return (0);
}