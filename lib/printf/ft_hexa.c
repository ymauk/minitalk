/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 11:52:05 by yannismauk        #+#    #+#             */
/*   Updated: 2024/04/04 10:59:36 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexabig(unsigned int n, int *counter)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (ft_putnbr_base(n, base, counter) == -1)
		return (-1);
	return (0);
}

int	ft_hexasmall(unsigned int n, int *counter)
{
	char	*base;

	base = "0123456789abcdef";
	if (ft_putnbr_base(n, base, counter) == -1)
		return (-1);
	return (0);
}

int	ft_putnbr_base(unsigned int n, char *base, int *counter)
{
	if (n > 15)
	{
		if (ft_putnbr_base(n / 16, base, counter) == -1)
			return (-1);
		if (ft_putnbr_base(n % 16, base, counter) == -1)
			return (-1);
	}
	if (n < 16)
	{
		if (ft_putchar(base[n], counter) == -1)
			return (-1);
	}
	return (0);
}

int	ft_p_putnbr(unsigned long int n, int *counter)
{
	char	*base;

	base = "0123456789abcdef";
	if (n > 15)
	{
		if (ft_p_putnbr(n / 16, counter) == -1)
			return (-1);
		if (ft_p_putnbr(n % 16, counter) == -1)
			return (-1);
	}
	if (n < 16)
	{
		if (ft_putchar(base[n], counter) == -1)
			return (-1);
	}
	return (0);
}
