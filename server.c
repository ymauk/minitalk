/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:44:24 by ymauk             #+#    #+#             */
/*   Updated: 2024/08/14 14:30:20 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	int	pid;

	argv = 0;
	argc = 0;
	pid = getpid();
	ft_printf("%sPID Number: %d\n%s", G, pid, DC);
	return (0);
}
