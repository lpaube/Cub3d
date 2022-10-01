#include "get_next_line.h"

void	gnl_free(char **save)
{
	if (save == 0)
		return ;
	if (*save)
		free(*save);
	*save = 0;
}
