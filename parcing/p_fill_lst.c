/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_fill_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchmouk <rchmouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 03:51:21 by rchmouk           #+#    #+#             */
/*   Updated: 2023/05/22 23:28:52 by rchmouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	fill_arg_name_tab(t_index *a, int *i, char **cont, t_parc *all)
{
	if (ft_strncmp(cont[*i], "<", ft_strlen(cont[*i])) == 0)
	{
		all->tab[(a->index)] = 1;
		all->name[(a->index)++] = ft_strdup(cont[++(*i)]);
	}
	else if (ft_strncmp(cont[*i], ">>", ft_strlen(cont[(*i)])) == 0)
	{
		all->tab[(a->index)] = 2;
		all->name[(a->index)++] = ft_strdup(cont[++(*i)]);
	}
	else if (ft_strncmp(cont[*i], ">", ft_strlen(cont[(*i)])) == 0)
	{
		all->tab[(a->index)] = 3;
		all->name[(a->index)++] = ft_strdup(cont[++(*i)]);
	}
	else if (ft_strncmp(cont[*i], "<<", ft_strlen(cont[(*i)])) == 0)
	{
		all->tab[(a->index)] = 4;
		all->name[(a->index)++] = ft_strdup(cont[++(*i)]);
	}
	else
		all->arg[(a->arg_i)++] = ft_strdup(cont[(*i)]);
	(*i)++;
}

void	check(int *x)
{
	if (*x > 0)
		(*x)++;
}

t_parc	*ft_fill_node(char **cont, int x)
{
	t_parc		*all;
	t_count		b;
	static int	i;
	static int	j;
	t_index		a;

	a.index = 0;
	a.arg_i = 0;
	b.count_dir = 0;
	if (x == 1)
		return (i = 0, j = 0, NULL);
	check(&j);
	b.count_arg = ft_count_arg(cont, j);
	all = malloc(sizeof(t_parc));
	all->tab = NULL;
	all->arg = malloc(sizeof(char *) * (b.count_arg + 1));
	count_dir(&j, &b.count_dir, b.count_arg, cont);
	if (b.count_dir != 0)
		all->tab = malloc(sizeof(int) * b.count_dir);
	all->name = malloc(sizeof(char *) * (b.count_dir + 1));
	check(&i);
	while (cont[i] && ft_strncmp(cont[i], "|", ft_strlen(cont[i])) != 0)
		fill_arg_name_tab(&a, &i, cont, all);
	return (all->arg[a.arg_i] = NULL, all->name[a.index] = NULL,
		all->next = NULL, all);
}

t_parc	*ft_fill_lst(char **container)
{
	t_parc	*lst;
	int		i;

	lst = ft_fill_node(container, 0);
	i = 0;
	while (container[i])
	{
		if (ft_strncmp(container[i], "|", ft_strlen(container[i])) == 0)
			break ;
		i++;
	}
	while (container[i])
	{
		if (ft_strncmp(container[i], "|", ft_strlen(container[i])) == 0)
			ft_lst_add_back(lst, ft_fill_node(container, 0));
		i++;
	}
	ft_fill_node(container, 1);
	return (lst);
}
