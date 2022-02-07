/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim_spaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 17:38:54 by mafortin          #+#    #+#             */
/*   Updated: 2022/02/07 15:12:44 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Alloc a new line, triming all extra spaces between words.
//Before: Hello       World    
//After :Hello World

int	nb_letter(char *string)
{
	int	nb;
	int	i;

	nb = 0;
	if (!string)
		return (-1);
	while (string[i])
	{
		if (string[i] == ' ')
		{
			nb++;
			while (string[i] == ' ')
				i++;
			if (!string[i])
				return (nb);
		}
		i++;
		nb++;
	}
	return (nb);
}

char	*ft_trim_spaces(char *str)
{
	int		nb;
	char	*new_str;

	nb = nb_letter(str);
	if (nb == 0)
		return (NULL);
	new_str = ft_calloc(sizeof(char) * nb);
}
