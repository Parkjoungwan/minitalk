/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 16:08:24 by joupark           #+#    #+#             */
/*   Updated: 2021/10/24 17:00:02 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	ft_print(int pid)
{
	char	*pid_str;

	pid_str = ft_itoa(pid);
	write(1, "server pid: ", 12);
	write(1, pid_str, ft_strlen(pid_str));
	write(1, "\n", 1);
}

int	main()
{
	ft_print(getpid());
	while(1)
		pause();
	return (0);
}
