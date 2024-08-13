/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:18:59 by yannismauk        #+#    #+#             */
/*   Updated: 2024/04/05 11:41:20 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		counter;

	va_start(args, str);
	i = 0;
	counter = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			if (ft_cases(args, &counter, str[i]) == -1)
				return (-1);
		}
		else
		{
			if (ft_putchar(str[i], &counter) == -1)
				return (-1);
		}
		i++;
	}
	va_end(args);
	return (counter);
}

int	ft_cases(va_list args, int *counter, char str)
{
	if (ft_cases_1(args, counter, str) == -1)
		return (-1);
	else if (ft_cases_2(args, counter, str) == -1)
		return (-1);
	return (0);
}
