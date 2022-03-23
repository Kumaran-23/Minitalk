/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snair <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 08:23:32 by snair             #+#    #+#             */
/*   Updated: 2022/03/22 10:32:25 by snair            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"

void	sig_handler(int sig, siginfo_t *info, void *context)
{
	static int				i = 0;
	static unsigned char	c = 0;
	static pid_t			client_pid = 0;

	(void)context;
	if (info->si_pid != client_pid)
		client_pid = info->si_pid;
	c <<= 1;
	if (sig == SIGUSR2)
		c |= 1;
	i++;
	while (i == 8)
	{
		if (!c)
			kill(client_pid, SIGUSR1);
		if (c == '\0')
			ft_putchar_fd('\n', 1);
		ft_putchar_fd(c, 1);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	s_sigaction;

	s_sigaction.sa_sigaction = sig_handler;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	ft_putstr_fd("Server PID:\t", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	while (1)
		pause();
	return (0);
}
