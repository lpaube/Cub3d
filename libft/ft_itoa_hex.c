/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 16:55:12 by mafortin          #+#    #+#             */
/*   Updated: 2021/09/01 19:30:02 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	ft_deal_letter(char *str, int modulo, int index)
{
	if (modulo == 10)
		str[index] = 'A';
	if (modulo == 11)
		str[index] = 'B';
	if (modulo == 12)
		str[index] = 'C';
	if (modulo == 13)
		str[index] = 'D';
	if (modulo == 14)
		str[index] = 'E';
	if (modulo == 15)
		str[index] = 'F';
	return (str[index]);
}

char	ft_deal_modulo(char *str, int modulo, int index)
{
	if (modulo >= 10 && modulo <= 15)
		str[index] = ft_deal_letter(str, modulo, index);
	else
		str[index] = modulo + '0';
	return (str[index]);
}

char	*ft_itoa_hex(unsigned int nb)
{
	int		len;
	char	*str;
	int		index;
	int		modulo;

	index = 0;
	len = ft_digit_len(nb) + 1;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	while (nb > 0)
	{
		modulo = nb % 16;
		nb /= 16;
		str[index] = ft_deal_modulo(str, modulo, index);
		index++;
		len--;
	}
	str[index] = '\0';
	return (ft_inv_string(str, index));
}
