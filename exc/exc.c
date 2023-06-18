/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchmouk <rchmouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 06:04:42 by mmajdoub          #+#    #+#             */
/*   Updated: 2023/06/18 17:30:58 by rchmouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_checkcmd(t_parc *head, t_env **env_list, char **env,
		t_heredoc **idfd)
{
	if (head->arg[0] != NULL)
	{
		if (ft_builtins(head, env_list) == 1)
			ft_one_cmd(head, env, idfd, env_list);
	}
	else
		return ;
}

int	ft_check_infile_outfile(t_parc *all)
{
	int	i;

	i = 0;
	if (all->name == NULL)
		return (1);
	while (all->name[i])
	{
		if (all->tab[i] == 1 || all->tab[i] == 2)
			return (0);
		i++;
	}
	return (1);
}

void	ft_exc(t_parc **all, t_env **env_list, char **env, t_heredoc **idfd)
{
	ft_heredoc_list(all, idfd, *env_list);
	if (ft_check_infile_outfile(*all) == 0)
	{
		if (ft_open_outfile(*all) == -1 || ft_open_infile(*all, idfd) == -1)
			return ;
	}
	if ((*all)->next)
		ft_one_pipe(all, idfd, env_list);
	else
		ft_checkcmd(*all, env_list, env, idfd);
}
