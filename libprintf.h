/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:31:09 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/01/02 15:31:11 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_integer(long nb);
int	ft_char(char x);
int	ft_hex(unsigned long nb, char c);