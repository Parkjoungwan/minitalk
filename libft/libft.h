/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:59:28 by joupark           #+#    #+#             */
/*   Updated: 2021/12/03 21:58:23 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_atoi(char *str);
void	ft_bzero(void *s, size_t n);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *s);

#endif
