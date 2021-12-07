/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 11:59:55 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/09 10:18:04 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit_string(char *c)
{
	int	index;

	index = 0;
	if (c[index] == '-' || c[index] == '+')
		index++;
	while (c[index + 1])
	{
		if (c[index] >= '0' && c[index] <= '9')
			index++;
		else
			return (0);
	}
	if (c[index] >= '0' && c[index] <= '9')
		return (1);
	else
		return (0);
}
