/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:44:16 by ymauk             #+#    #+#             */
/*   Updated: 2024/08/16 10:03:46 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sending_message(pid_t sending_pid, char *message)
{
	int		len;
	int		i;
	int		x;
	char	c;

	i = 0;
	len = ft_strlen(message);
	while (i <= len)
	{
		c = message[i];
		x = 0;
		while (x < 8)
		{
			if ((c & (1 << x)) != 0)
				kill (sending_pid, SIGUSR1);
			else
				kill (sending_pid, SIGUSR2);
			usleep(100);
			x++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	sending_pid;

	if (argc != 3)
		return (ft_printf("%sWrong amount of arguments!%s\n", R, DC));
	sending_pid = ft_atoi(argv[1]);
	sending_message(sending_pid, argv[2]);
	return (0);
}
