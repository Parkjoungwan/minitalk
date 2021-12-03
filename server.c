/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 13:06:23 by joupark           #+#    #+#             */
/*   Updated: 2021/12/03 21:30:13 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft/libft.h"

void	print_pid()
{
	char	*str_pid;

	str_pid = ft_itoa(getpid());
	write(1, "pid: ", 5);
	write(1, str_pid, ft_strlen(str_pid));
	write(1, "\n", 1);
	free(str_pid);
}

void	ft_ac(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)context;
	(void)info;
	if (!g_set.bit)
	{
		g_set.bit = 1 << 6;
		++(g_set.byte);
	}
	g_set.message[g_set.byte] += g_set.bit;
	g_set.bit >>= 1;
	if (g_set.byte == BUFFSIZE - 2
			&& !g_set.bit)
		g_set.overflow = 1;
}

void	ft_nc(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)context;
	if (!g_set.bit)
	{
		g_set.bit = 1 << 6;
		++(g_set.byte);
	}
	g_set.bit >>= 1;
	if (g_set.byte == BUFFSIZE - 2 && !g_set.bit)
		g_set.overflow = 1;
	else if (!g_set.message[g_set.byte]
			&& !g_set.bit)
	{
		g_set.received = 1;
		kill(info->si_pid, SIGUSR1);
	}
}

void ft_handler(void)
{
	while (1)
	{
		pause();
		if (g_set.received || g_set.overflow)
		{
			write(1, g_set.message, ft_strlen(g_set.message));
			ft_bzero(g_set.message, BUFFSIZE);
			g_set.byte = 0;
			g_set.bit = 1 << 6;
			if (g_set.received)
				write(1, "\n", 1);
			g_set.received = 0;
			g_set.overflow = 0;
		}
	}
}

int	main(void)
{
	struct sigaction a_c;
	struct sigaction n_c;

	a_c.sa_sigaction = ft_ac;
	n_c.sa_sigaction = ft_nc;
	a_c.sa_flags = SA_SIGINFO;
	n_c.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &a_c, NULL) != 0)
		error("signal error\n");
	if (sigaction(SIGUSR2, &n_c, NULL) != 0)
		error("signal error\n");
	print_pid();
	ft_bzero(g_set.message, BUFFSIZE);
	ft_handler();
}
