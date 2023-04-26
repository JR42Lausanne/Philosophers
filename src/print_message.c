/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:59:40 by jlaiti            #+#    #+#             */
/*   Updated: 2023/04/26 12:10:51 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <pthread.h>
#include <stdio.h>

void	print_msg(int time, char *msg, t_philo *philo, t_table *table)
{
	if (!check_is_alive(&table->stop, &table->is_alive))
	{
		if (pthread_mutex_lock(&table->write_mutex) == -1)
			return ;
		printf("%d: philosopher %d - %s", time - philo->start_time,
			philo->id, msg);
		if (pthread_mutex_unlock(&table->write_mutex) == -1)
			return ;
	}	
}
