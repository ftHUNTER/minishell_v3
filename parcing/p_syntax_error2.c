/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_syntax_error2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchmouk <rchmouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 23:30:56 by rchmouk           #+#    #+#             */
/*   Updated: 2023/06/10 23:33:45 by rchmouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strcmp_error(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}

int	check_pipe(char **container)
{
	int	i;

	i = 0;
	if (ft_strcmp_error(container[i], "|") == 0)
	{
		printf("syntax error\n");
		return (0);
	}
	while (container[i])
		i++;
	if (ft_strcmp_error(container[i - 1], "|") == 0)
	{
		printf("syntax error\n");
		return (0);
	}
	return (1);
}
