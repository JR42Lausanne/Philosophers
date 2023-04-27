/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:43:50 by jlaiti            #+#    #+#             */
/*   Updated: 2023/04/27 15:07:19 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <pthread.h>
#include <stdio.h>

void	*handle_philo(void *arg)
{
	t_data	*data;
	int		i;

	data = arg;
	while (!check_is_alive(&data->table->stop, &data->table->mutex))
	{
		i = 0;
		while (i < data->philo[0].nb_philo)
		{
			if (get_time() - data->philo[i].last_meal >= data->philo[i].philo_alive)
			{
				change_status(&data->table->stop, 1, &data->table->mutex);
			}	
			i++;
		}
	}
	return (NULL);
}
