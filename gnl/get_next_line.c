/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stomonoh <stomonoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 14:16:16 by stomonoh          #+#    #+#             */
/*   Updated: 2020/12/24 16:11:11 by stomonoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	erro_free_all(char **line, char **buf, char **save)
{
	FREE_AND_NULL(buf);
	FREE_AND_NULL(line);
	FREE_AND_NULL(save);
	return (-1);
}

int	create_line(char **line, char *buf, char **save)
{
	char	*tmp;
	char	*new_line;

	if (!(new_line = ft_strchr(buf, '\n')))
	{
		if (!(tmp = ft_strjoin(*line, buf)))
			return (error_free_all(line, &buf, save));
		FREE_AND_NULL(line);
		*line = tmp;
		return (0);
	}
	*new_line = '\0';
	if (!(tmp = ft_strjoin(*line, buf)))
		return (error_free_all(line, &buf, save));
	FREE_AND_NULL(line);
	*line = tmp;
	FREE_AND_NULL(save);
	if (!(*save = ft_strdup(new_line + 1)))
		return (error_free_all(line, &buf, save));
	return (1);
}

int	read_buf(int fd, char **line, char **save)
{
	int		cnt;
	char	*buf;
	int		res;

	if (!(buf = malloc(BUFFER_SIZE + 1)))
		return (error_free_all(line, NULL, save));
	while ((cnt = read(fd, buf, BUFFER_SIZE)))
	{
		if (cnt == -1)
			return (error_free_all(line, &buf, save));
		buf[cnt] = '\0';
		if ((res = create_line(line, buf, save)) != 0)
		{
			FREE_AND_NULL(&buf);
			return (res);
		}
	}
	buf[cnt] = '\0';
	FREE_AND_NULL(save);
	FREE_AND_NULL(&buf);
	return (0);
}

int	check_save(char **save, char **line)
{
	char	*tmp;
	char	*new_line;

	if (!(tmp = ft_strdup(*save)))
		return (error_free_all(line, NULL, save));
	if ((new_line = ft_strchr(tmp, '\n')))
	{
		*new_line = '\0';
		FREE_AND_NULL(line);
		if (!(*line = ft_strdup(tmp)))
			return (error_free_all(line, NULL, save));
		FREE_AND_NULL(save);
		if (!(*save = ft_strdup(new_line + 1)))
			return (error_free_all(line, NULL, save));
		FREE_AND_NULL(&tmp);
		return (1);
	}
	FREE_AND_NULL(line);
	if (!(*line = ft_strdup(*save)))
		return (error_free_all(line, NULL, save));
	FREE_AND_NULL(save);
	FREE_AND_NULL(&tmp);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*save;
	int			ret;

	if ((BUFFER_SIZE <= 0) || fd < 0 || 255 < fd
	|| !line || !(*line = ft_strdup("")))
		return (-1);
	ret = 0;
	if (!save)
	{
		if (!(save = ft_strdup("")))
			return (error_free_all(line, NULL, NULL));
	}
	else
		ret = check_save(&save, line);
	if (!ret)
		ret = read_buf(fd, line, &save);
	return (ret);
}
