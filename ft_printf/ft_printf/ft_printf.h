#ifndef FT_PRINTF
# define FT_PRINTF

# include <stdarg.h>
//
# include <stdio.h>
# include <unistd.h>
# include "../../libft/libft.h"
//

typedef struct{
	int		flag;
	int		mini;
	int		width;
	char	type;
}			info;

int		ft_printf(const char *str, ...);
void	print_type_c(info *test, unsigned char c, size_t *count);
void	print_type_s(info *test, char *str, size_t *count);
void	print_type_p(info *test, long p, size_t *count);
void	print_type_xX(info *test, unsigned int num, size_t *count);
void	print_type_u(info *test, unsigned int num, size_t *count);
void	print_type_id(info *test, int num, size_t *count);
void	print_type_id_2(info *test, int len, int digit, unsigned int new);
void	print_hex(char type, size_t num);
void	print_num(unsigned int num);
void	free_box(info *test);

#endif