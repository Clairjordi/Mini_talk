/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 21:05:56 by clorcery          #+#    #+#             */
/*   Updated: 2022/09/03 15:30:55 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

char	*malloc_tab(int tmp)
{
	char	*tab;

	tab = malloc (sizeof(char) * (tmp + 1));
	if (!tab)
	{
		ft_putendl_fd("Malloc error", 2);
		exit (1);
	}
	return (tab);
}
