/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_expand_help.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchmouk <rchmouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 22:05:18 by rchmouk           #+#    #+#             */
/*   Updated: 2023/06/14 22:08:27 by rchmouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	rep_helper(char **str, int i, t_arg_rep a)
{
	char	*num;

	num = ft_itoa(g_exitstatus);
	if ((*str)[i] == '?')
	{
		i++;
		a.s1 = ft_substr(*str, 0, a.start);
		a.s3 = ft_substr(*str, i, ft_strlen(*str) - i);
		a.s1 = replace_free(a.s1, num);
		a.big = ft_strjoin(a.s1, a.s3);
		free(a.s1);
		free(a.s3);
		free(*str);
		free(num);
		*str = a.big;
		return (0);
	}
	return (1);
}
