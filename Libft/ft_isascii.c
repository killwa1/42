/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 15:43:19 by kicausse          #+#    #+#             */
/*   Updated: 2018/11/06 15:43:19 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
