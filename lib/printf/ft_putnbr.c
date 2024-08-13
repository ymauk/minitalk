/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 10:48:13 by ymauk             #+#    #+#             */
/*   Updated: 2024/04/04 13:02:43 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c, int *counter)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	(*counter)++;
	return (0);
}

int	ft_if_pos(int number, int *counter)
{
	char	array[20];
	int		i;

	i = 0;
	while (number != 0)
	{
		array[i++] = number % 10 + '0';
		number = number / 10;
	}
	i--;
	while (i >= 0)
	{
		if (ft_putchar(array[i], counter) == -1)
			return (-1);
		i--;
	}
	return (0);
}

int	ft_putnbr(int n, int *counter)
{
	if (n == 0)
		if (ft_putchar('0', counter) == -1)
			return (-1);
	if (n == -2147483648)
	{
		if (write(1, "-2147483648", 11) == -1)
			return (-1);
		*counter += 11;
		return (0);
	}
	if (n < 0)
	{
		if (ft_putchar('-', counter) == -1)
			return (-1);
		n = n * (-1);
	}
	if (n > 0)
	{
		if (ft_if_pos(n, counter) == -1)
			return (-1);
	}
	return (0);
}

int	ft_u_putnbr(unsigned int n, int *counter)
{
	if (n > 9)
	{
		if (ft_putnbr(n / 10, counter) == -1)
			return (-1);
		n = n % 10;
	}
	if (ft_putnbr(n, counter) == -1)
		return (-1);
	return (0);
}
