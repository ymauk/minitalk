/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:44:24 by ymauk             #+#    #+#             */
/*   Updated: 2024/08/16 10:56:29 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*character_to_string(char *string, char character)
{
	
}

void	handle_signal(int signal)
{
	static char	character;
	static int	pos_bit;
	static char	*string = NULL;

	pos_bit = 0;
	character = 0;
	if (signal == SIGUSR1)
		character |= (1 << pos_bit);
	pos_bit++;
	if (pos_bit == 8)
	{
		if (character != '\0')
			character_to_string(&string, character);
		else
		{
			ft_printf("%s", string);
			free (string);
			string = NULL;
		}
	}
	pos_bit = 0;
	character = 0;
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					pid;

	argv = NULL;
	argc = 0;
	pid = getpid();
	ft_printf("%sPID Number: %d\n%s", G, pid, DC);
	sa.sa_handler = handle_signal;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
