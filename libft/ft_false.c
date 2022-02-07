//HEADER

#include "libft.h"
#include <stdbool.h>

bool	ft_false(char *error_msg, int fd)
{
	ft_putstr_fd(error_msg, fd);
	return (false);
}
