/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_bit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:27:57 by kicausse          #+#    #+#             */
/*   Updated: 2018/11/06 17:27:58 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_set_bit(int nbr, int idx, char value)
{
	return (nbr ^ ((-value ^ nbr) & (1UL << idx)));
}
