#include <stdio.h>
int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}
int	ft_check(char *str)
{
	int i;
	
	i = -1;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int main()
{
    printf("%d\n", ft_check("a1233"));
}