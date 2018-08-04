/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   losange.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phaydont <phaydont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 20:45:01 by phaydont          #+#    #+#             */
/*   Updated: 2018/07/21 21:09:37 by phaydont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnchar(char c, int n)
{
	while (n > 0)
	{
		write(1, &c, 1);
		n--;
	}
}

void	p1(int h)
{
	int	i;

	i = 0;
	while (h - i >= 0)
	{
		ft_putnchar('x', h - i);
		write(1, " ", 1);
		if (i > 0)
		{
			ft_putnchar('x', i * 2 - 1);
			write(1, " ", 1);
		}
		ft_putnchar('x', h - i);
		write(1, "\n", 1);
		i++;
	}
}

void	print_losange(int h)
{
	int i;

	h--;
	p1();
	i = 1;
	while (i <= h)
	{
		ft_putnchar('x', i);
		write(1, " ", 1);
		if (i < h)
		{
			ft_putnchar('x', (h - i) * 2 - 1);
			write(1, " ", 1);
		}
		ft_putnchar('x', i);
		write(1, "\n", 1);
		i++;
	}
}
