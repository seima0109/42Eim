/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stomonoh <stomonoh@student.42tokyo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 04:51:39 by stomonoh          #+#    #+#             */
/*   Updated: 2020/10/24 21:11:06 by stomonoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	nbrinstr(char *ans, unsigned int n)
{
	if (n < 10)
	{
		*ans = n + '0';
		return ;
	}
	nbrinstr(ans - 1, n / 10);
	*ans = n % 10 + '0';
}

char		*ft_itoa(int n)
{
	char			*ans;
	int				i;
	unsigned int	size;

	if (n < 0)
		size = -n;
	else
		size = n;
	i = 1;
	while (n >= 10 || n <= -10)
	{
		n /= 10;
		i++;
	}
	if (n < 0)
		i++;
	if (!(ans = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	if (n < 0)
		*ans = '-';
	nbrinstr(ans + i - 1, size);
	*(ans + i) = '\0';
	return (ans);
}
