/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchmouk <rchmouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 23:19:17 by rchmouk           #+#    #+#             */
/*   Updated: 2023/06/18 16:53:44 by rchmouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <signal.h>
#include <termios.h>

void	handle_signal(int signal)
{
	if (signal == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

int	main(int ac, char **av, char **env)
{
	t_parc			*all;
	char			*buffer;
	char			**container;
	t_env			*env_list;
	struct termios	origenal;
	struct termios	fake;
	t_heredoc		*idfd;

	env_list = ft_fill_lst2(env);
	tcgetattr(0, &origenal);
	tcgetattr(0, &fake);
	fake.c_lflag &= ~ECHOCTL;
	while (ac && av)
	{
		idfd = NULL;
		tcsetattr(STDIN_FILENO, TCSANOW, &fake);
		signal(SIGINT, handle_signal);
		buffer = readline(">minishell: ");
		tcsetattr(STDIN_FILENO, TCSANOW, &origenal);
		if (buffer != NULL && buffer[0])
		{
			add_history(buffer);
			buffer = ft_expand(buffer, env_list, 0);
			container = p_split_pro(buffer);
			if (p_syntax_error(container, buffer) == 1)
			{
				all = ft_fill_lst(container);
				remoev_cout(all);
				ft_exc(&all, &env_list, env, &idfd);
				free_all(all, container, buffer, 1);
			}
			else
				free_all(all, container, buffer, 0);
		}
		else if (buffer == NULL)
			exit(0);
		else if (buffer[0] == 0)
			free(buffer);
	}
}
