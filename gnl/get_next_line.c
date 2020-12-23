/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stomonoh <stomonoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 14:16:16 by stomonoh          #+#    #+#             */
/*   Updated: 2020/12/23 21:35:46 by stomonoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
int	ret_error(char *buf, char *save)
{
	free(buf);
	free(save);
	return (-1);
}*/

int	create_line(char **line, char *buf, char **save)
{
	char	*tmp;
	char	*new_line;

//	write(1, "===create_line===\n", 18);
	if (!(new_line = ft_strchr(buf, '\n')))
	{
		tmp = ft_strjoin(*line, buf);
		FREE_AND_NULL(line);
		*line = tmp;
		return (0);
	}
	*new_line = '\0';
//	write(1, "===after newline===\n", 20);
	if (!(tmp = ft_strjoin(*line, buf)))
		return (-1);
//	printf("before line free\n");
	FREE_AND_NULL(line);
	*line = tmp;
	//printf("before tmp_2 free\n");
	//FREE_AND_NULL(&tmp);
	if (!(*save = ft_strdup(new_line + 1)))
		return (-1);
	return (1);
}

int	read_buf(int fd, char **line, char **save)
{
	int		cnt;
	char	*buf;
	int		res;

//	write(1, "===read buf===\n", 15);
	buf = malloc(BUFFER_SIZE + 1);
	while ((cnt = read(fd, buf, BUFFER_SIZE)))
	{
		if (cnt == -1)
		{
			FREE_AND_NULL(&buf);
			FREE_AND_NULL(line);//エラー専用の関数作りたいかも
			return (-1);
		}
//		write(1, "before buf[cnt] = 0\n", 20);
		buf[cnt] = '\0';
//		write(1, "after buf[cnt] = 0\n", 20);
		if ((res = create_line(line, buf, save)) != 0)
		{
			FREE_AND_NULL(&buf);
			return (res);
		}
		//EOFでも改行入りでもない場合
		/*tmp = ft_strjoin(*line, buf);
		FREE_AND_NULL(line);
		*line = tmp;*/
	}
//	printf("cnt = [%d]", cnt);
	buf[cnt] = '\0';
//	printf("before save(read_buf) free\n");
	FREE_AND_NULL(save);
	FREE_AND_NULL(&buf);
	return (0);
}

int	check_save(char **save, char **line)
{
	char	*tmp;
	char	*new_line;

//	write(1, "===check save===", 16);
	tmp = ft_strdup(*save);
	if ((new_line = ft_strchr(tmp, '\n')))
	{
		*new_line = '\0';
		*line = ft_strdup(tmp);
		FREE_AND_NULL(save);
		*save = ft_strdup(new_line + 1);
		return (1);
	}
	if (!(*line = ft_strdup(*save)))
		return (-1);
//	printf("before save(check save) free\n");
	FREE_AND_NULL(save);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*save;
	int			ret;

//	printf("in gnl\n");
	if ((BUFFER_SIZE <= 0) || fd < 0 || 255 < fd 
	|| !line || !(*line = ft_strdup("")))
		return (-1);
	ret = 0;
	if (!save)
	{
		if (!(save =  ft_strdup("")))
			return (-1);
	}
	else
		ret = check_save(&save, line);//1ならリターン0ならread
	if (!ret)
	{
		ret = read_buf(fd, line, &save);
	}
	return (ret);
}
	/*
	while ((ret = read(fd, buf, BUFFER_SIZE)))
	{
		buf[BUFFER_SIZE] = '\0';
		if (ret = -1)
			return(ret_error(buf, save));
		if (!save)//1周目またはsaveが空の時
			if (!(save = ft_strdup("")))//セグフォケア
				return (ret_error);
		if (!(tmp = ft_strjoin(save, buf)))
			return (ret_error);
		free(save);
		save = tmp;
	}
	return (test(save, line));
	return (1);
}*/