#include "libft.h"

int	ft_strsufix(char *s, char *sufix)
{
	size_t	slen;
	size_t	sulen;

	if (s == NULL || sufix == NULL)
		return (0);
	slen = ft_strlen(s);
	sulen = ft_strlen(sufix);
	if (sulen > slen)
		return (0);
	while (sulen > 0)
	{
		if (s[slen - 1] != sufix[sulen - 1])
			return (0);
                slen--;
                sulen--;
	}
	return (1);
}
