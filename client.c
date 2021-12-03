/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 12:53:51 by joupark           #+#    #+#             */
/*   Updated: 2021/12/03 21:33:37 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft/libft.h"

void	send_char(int pid, unsigned char byte)
{
	int counter;

	counter = 1 << 6;
	while (counter)
	{
		if (byte & counter)
		{
			if (kill(pid, SIGUSR1) == -1)
				error("bad pid\n");
		}
		else
			if (kill(pid, SIGUSR2) == -1)
				error("bad pid\n");
		counter >>= 1;
		usleep(600);
	}
}

void	ft_handler(char *str_pid, char *message)
{
	int pid;
	
	pid = ft_atoi(str_pid);
	while (*message)
	{
		send_char(pid, *message);
		++message;
	}
	send_char(pid, *message);
}

void	success(int sig)
{
	(void)sig;
	write(1, "received!\n", 10);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		error("Wrong input set!\n ./tyr -> client [pid] [msg]\n");
	signal(SIGUSR1, success);
	ft_handler(argv[1], argv[2]);
	return (0);
}
