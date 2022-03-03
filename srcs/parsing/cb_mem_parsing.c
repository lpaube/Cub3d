/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_mem_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:58:58 by mafortin          #+#    #+#             */
/*   Updated: 2022/03/03 13:39:18 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include "../includes/parsing.h"
#include "../libft/libft.h"

bool	free_color(int code, char *line, char **numbers, int *color)
{
	if (code == 1)
		free(line);
	if (code == 2)
	{
		free(line);
		ft_free_tab(numbers);
	}
	else
	{
		free(line);
		ft_free_tab(numbers);
		free(color);
	}
	return (false);
}
