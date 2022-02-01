/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_word.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 17:40:23 by mafortin          #+#    #+#             */
/*   Updated: 2022/01/30 17:48:17 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_number_word(char *string)
{
	int	nb;
	int	i;

	nb = 0;
	if (!string)
		return (-1);
	while (string[i])
	{
		if (string[i] != ' ')
		{
			nb++;
			while (string[i] != ' ' && string[i])
			{	
				i++;
				if (!string[i])
					return(nb);
			}
		}
		i++;
	}
	return (nb);
}
