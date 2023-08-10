/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:04:53 by fgrea             #+#    #+#             */
/*   Updated: 2021/11/09 21:08:42 by fgrea            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

char	**pipex_get_path_env(char **env)
{
	char	**path_env;

	while (*env && ft_strncmp(*env, "PATH=", 5) != 0)
		env++;
	if (!*env)
		return (NULL);
	path_env = ft_split(((*env) + 5), ':');
	return (path_env);
}

void	pipex_verif(int ac, char **av)
{
	int	fd[2];

	if (ac < 5)
		pipex_error();
	fd[0] = open(av[1], O_DIRECTORY);
	fd[1] = open(av[ac - 1], O_DIRECTORY);
	if (fd[0] != -1 || fd[1] != -1)
		pipex_error();
	close(fd[0]);
	close(fd[1]);
	fd[0] = open(av[1], O_RDONLY);
	if (fd[0] < 0)
		pipex_error();
	close(fd[0]);
}

int	main(int ac, char **av, char **env)
{
	char	**path_env;
	t_data	data;

	pipex_verif(ac, av);
	data.ac = ac;
	data.av = av;
	path_env = pipex_get_path_env(env);
	pipex_launcher(data, path_env);
	return (0);
}
