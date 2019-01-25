/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aliases.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 07:48:16 by kicausse          #+#    #+#             */
/*   Updated: 2019/01/25 07:48:16 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"

char	*replace_word(char *input, char **alias, int x)
{
	int		i;
	int		c;
	int		len;
	char	*tmp;

	i = -1;
	while (alias && alias[++i])
	{
		if ((c = ft_cfind(alias[i], '=')) == -1)
			continue ;
		alias[i][c] = '\0';
		len = ft_strlen(alias[i]);
		if ((x == 0 || input[x - 1] == ' ') && ft_strncmp(input + x,
			alias[i], len) == 0 && (input[x + len] == ' '
			|| input[x + len] == '\0'))
		{
			ft_strcut(input, x, x + len);
			tmp = input;
			input = ft_strins_malloc(input, alias[i] + c + 1, x);
			ft_strdel(&tmp);
		}
		alias[i][c] = '=';
	}
	return (input);
}

char	*replace_aliases(char *input, char **alias)
{
	int		x;
	char	*output;
	int		escape;

	if ((output = ft_strdup(input)) == NULL)
		return (NULL);
	x = -1;
	escape = 0;
	while (output[++x])
	{
		if (escape && !(escape = 0))
			continue;
		if (input[x] == '\\' && (escape = 1))
			continue ;
		quote_match(output, (unsigned int*)&x, NULL);
		output = replace_word(output, alias, x);
	}
	return (output);
}