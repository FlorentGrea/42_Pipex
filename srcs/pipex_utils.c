/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:13:42 by fgrea             #+#    #+#             */
/*   Updated: 2021/11/09 21:09:01 by fgrea            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	pipex_error(void)
{
	if (errno == 0)
		ft_putstr_fd("Wrong arguments\n", 1);
	else
		perror(strerror(errno));
	exit(0);
}

char	*pipex_cut_commands(char *av)
{
	int	i;

	i = 0;
	while (av[i] && av[i] != ' ')
		i++;
	if (av[i])
		av = ft_substr(av, 0, i);
	if (av == NULL)
		pipex_error();
	return (av);
}

char	*pipex_find_path(char *av, char **path_env)
{
	char	*tmp;
	char	*tmp2;

	av = pipex_cut_commands(av);
	if (av && *av != '/')
	{
		while (*path_env)
		{
			tmp = ft_strjoin(*path_env++, "/");
			if (tmp == NULL)
				pipex_error();
			tmp2 = ft_strjoin(tmp, av);
			free(tmp);
			tmp = NULL;
			if (tmp2 == NULL)
				pipex_error();
			if (!access(tmp2, F_OK))
				return (tmp2);
			free(tmp2);
			tmp2 = NULL;
		}
	}
	else if (!access(av, F_OK))
		return (av);
	return (NULL);
}
