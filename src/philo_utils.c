/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:24:37 by jlaiti            #+#    #+#             */
/*   Updated: 2023/04/26 15:10:10 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <unistd.h>
#include <sys/time.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = -1;
	while (str[++i])
		ft_putchar_fd(str[i], fd);
}

int	ft_atoi(char *str)
{
	int		i;
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 8 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if ((res * sign > INTMAX || res * sign < INTMIN)
		|| (res <= 0))
		ft_error("invalid argument");
	return (res * sign);
}

int	get_time(void)
{
	struct timeval	tv;
	static long int	start_time;
	long int		current_time;

	if (gettimeofday(&tv, NULL) == -1)
		return (-1);
	if (start_time == 0)
	{
		start_time = tv.tv_sec * 1000;
		start_time += tv.tv_usec / 1000;
	}
	else
	{
		current_time = tv.tv_sec * 1000;
		current_time += tv.tv_usec / 1000;
		return ((int)(current_time - start_time));
	}
	return (start_time);
}

void	custom_sleep(int time, t_table *table)
{
	int	start_time;

	start_time = get_time();
	while (!check_is_alive(&table->stop, &table->mutex)
		&& (get_time() - start_time < time))
	{
		usleep(time / 10);
	}
	return ;
}
