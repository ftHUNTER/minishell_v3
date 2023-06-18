/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_fill_env_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchmouk <rchmouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 22:17:35 by rchmouk           #+#    #+#             */
/*   Updated: 2023/05/23 23:00:37 by rchmouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_var(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			break ;
		i++;
	}
	return (ft_substr(str, 0, i));
}

char	*ft_val(char *str)
{
	int	i;
	int	start;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			break ;
		i++;
	}
	start = i + 1;
	return (ft_substr(str, start, ft_strlen(str) - start));
}

t_env	*ft_fill_lst2(char **env)
{
	int		i;
	t_env	*new;
	t_env	*tmp;

	i = 0;
	tmp = malloc(sizeof(t_env));
	tmp->var = ft_var(env[i]);
	tmp->val = ft_val(env[i]);
	tmp->next = NULL;
	new = tmp;
	while (env[i])
	{
		tmp = malloc(sizeof(t_env));
		tmp->var = ft_var(env[i]);
		tmp->val = ft_val(env[i]);
		tmp->next = NULL;
		ft_lst_add_back2(new, tmp);
		i++;
	}
	return (new);
}
