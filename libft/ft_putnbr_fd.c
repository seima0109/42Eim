/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stomonoh <stomonoh@student.42tokyo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 20:35:30 by stomonoh          #+#    #+#             */
/*   Updated: 2020/10/24 20:40:27 by stomonoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	put(unsigned int num, int fd)
{
	int				p;

	if (num < 10)
	{
		p = num + '0';
		write(fd, &p, 1);
		return ;
	}
	put(num / 10, fd);
	p = num % 10 + '0';
	write(fd, &p, 1);
}

void		ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;

	if (n < 0)
	{
		num = -n;
		write(fd, "-", 1);
	}
	else
		num = n;
	put(num, fd);
}
