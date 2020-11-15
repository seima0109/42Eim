/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stomonoh <stomonoh@student.42tokyo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 17:50:47 by stomonoh          #+#    #+#             */
/*   Updated: 2020/10/31 03:26:18 by stomonoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long	strnbr(char *str)
{
	int			i;
	long long	nbr;
	long long	ov_div;
	int			ov_mod;

	ov_div = LONG_MAX / 10;
	ov_mod = LONG_MAX % 10;
	i = 0;
	nbr = 0;
	while (str[i] <= '9' && '0' <= str[i])
	{
		if (ov_div < nbr)
			return (-1);
		if (ov_div == nbr && ov_mod < str[i] - '0')
			return (-1);
		nbr *= 10;
		nbr += str[i] - '0';
		i++;
	}
	return (nbr);
}

int					ft_atoi(char *str)
{
	int		i;
	int		flag;
	long	nbr;

	i = 0;
	flag = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' \
			|| str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '-')
		flag = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	nbr = strnbr(&str[i]);
	if (flag == -1 && nbr == -1)
		return (0);
	nbr *= flag;
	return (nbr);
}
