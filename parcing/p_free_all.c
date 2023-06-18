/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_free_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchmouk <rchmouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:43:11 by rchmouk           #+#    #+#             */
/*   Updated: 2023/06/10 23:46:50 by rchmouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_dubl(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_all(t_parc *all, char **container, char *buffer, int bool)
{
	int		i;
	t_parc	*tmp;

	i = 0;
	tmp = all;
	free(buffer);
	while (container[i])
		free(container[i++]);
	free(container);
	if (bool == 1)
	{
		while (tmp)
		{
			all = tmp;
			free_dubl(tmp->arg);
			free_dubl(tmp->name);
			if (tmp->tab)
				free(tmp->tab);
			tmp = tmp->next;
			free(all);
		}
	}
}

void	str_free(char *s1, char *s2, char *s3, char *s4)
{
	free(s1);
	free(s2);
	free(s3);
	free(s4);
}

char	*replace_free(char *s1, char *env)
{
	char	*tmp;

	tmp = s1;
	s1 = ft_strjoin(s1, env);
	free(tmp);
	return (s1);
}
