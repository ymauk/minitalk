/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:44:24 by ymauk             #+#    #+#             */
/*   Updated: 2024/08/16 14:49:06 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*help_c2s(char character)
{
	char	*new_string;

	new_string = (char *)malloc(2 * sizeof(char));
	if (!new_string)
		return (NULL);
	new_string[0] = character;
	new_string[1] = '\0';
	return (new_string);
}

char	*character_to_string(char *string, char character)
{
	char	*new_string;
	int		len_string;

	len_string = 0;
	if (string == NULL)
		new_string = help_c2s(character);
	else
	{
		len_string = ft_strlen(string);
		new_string = (char *)malloc((len_string + 2) * sizeof(char));
		if (!new_string)
		{
			free (string);
			return (NULL);
		}
		ft_strlcpy(new_string, string, len_string + 1);
		new_string[len_string] = character;
		new_string[len_string + 1] = '\0';
		free (string);
	}
	return (new_string);
}

void	handle_signal(int signal)
{
	static char	character = 0;
	static int	pos_bit = 0;
	static char	*string = NULL;

	if (signal == SIGUSR1)
		character |= (1 << pos_bit);
	pos_bit++;
	if (pos_bit == 8)
	{
		if (character != '\0')
			string = character_to_string(string, character);
		else
		{
			ft_printf("%s", string);
			ft_printf("\n");
			free (string);
			string = NULL;
		}
		pos_bit = 0;
		character = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	pid = getpid();
	ft_printf("PID Number of Server: %s%d\n%s", G, pid, DC);
	ft_printf("Type in as Client: %s<PID Number of Server> <text>\n%s", G, DC);
	sa.sa_handler = handle_signal;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		usleep(100);
	}
	return (0);
}
