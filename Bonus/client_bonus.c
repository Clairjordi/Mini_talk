/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:09:36 by clorcery          #+#    #+#             */
/*   Updated: 2022/08/09 12:00:35 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk_bonus.h"

static void	check_args(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac != 3)
		ft_error("there are too many or not enough arguments\n");
	while (av[1][i])
	{
		if (ft_isdigit(av[1][i]) == 0)
			ft_error("the first argument is invalid\n");
		i++;
	}
	if (ft_atoi(av[1]) < 1)
		ft_error("Invalid PID\n");
	if (av[2][0] == '\0')
		ft_error("the second argument is empty\n");
}

static void	send_int(int pid, int tmp)
{
	int	i;

	i = 31;
	while (i >= 0)
	{
		if (tmp >> i & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(1);
		i--;
	}
}

static void	send_arg(char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c >> i & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(1);
		i--;
	}
}

static void	handler_client(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_printf("message received\n");
		exit (0);
	}
}

int	main(int argc, char *argv[])
{
	int	pid;
	int	i;
	int	len;
	int	pid_client;

	i = 0;
	signal(SIGUSR1, handler_client);
	check_args(argc, argv);
	pid_client = getpid();
	pid = ft_atoi(argv[1]);
	len = ft_strlen(argv[2]);
	send_int(pid, pid_client);
	send_int(pid, len);
	while (argv[2][i] != '\0')
		send_arg(argv[2][i++], pid);
	send_arg(argv[2][i], pid);
	while (1)
		continue ;
	return (0);
}
