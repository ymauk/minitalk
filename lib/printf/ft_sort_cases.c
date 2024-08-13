/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_cases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:07:19 by yannismauk        #+#    #+#             */
/*   Updated: 2024/04/05 11:36:37 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_cases_1(va_list args, int *counter, char str)
{
	if (str == 'd' || str == 'i')
	{
		if (ft_putnbr(va_arg(args, int), counter) == -1)
			return (-1);
	}
	if (str == 'c')
	{
		if (ft_putchar(va_arg(args, int), counter) == 1)
			return (-1);
	}
	if (str == 's')
	{
		if (ft_putstr(va_arg(args, char *), counter) == -1)
			return (-1);
	}
	if (str == '%')
	{
		if (ft_putchar('%', counter) == -1)
			return (-1);
		counter++;
	}
	return (0);
}

int	ft_cases_2(va_list args, int *counter, char str)
{
	if (str == 'u')
	{
		if (ft_u_putnbr(va_arg(args, unsigned int), counter) == -1)
			return (-1);
	}
	if (str == 'x')
	{
		if (ft_hexasmall(va_arg(args, unsigned int), counter) == -1)
			return (-1);
	}
	if (str == 'X')
	{
		if (ft_hexabig(va_arg(args, unsigned int), counter) == -1)
			return (-1);
	}
	if (str == 'p')
	{
		if (write (1, "0x", 2) == -1)
			return (-1);
		*counter = *counter + 2;
		if (ft_p_putnbr(va_arg(args, unsigned long int), counter) == -1)
			return (-1);
	}
	return (0);
}
