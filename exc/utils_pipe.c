/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchmouk <rchmouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:37:23 by mmajdoub          #+#    #+#             */
/*   Updated: 2023/06/18 17:31:42 by rchmouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_pipe_helper(t_parc **all, t_pipe *t, t_heredoc **idfd,
		t_env **env_list)
{
	if (!(*all)->arg)
		return ;
	t->eropin = ft_open_infile((*all), idfd);
	t->eropout = ft_open_outfile((*all));
	if (t->eropin != -1)
		dup2(t->eropin, 0);
	close(t->fd[0]);
	if (t->eropout == -1)
		dup2(t->fd[1], 1);
	else
		dup2(t->eropout, 1);
	if (ft_builtins((*all), env_list) == 1)
	{
		t->bufcmd = ft_get_bufcmd(t->spltcmd, (*all)->arg[0]);
		execve(t->bufcmd, (*all)->arg, NULL);
		free_dubl(t->spltcmd);
		free(t->bufcmd);
		(write(2, "EXECVE ERROR ! \n", 17), exit(127));
	}
	exit(0);
}

void	ft_pipe_helper2(t_parc **all, t_pipe *t, t_heredoc **idfd)
{
	if (!(*all)->arg)
		return ;
	t->eropin = ft_open_infile((*all), idfd);
	t->eropout = ft_open_outfile((*all));
	close(t->fd[0]);
	if (t->eropin == -1)
		dup2(t->idpip, 0);
	else
		dup2(t->eropin, 0);
	if (t->eropout != -1)
		dup2(t->eropout, 1);
	else
		dup2(t->fd[1], 1);
	if (ft_builtins((*all), &(*all)->env_list) == 1)
	{
		t->bufcmd = ft_get_bufcmd(t->spltcmd, (*all)->arg[0]);
		execve(t->bufcmd, (*all)->arg, NULL);
		free_dubl(t->spltcmd);
		free(t->bufcmd);
		(write(2, "EXECVE ERROR ! \n", 17), exit(127));
	}
	exit(0);
}

void	ft_pipe_helper3(t_parc **all, t_pipe *t, t_heredoc **idfd)
{
	if (!(*all)->arg)
		return ;
	t->eropin = ft_open_infile((*all), idfd);
	t->eropout = ft_open_outfile((*all));
	close(t->fd[1]);
	if (t->eropin == -1)
		dup2(t->fd[0], 0);
	else
		dup2(t->eropin, 0);
	if (t->eropout != -1)
		dup2(t->eropout, 1);
	if (ft_builtins((*all), &(*all)->env_list) == 1)
	{
		t->bufcmd = ft_get_bufcmd(t->spltcmd, (*all)->arg[0]);
		execve(t->bufcmd, (*all)->arg, NULL);
		free_dubl(t->spltcmd);
		free(t->bufcmd);
		(write(2, "EXECVE ERROR ! \n", 17), exit(127));
	}
	exit(0);
}

void	ft_pipe_helper4(t_parc **all, t_pipe *t, t_heredoc **idfd)
{
	(*all) = (*all)->next;
	if (ft_check_ex_heredoc(all) == 0)
		*idfd = (*idfd)->next;
	while ((*all)->next)
	{
		close(t->fd[1]);
		t->idpip = t->fd[0];
		pipe(t->fd);
		if (fork() == 0)
			ft_pipe_helper2(all, t, idfd);
		close(t->idpip);
		(*all) = (*all)->next;
		if (ft_check_ex_heredoc(all) == 0)
			*idfd = (*idfd)->next;
	}
}
