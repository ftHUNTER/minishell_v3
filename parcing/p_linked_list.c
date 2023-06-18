/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_linked_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchmouk <rchmouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 05:40:50 by rchmouk           #+#    #+#             */
/*   Updated: 2023/05/23 22:18:46 by rchmouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_parc	*ft_lst_last(t_parc *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lst_add_back(t_parc *lst, t_parc *new)
{
	if (lst == NULL)
		lst = new;
	else
		(ft_lst_last(lst))->next = new;
}

t_env	*ft_lst_last2(t_env *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lst_add_back2(t_env *lst, t_env *new)
{
	if (lst == NULL)
	{
		lst = new;
	}
	else
		(ft_lst_last2(lst))->next = new;
}
