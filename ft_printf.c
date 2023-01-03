/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:26:29 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/01/03 15:57:58 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	if (*(str + 1) == 'x' || *(str + 1) == 'X')
		count += ft_hex(va_arg(var_args, unsigned long), *(str + 1));
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
		if (*str == '%')
		{
			count += check_conversion(str, var_args);
			str++;
		}
		if (*str == '\n')
		{
			count += ft_char('\n');
		}
		str++;
	}
	return (count);
}
/* 
int main(void)
{
	int	counter_mine;
	int	counter_official;

	counter_mine = ft_printf("\n%%\n");
	counter_official = printf("\n%%\n");
	printf("counter_mine%i\ncounter_official%i\n", counter_mine, counter_official);
	return (0);
} */