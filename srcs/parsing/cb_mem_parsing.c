/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_mem_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:58:58 by mafortin          #+#    #+#             */
/*   Updated: 2022/03/07 13:25:13 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include "../includes/parsing.h"
#include "../libft/libft.h"


bool	free_color(char **numbers)
{
	ft_free_tab(numbers);
	return (false);
}
