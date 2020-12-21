/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stomonoh <stomonoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 14:16:16 by stomonoh          #+#    #+#             */
/*   Updated: 2020/12/21 19:48:44 by stomonoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
int	get_next_line (int fd, char **line)
{
	char		*buf;
	static char	*save;

	if ((buf = malloc(BUFFER_SIZE + 1)) == NULL || fd <= -1)
		return (-1);
	*line = NULL;
	free(*line);
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
}*/

int	get_next_line (int fd, char **line)
{
	static char	*save;
	char		*tmp;

	if (save && (tmp = ft_strchr(save, '\n')))
	{
		*tmp = '\0';
		*line = ft_strdup(save);
		save = ++tmp;
		return (1);
	}
	return (link_line(fd, line, &save));
}

int	link_line(int fd, char **line, char **save)
{
	char *buf;
	char *tmp_n;

	*line = ft_strdup(*save);
//	printf("*line<-save = [%s]\n",*line);
	if ((buf = malloc(BUFFER_SIZE + 1)) == NULL || fd <= -1)
		return (-1);
	while (1)
	{
		ft_bzero(buf, BUFFER_SIZE);
		if (!read (fd, buf, BUFFER_SIZE))//readが0ならgnlで0を返す
		{
		//	*line = ft_strjoin(*line, "\0");
		//	printf("1*line = %s\n", *line);
			free(buf);
			return (0);
		}
		if ((tmp_n = ft_strchr(buf, '\n')))//bufの中に改行があった場合
		{
			*tmp_n = '\0';
		//	printf("2*line[%s]buf[%s]\n", *line, buf);
			*line = ft_strjoin(*line, buf);
			*save = ++tmp_n;
			free(buf);
			return (1);
		}
		else
		{
		//	printf("3*line[%s]buf[%s]\n",*line, buf);
			*line = ft_strjoin(*line, buf);
		}
	}
}