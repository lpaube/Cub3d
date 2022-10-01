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
					return (nb);
			}
		}
		i++;
	}
	return (nb);
}
