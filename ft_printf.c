/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:26:29 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/01/04 17:53:20 by ccosta-c         ###   ########.fr       */
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
	if (*(str + 1) == 'c')
		count += ft_char(va_arg(var_args, int));
	if (*(str + 1) == 's')
		count += ft_string(va_arg(var_args, char*));
	if (*(str + 1) == 'u')
		count += ft_unsigned(va_arg(var_args, unsigned int));
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
		else
		{
			count += ft_char(*str);
		}
		str++;
	}
	return (count);
}
 
int main(void)
{
	int	counter_mine;
	int	counter_official;

	counter_official = 0;
	counter_mine = ft_printf("\n%s\n", "FODASSE");
	counter_official = printf("\n%p\n", &counter_official);
	printf("counter_mine%i\ncounter_official%i\n", counter_mine, counter_official);
	return (0);
}