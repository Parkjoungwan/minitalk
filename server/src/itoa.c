/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 16:10:16 by joupark           #+#    #+#             */
/*   Updated: 2021/10/24 16:12:55 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

size_t	ft_strlen(const char *s)
{
	size_t result;

	result = 0;
	while (s[result])
		result++;
	return (result);
}

int	ft_numlen(int n)
{
	int	result;

	result = 0;
	if (n == -2147483648)
		return (11);
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = n * -1;
		result++;
	}
	while (n > 0)
	{
		n /= 10;
		result++;
	}
	return (result);
}

static	void	ft_fillstr(int n, int i, char *result)
{
	if (n == 0)
	{
		result[0] = '0';
	}
	if (n == -2147483648)
	{
		result[i--] = '0' + 8;
		n /= 10;
	}
	if (n < 0)
	{
		result[0] = '-';
		n = n * -1;
	}
	while (n > 0)
	{
		result[i--] = '0' + (n % 10);
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*result;
	int		i;

	i = ft_numlen(n);
	result = malloc(sizeof(char) * (i + 1));
	if (!result)
		return (NULL);
	result[i--] = '\0';
	ft_fillstr(n, i, result);
	return (result);
}
