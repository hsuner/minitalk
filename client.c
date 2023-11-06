/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsuner <hsuner@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 05:04:45 by hsuner            #+#    #+#             */
/*   Updated: 2023/10/04 16:33:27 by hsuner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

int	ft_atoi(char *pid)
{
	int	result;

	result = 0;
	while (*pid)
		result = (result * 10) + *pid++ - '0';
	return (result);
}

void	get_binary(int pid, char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 8;
		while (j--)
		{
			usleep(50);
			if ((str[i] >> j) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
		}
		i++;
	}
}

int	main(int c, char **v)
{
	int	pid;

	if (c != 3)
		return (0);
	pid = ft_atoi(v[1]);
	get_binary(pid, v[2]);
	return (0);
}
