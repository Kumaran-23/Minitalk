/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snair <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 07:50:04 by snair             #+#    #+#             */
/*   Updated: 2022/03/22 20:02:45 by snair            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"

void	error(int i)
{
	if (i == 0)
	{
		ft_putstr_fd("Invalid PID\n", 1);
		exit(1);
	}
}

void	send_bits(int pid, char *str)
{
	int		i;
	char	c;

	i = 7;
	while (i >= 0)
	{
		c = *str >> i & 1;
		if (c)
		{
			if (kill(pid, SIGUSR2) == -1)
				error(0);
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				error(0);
		}
		i--;
		usleep(150);
	}
}

void	signal_received(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_putstr_fd("Signal Received!\n", 1);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		return (ft_putstr_fd("Format ./client [Server PID] [\"message\"]\n", 1));
	ft_putstr_fd("Sent: ", 1);
	ft_putnbr_fd(ft_strlen(argv[2]), 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, signal_received);
	pid = ft_atoi(argv[1]);
	while (argv[2])
		send_bits(pid, argv[2]++);
	send_bits(pid, argv[2]);
}
