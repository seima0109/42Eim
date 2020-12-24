/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stomonoh <stomonoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 14:15:23 by stomonoh          #+#    #+#             */
/*   Updated: 2020/12/24 14:01:11 by stomonoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *str1, char *str2)
{
	char	*new_str;
	int		i;
	size_t	len_1;
	size_t	len_2;
	
	len_1 = str1 ? ft_strlen(str1) : 0;
	len_2 = str2 ? ft_strlen(str2) : 0;
	if (!str1 && !str2)
		return (NULL);
	i = 0;
	if (!(new_str = malloc(len_1 + len_2 + 1)))
		return (NULL);	
	while (len_1--)
		new_str[i++] = *str1++;
	while (len_2--)
		new_str[i++] = *str2++;
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_strdup(const char *str)
{
	char	*new_str;
	int		i;

	if (!(new_str = malloc(ft_strlen(str) + 1)) || !str)
		return (NULL);
	i = 0;
	while (*str)
		*(new_str + i++) = *str++;
	*(new_str + i) = '\0';
	return (new_str);
}

char	*ft_strchr(char *str, char c)
{
	int	len;

	if (!str)
		return (NULL);
	len = 0;
	while (1)
	{
		if (*str == c)
			return (str);
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


char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
		return (ft_strdup("\0"));
	i = 0;
	if (!(str = (char *)malloc((len - start + 1) * sizeof(char))))
		return (NULL);
	while (i < len && s[start + i])
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
