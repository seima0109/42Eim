/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TomonohSeima <TomonohSeima@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 14:16:16 by stomonoh          #+#    #+#             */
/*   Updated: 2020/11/14 17:38:20 by TomonohSeim      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line (int fd, char **line)
{
	char		*buf;
	static char	*save;

	if ((buf = malloc(BUFFER_SIZE + 1)) == NULL || fd <= -1)
		return (-1);
	*line = NULL;
	//free(*line);
	if (save)
	{
		*line = ft_strdup(save);
		save = ft_strchr(*line, '\n');
		if (save)
		{
			free(buf);
			*save++ = '\0';
			return (1);
		}
	}
	save = NULL;
	free(save);
	while (1)
	{
		if (!read (fd, buf, BUFFER_SIZE))//readが0ならgnlで0を返す
		{
			*line = ft_strdup("\0");
			free(buf);
			return (0);
		}
		buf[BUFFER_SIZE] = '\0';
		save = ft_strchr(buf, '\n');
		if (save)//bufに改行があった場合最初の改行に\0を入れてsaveの参照先を次の文字に移す。
		{
			save++;
			if ((*line = ft_strjoin(*line, buf)) == NULL)
				return (-1);
			free(buf);
			return (1);
		}
		if ((*line = ft_strjoin(*line, buf)) == NULL)
			return (-1);
	}
}