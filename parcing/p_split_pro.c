/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_split_pro.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchmouk <rchmouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 00:54:26 by rchmouk           #+#    #+#             */
/*   Updated: 2023/06/10 23:38:09 by rchmouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	count(int *tab, int len, int i, int count)
{
	int	x;

	while (i < len)
	{
		x = tab[i];
		if (x == 2 || x == 0 || x == 5 || x == 3)
		{
			while (i < len && tab[i] == x)
				i++;
			count++;
		}
		else
			i++;
	}
	return (count);
}

char	*get_str(char *str, int *tab, int size, int bool)
{
	static int	x;
	int			len;
	int			start;

	len = 0;
	start = 0;
	if (bool == 1)
	{
		x = 0;
		return (NULL);
	}
	while (x < size)
	{
		if (tab[x] == 0 || tab[x] == 2 || tab[x] == 3 || tab[x] == 5)
		{
			start = x;
			while (x < size && tab[x] == tab[start])
				x++;
			len = x;
			break ;
		}
		else
			x++;
	}
	return (ft_substr(str, start, len - start));
}

char	**p_split_pro(char *str)
{
	int		nb;
	int		i;
	int		len;
	int		*tab;
	char	**container;

	i = 0;
	len = ft_strlen(str);
	tab = string_to_nbr(str);
	nb = count(tab, len, 0, 0);
	container = malloc(sizeof(char *) * (nb + 1));
	while (i < nb)
		container[i++] = get_str(str, tab, len, 0);
	container[i] = get_str(str, tab, len, 1);
	free(tab);
	return (container);
}
