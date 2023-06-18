/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchmouk <rchmouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:16:26 by mmajdoub          #+#    #+#             */
/*   Updated: 2023/06/18 17:32:33 by rchmouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_addback(t_heredoc **head, int ptr)
{
	t_heredoc	*new;
	t_heredoc	*last;

	new = malloc(sizeof(t_heredoc));
	new->data = ptr;
	new->next = NULL;
	if (*head == NULL)
		*head = new;
	else
	{
		last = *head;
		while (last->next != NULL)
			last = last->next;
		last->next = new;
	}
}

void	ft_heredoc_list(t_parc **head, t_heredoc **idfd, t_env *env)
{
	t_parc	*tmp;
	int		i;
	int		c;

	i = 0;
	c = 0;
	tmp = *head;
	while (tmp)
	{
		i = 0;
		while (tmp->name[i])
		{
			if (tmp->tab[i] == 4)
				c = ft_heredoc(*head, tmp->name[i], env);
			i++;
		}
		ft_addback(idfd, c);
		tmp = tmp->next;
	}
}

int	ft_heredoc(t_parc *head, char *ptr, t_env *env)
{
	int		perout;
	int		fd[2];
	char	*buffer;

	perout = -1;
	pipe(fd);
	(void)head;
	while (1)
	{
		buffer = get_next_line(0);
		if (ft_strncmp(buffer, ptr, ft_strlen(ptr)) == 0)
			break ;
		buffer = ft_expand(buffer, env, 0);
		perout = ft_open_outfile(head);
		ft_putstr_fd(buffer, fd[1]);
	}
	close(fd[1]);
	return (fd[0]);
}
