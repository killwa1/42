/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ccount.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 18:46:06 by kicausse          #+#    #+#             */
/*   Updated: 2019/02/28 18:46:06 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_ccount(char *str, char c)
{
	int	count;
	int	i;

	if (str == 0)
		return (0);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			++count;
		++i;
	}
	return (count);
}
