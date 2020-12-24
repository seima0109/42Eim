/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stomonoh <stomonoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 23:26:21 by stomonoh          #+#    #+#             */
/*   Updated: 2020/12/24 14:01:17 by stomonoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif
# define FREE_AND_NULL(ptr) {free(*ptr); *ptr = NULL;}

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *str);
char	*ft_strchr(char *str, char c);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_strdup(const char *str);
int		read_buf(int fd, char **line, char **save);
int		create_line(char **line, char *buf, char **save);

#endif