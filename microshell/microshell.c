/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:59:44 by juzheng           #+#    #+#             */
/*   Updated: 2023/10/09 15:59:46 by juzheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

int	exec(char **argv, char **envp, int i)
{
	execve(*argv, argv, envp);
}

int	main(int argc, char **argv, char **envp)
{
	int	i = 0;
	int	status = 0;

	if (argc > 1)
	{
		while (argv[i] && argv[++i])
		{
			argv += i;
			i = 0;
			while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
				i++;
			
			status = exec(argv, envp, i);
		}
	}
	return status;
}
