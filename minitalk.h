/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 10:27:08 by ymauk             #+#    #+#             */
/*   Updated: 2024/08/16 17:57:36 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "lib/Libft/libft.h"
# include "lib/printf/ft_printf.h"
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

//colours

# define B "\033[0;34m"
# define P "\033[0;35m"
# define R "\033[0;31m"
# define G "\033[0;32m"
# define DC "\033[0;39m"
# define Y "\033[0;33m"

//client
void	sending_message(pid_t sending_pid, char *message);

//server
char	*help_c2s(char character);
char	*character_to_string(char *string, char character);
void	handle_signal(int signal);

#endif