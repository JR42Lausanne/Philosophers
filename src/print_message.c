/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:59:40 by jlaiti            #+#    #+#             */
/*   Updated: 2023/05/02 11:54:26 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <pthread.h>
#include <stdio.h>

void	print_msg(int time_ms, char *msg, t_philo *philo, t_table *table)
{
	static int	should_stop;

	(void) time_ms;
	if (!check_is_alive(&table->stop, &table->mutex_stop))
	{
		if (pthread_mutex_lock(&table->write_mutex) == -1)
			return ;
		if (!should_stop && msg[0] != 'A')
			printf("%d: philosopher %d - %s", get_time(),
			philo->id, msg);
		else if (msg[0] == 'A')
			printf("%s\n", msg);
		if (msg[0] == 'd' || msg[0] == 'A')
			should_stop = 1;
		if (pthread_mutex_unlock(&table->write_mutex) == -1)
			return ;
	}	
}
