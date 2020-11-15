/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stomonoh <stomonoh@student.42tokyo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 17:05:40 by stomonoh          #+#    #+#             */
/*   Updated: 2020/11/01 15:24:49 by stomonoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	result_free(char **result, int i)
{
	while (--i >= 0)
		free(result[i]);
	free(result);
}

static char	**divide(const char *s, char c, int count, char **result)
{
	int		i;
	size_t	len;

	i = 0;
	while (count--)
	{
		len = 0;
		while (s[len] != c && s[len])
			len++;
		if (!(result[i] = (char *)malloc(sizeof(char) * (len + 1))))
		{
			result_free(result, i);
			return (NULL);
		}
		ft_strlcpy(result[i++], s, len + 1);
		while (*s)
		{
			if (*s == c && *(s + 1) != c)
				break ;
			s++;
		}
		s += 1;
	}
	result[i] = NULL;
	return (result);
}

char		**ft_split(const char *s, char c)
{
	char	**result;
	int		i;
	int		count;

	if (!s)
		return (NULL);
	count = 0;
	i = 0;
	while (s[i])
	{
		if ((s[i] != c && s[i]) && (s[i + 1] == c || !s[i + 1]))
			count++;
		i++;
	}
	if (count > 0 && s[0] == c)
	{
		while (*s == c)
			s++;
	}
	if (!(result = (char **)malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	return (divide(s, c, count, result));
}
