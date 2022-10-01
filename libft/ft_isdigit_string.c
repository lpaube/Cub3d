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
