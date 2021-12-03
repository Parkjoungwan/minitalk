/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:53:49 by joupark           #+#    #+#             */
/*   Updated: 2021/12/03 21:00:30 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# define BUFFSIZE 1024
# include <signal.h>

typedef struct s_pack
{
	char	message[BUFFSIZE];
	int		bit;
	int		byte;
	int		received;
	int		overflow;
}				t_pack;

t_pack	g_set = {{0}, 1 << 6, 0, 0, 0};

void	error(char	*str_error);
#endif
