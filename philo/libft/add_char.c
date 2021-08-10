#include "libft.h"

char	*add_char(char *str, unsigned int byte)
{
	char	*ptr;
	int		i;

	i = ft_strlen(str);
	ptr = malloc(i + 2);
	i--;
	while (i >= 0)
	{
		ptr[i] = str[i];
		i--;
	}
	ptr[ft_strlen(str)] = byte;
	ptr[ft_strlen(str) + 1] = '\0';
	return (ptr);
}
