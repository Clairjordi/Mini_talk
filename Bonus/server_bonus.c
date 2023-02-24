/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:10:32 by clorcery          #+#    #+#             */
/*   Updated: 2022/08/09 11:59:22 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk_bonus.h"

static int	g_pid_client = 0;

static int	print_str(int tmp)
{
	static char	*tab;
	char		c;
	static int	i = 0;

	if (!tab)
		tab = malloc_tab(tmp);
	else
	{
		c = tmp;
		tab[i] = c;
		if (c == 0)
		{
			ft_printf("%s\n", tab);
			free(tab);
			tab = NULL;
			i = 0;
			kill(g_pid_client, SIGUSR1);
			g_pid_client = 0;
			return (0);
		}
		i++;
	}
	return (2);
}

static void	recup_char(int sig, int *ptr_tmp, int *ptr_count, int *ptr_j)
{
	if (*ptr_count < 7)
	{
		if (sig == SIGUSR1)
			*ptr_tmp = (*ptr_tmp + 1);
		*ptr_tmp <<= 1;
		(*ptr_count)++;
	}
	else if (*ptr_count == 7)
	{
		if (sig == SIGUSR1)
			*ptr_tmp = (*ptr_tmp + 1);
		*ptr_j = print_str(*ptr_tmp);
		*ptr_count = 0;
		*ptr_tmp = 0;
	}
}

static void	recup_len(int sig, int *ptr_tmp, int *ptr_count, int *ptr_j)
{
	if (*ptr_count < 31)
	{
		if (sig == SIGUSR1)
			*ptr_tmp = (*ptr_tmp + 1);
		*ptr_tmp <<= 1;
		(*ptr_count)++;
	}
	else if (*ptr_count == 31)
	{
		if (sig == SIGUSR1)
			*ptr_tmp = (*ptr_tmp + 1);
		print_str(*ptr_tmp);
		*ptr_tmp = 0;
		*ptr_count = 0;
		*ptr_j = 2;
	}
}

static void	handler(int sig)
{
	static int	tmp = 0;
	static int	count = 0;
	static int	j = 0;

	if (j == 0)
	{
		if (count < 31)
		{
			if (sig == SIGUSR1)
				g_pid_client = (g_pid_client + 1);
			g_pid_client <<= 1;
			count++;
		}
		else if (count == 31)
		{
			if (sig == SIGUSR1)
				g_pid_client = (g_pid_client + 1);
			count = 0;
			j = 1;
		}
	}
	else if (j == 1)
		recup_len(sig, &tmp, &count, &j);
	else
		recup_char(sig, &tmp, &count, &j);
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("%d\n", pid);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		continue ;
	return (0);
}
