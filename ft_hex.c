/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 11:59:18 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/01/02 15:33:07 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

int		ft_hex(unsigned long nb, char c)
{
	int	count;
	char *base;
	
	if (c == 'x')
		base = "0123456789abcdef";
	if (c == 'X')
		base = "0123456789ABCDEF";
	count = 0;
	if (nb >= 16)
	{
		count += ft_hex(nb / 16, c);
		count += ft_hex(nb % 16, c);
	}
	if (nb < 16)
	{
		count += ft_char(*(base + nb));
	}
	return (count);
}