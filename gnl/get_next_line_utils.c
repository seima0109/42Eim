/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stomonoh <stomonoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 14:15:23 by stomonoh          #+#    #+#             */
/*   Updated: 2020/11/15 23:31:39 by stomonoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *str1, char *str2)
{
	char	*new_str;
	int		i;
	int		bsize;
	size_t	len_1;

	len_1 = 0;
//	printf("*line = %s\n",str1);
	if (str1)
		len_1 = ft_strlen(str1);
	if (!str1 && !str2)
		return (NULL);
	i = 0;
//	printf("len1 = %zu ",len_1);
	if (!(new_str = malloc(len_1 + BUFFER_SIZE + 1)))
		return (NULL);	
	while (len_1--)
		new_str[i++] = *str1++;
	bsize = BUFFER_SIZE;
	while (bsize--)
		new_str[i++] = *str2++;
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_strdup(const char *str)
{
	char	*new_str;
	int		i;

	if (!(new_str = malloc(ft_strlen(str) + 1)))
		return (NULL);
	i = 0;
	while (*str)
		*(new_str + i++) = *str++;
	*(new_str + i) = '\0';
	return (new_str);
}

char	*ft_strchr(char *str, char c)
{
	char	*ans;

	while (1)
	{
		if (*str == c)
		{
			ans = ft_strdup(str);
			*str = '\0';
			return (ans);
		}
		if (!*str)
			return (NULL);
		str++;
	}
}

size_t	ft_strlen(const char *str)
{
	size_t len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

void	ft_bzero(void *buf, size_t n)
{
	unsigned char *p;

	p = (unsigned char *)buf;
	while (n--)
		*p = '\0';
}