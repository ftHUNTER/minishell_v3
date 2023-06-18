/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_fill_lst_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchmouk <rchmouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 23:01:26 by rchmouk           #+#    #+#             */
/*   Updated: 2023/05/22 23:28:36 by rchmouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_count_arg(char **container, int j)
{
	int	x;
	int	len;

	x = 0;
	len = 0;
	while (container[j] && ft_strncmp(container[j], "|",
			ft_strlen(container[j])) != 0)
	{
		if (ft_strncmp(container[j], "<", ft_strlen(container[j])) == 0)
			x++;
		else if (ft_strncmp(container[j], ">", ft_strlen(container[j])) == 0)
			x++;
		else if (ft_strncmp(container[j], ">>", ft_strlen(container[j])) == 0)
			x++;
		else if (ft_strncmp(container[j], "<<", ft_strlen(container[j])) == 0)
			x++;
		j++;
		len++;
	}
	x = len - (x * 2);
	return (x);
}

void	count_dir(int *j, int *count_dir, int count_arg, char **cont)
{
	while (cont[*j] && ft_strncmp(cont[*j], "|", ft_strlen(cont[*j])) != 0)
	{
		(*count_dir)++;
		(*j)++;
	}
	*count_dir = ((*count_dir - count_arg) / 2);
}
