/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stomonoh <stomonoh@student.42tokyo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 15:07:36 by stomonoh          #+#    #+#             */
/*   Updated: 2020/11/01 12:04:33 by stomonoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void				ft_bzero(void *buf, size_t n);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);
void				*ft_memset(void *buf, int c, size_t n);
void				*ft_memcpy(void *buf1, const void *buf2, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t len);
void				*ft_memchr(const void *buf, int c, size_t n);
void				*ft_memmove(void *buf1, const void *buf2, size_t n);
void				*ft_calloc(size_t n, size_t size);
size_t				ft_strlen(const char *str);
size_t				ft_strlcpy(char *str1, const char *str2, size_t size);
size_t				ft_strlcat(char *str1, const char *str2, size_t size);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_atoi(char *str);
int					ft_strncmp(const char *str1, const char *str2, size_t n);
int					ft_memcmp(const void *buf1, const void *buf2, size_t n);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				*ft_strchr(const char *str, int c);
char				*ft_strrchr(const char *str, int c);
char				*ft_strdup(const char *str);
char				*ft_strjoin(const char *str1, const char *str2);
char				*ft_strnstr(const char *big,
						const char *little, size_t len);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				**ft_split(const char *s, char c);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst,
						void *(*f)(void *), void (*del)(void *));
#endif
