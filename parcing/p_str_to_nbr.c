/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_str_to_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchmouk <rchmouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 23:30:59 by rchmouk           #+#    #+#             */
/*   Updated: 2023/06/02 15:21:43 by rchmouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

typedef struct var
{
	int	*nb_str;
	int	i;
	int	len;
	int	lock;
	int	lock2;
}		t_arg;

void	helper(t_arg *a, char *str)
{
	if (str[a->i] == ' ' || str[a->i] == '\t')
		a->nb_str[a->i] = 1;
	else if (str[a->i] == '<' || str[a->i] == '>')
		a->nb_str[a->i] = 2;
	else if (str[a->i] == '|')
		a->nb_str[a->i] = 5;
	else if (str[a->i] == '\"')
		a->lock = 1;
	else if (str[a->i] == '\'')
		a->lock2 = 1;
}

int	*string_to_nbr(char *str)
{
	t_arg	a;

	a.i = 0;
	a.lock = 0;
	a.lock2 = 0;
	a.len = ft_strlen(str);
	a.nb_str = calloc(sizeof(int), a.len);
	while (a.i < a.len)
	{
		if (a.lock == 0 && a.lock2 == 0)
			helper(&a, str);
		else if (a.lock2 == 0 && str[a.i] == '\"')
			a.lock = 0;
		else if (a.lock == 0 && str[a.i] == '\'')
			a.lock2 = 0;
		a.i++;
	}
	return (a.nb_str);
}

void	helper2(t_arg *a, char *str)
{
	if (str[a->i] == ' ')
		a->nb_str[a->i] = 1;
	else if (str[a->i] == '<' || str[a->i] == '>' || str[a->i] == '|')
		a->nb_str[a->i] = 2;
	else if (str[a->i] == '\"')
	{
		a->lock = 1;
		a->nb_str[a->i] = 1;
	}
	else if (str[a->i] == '\'')
	{
		a->lock2 = 1;
		a->nb_str[a->i] = 1;
	}
}

int	*string_to_nbr2(char *str)
{
	t_arg	a;

	a.i = 0;
	a.lock = 0;
	a.lock2 = 0;
	a.len = ft_strlen(str);
	a.nb_str = calloc(sizeof(int), a.len);
	while (a.i < a.len)
	{
		if (a.lock == 0 && a.lock2 == 0)
			helper2(&a, str);
		else if (a.lock2 == 0 && str[a.i] == '\"')
		{
			a.lock = 0;
			a.nb_str[a.i] = 1;
		}
		else if (a.lock == 0 && str[a.i] == '\'')
		{
			a.lock2 = 0;
			a.nb_str[a.i] = 1;
		}
		a.i++;
	}
	return (a.nb_str);
}
