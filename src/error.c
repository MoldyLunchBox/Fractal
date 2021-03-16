/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amya <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 05:59:05 by amya              #+#    #+#             */
/*   Updated: 2020/01/09 00:37:23 by amya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/frog_tol.h"

void	print_error(char **av, int ac)
{
	if (ac != 2)
	{
		ft_putstr("usage: ./fractol X\nX = from 0 to 10");
		exit(0);
	}
	if (ft_atoi(av[1]) < 0 || ft_atoi(av[1]) > 10 || av[1][1] != '\0')
	{
		ft_putstr("usage: ./fractol X\nX = from 0 to 10");
		exit(0);
	}
}
