/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:53:58 by yannismauk        #+#    #+#             */
/*   Updated: 2024/04/05 11:39:30 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_putnbr(int n, int *counter);
int		ft_putchar(char c, int *counter);
int		ft_putstr(char *s, int *counter);
int		ft_u_putnbr(unsigned int n, int *counter);
int		ft_cases(va_list args, int *counter, char str);
int		ft_cases_1(va_list args, int *counter, char str);
int		ft_cases_2(va_list args, int *counter, char str);
int		ft_hexasmall(unsigned int n, int *counter);
int		ft_hexabig(unsigned int n, int *counter);
int		ft_putnbr_base(unsigned int n, char *base, int *counter);
int		ft_p_putnbr(unsigned long int n, int *counter);
int		ft_if_pos(int number, int *counter);

#endif