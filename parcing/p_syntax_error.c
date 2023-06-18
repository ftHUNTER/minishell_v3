/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_syntax_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchmouk <rchmouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:19:10 by rchmouk           #+#    #+#             */
/*   Updated: 2023/06/10 23:33:14 by rchmouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_cout(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			c = str[i++];
			while (str[i] != c)
			{
				if (str[i] == '\0')
				{
					printf("syntax error\n");
					return (0);
				}
				i++;
			}
		}
		i++;
	}
	return (1);
}

int	check_error(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (str[0] == '|' && len > 1)
		return (0);
	if (len == 2)
	{
		if (str[0] == str[1])
			return (1);
	}
	else if (len == 1)
		return (1);
	return (0);
}

int	check_redirection(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i][0] == '>' || str[i][0] == '<' || str[i][0] == '|')
		{
			if (check_error(str[i]) == 0)
			{
				printf("syntax error\n");
				return (0);
			}
		}
		i++;
	}
	return (1);
}

int	check_orderly(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i][0] == '>' || str[i][0] == '<')
		{
			if (str[i + 1] == NULL || str[i + 1][0] == '>' || str[i
				+ 1][0] == '<' || str[i + 1][0] == '|')
			{
				printf("syntax error\n");
				return (0);
			}
		}
		i++;
	}
	return (1);
}

int	p_syntax_error(char **container, char *buffer)
{
	if (container[0] != NULL && buffer != NULL)
	{
		if (check_orderly(container) == 0 || check_pipe(container) == 0
			|| check_cout(buffer) == 0 || check_redirection(container) == 0)
			return (0);
	}
	return (1);
}
