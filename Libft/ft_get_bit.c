/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_bit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:30:31 by kicausse          #+#    #+#             */
/*   Updated: 2018/11/06 17:30:31 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_get_bit(int nbr, int idx)
{
	return ((nbr >> idx) & 1);
}
