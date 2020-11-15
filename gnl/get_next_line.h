#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *str);
char	*ft_strchr(char *str, char c);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_strdup(const char *str);
void	ft_bzero(void *buf, size_t n);

#endif