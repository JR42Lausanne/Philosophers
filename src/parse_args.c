/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:01:50 by jlaiti            #+#    #+#             */
/*   Updated: 2023/04/04 11:39:38 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	is_number(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	parse_args(char **argv, t_args *args)
{
	if (is_number(argv))
	{
		args->nb_philo = ft_atoi(argv[1]);
		args->time_to_die = ft_atoi(argv[2]);
		args->time_to_eat = ft_atoi(argv[3]);
		args->time_to_sleep = ft_atoi(argv[4]);
		args->nb_of_loop_philo = ft_atoi(argv[5]);
	}
	return (0);
}	
