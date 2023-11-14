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
	while (--sulen >= 0)
	{
		--slen;
		if (s[slen] != sufix[sulen])
			return (0);
	}
	return (1);
}
