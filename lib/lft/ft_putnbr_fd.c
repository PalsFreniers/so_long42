/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 05:41:50 by tdelage           #+#    #+#             */
/*   Updated: 2023/11/01 17:32:23 by tdelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

static char	get_int(int n)
{
	return (n + '0');
}

static void	ft_putnbr_buf(unsigned int nb, int fd)
{
	int		pos;
	int		rem;
	char	buf[12];

	pos = 0;
	while (pos == 0 || nb > 0)
	{
		rem = nb % 10;
		nb /= 10;
		buf[pos++] = get_int(rem);
	}
	while (--pos >= 0)
	{
		write(fd, &buf[pos], 1);
	}
}

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_buf(-nb, fd);
	}
	else
	{
		ft_putnbr_buf(nb, fd);
	}
}
