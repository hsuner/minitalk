/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsuner <hsuner@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:50:03 by hsuner            #+#    #+#             */
/*   Updated: 2023/09/12 16:50:15 by hsuner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include <signal.h>
#include <unistd.h>

void	take_sgn(int sig)
{
	static unsigned char	c = 0;
	static int				i = 128;

	if (sig == SIGUSR1)
		c += i;
	i /= 2;
	if (i == 0)
	{
		write(1, &c, 1);
		c = 0;
		i = 128;
	}
}

int	main(void)
{
	ft_printf("Server PID: %d\n", getpid());
	signal(SIGUSR1, take_sgn);
	signal(SIGUSR2, take_sgn);
	while (1)
		pause();
}
