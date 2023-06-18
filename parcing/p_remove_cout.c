/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_remove_cout.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchmouk <rchmouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 23:16:23 by rchmouk           #+#    #+#             */
/*   Updated: 2023/05/22 23:49:57 by rchmouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*remoev(char *str, int len)
{
	int		i;
	int		*tab;
	int		count_or_index;
	char	*new_str;

	i = 0;
	count_or_index = 0;
	tab = string_to_nbr2(str);
	while (i < len)
	{
		if (tab[i++] == 0)
			count_or_index++;
	}
	new_str = malloc(count_or_index + 1);
	i = 0;
	count_or_index = 0;
	while (i < len)
	{
		if (tab[i] == 0)
			new_str[count_or_index++] = str[i];
		i++;
	}
	new_str[count_or_index] = 0;
	return (free(tab), free(str), new_str);
}

void	remoev_cout(t_parc *all)
{
	int	i;

	while (all)
	{
		i = 0;
		if (all->arg != NULL)
		{
			while (all->arg[i])
			{
				all->arg[i] = remoev(all->arg[i], ft_strlen(all->arg[i]));
				i++;
			}
		}
		i = 0;
		if (all->name != NULL)
		{
			while (all->name[i])
			{
				all->name[i] = remoev(all->name[i], ft_strlen(all->name[i]));
				i++;
			}
		}
		all = all->next;
	}
}
