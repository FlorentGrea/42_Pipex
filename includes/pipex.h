/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:03:24 by fgrea             #+#    #+#             */
/*   Updated: 2021/11/09 18:44:48 by fgrea            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <libft.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>

typedef struct s_data
{
	int		ac;
	char	**av;
}	t_data;

typedef struct s_child
{
	int		**fd;
	pid_t	*child;
	int		status;
}	t_child;

void	pipex_error(void);
char	*pipex_find_path(char *av, char **path_env);

void	pipex_launcher(t_data data, char **path_env);

#endif
