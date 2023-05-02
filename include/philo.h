/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:57:05 by jlaiti            #+#    #+#             */
/*   Updated: 2023/05/02 15:49:38 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>

typedef struct s_args
{
	int	nb_philo;
	int	nb_forks;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	nb_of_loop_philo;
}			t_args;

typedef struct s_table
{
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	mutex_stop;
	pthread_mutex_t	mutex_die;
	int				stop;
	int				philo_loop;
}				t_table;

typedef struct s_philo
{
	int				nb_philo;
	int				id;
	int				time_to_eat;
	int				time_to_sleep;
	int				philo_alive;
	pthread_t		philo_thread;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*local_mutex;
	int				last_meal;
	int				nb_of_eat;
	t_table			*table;
}				t_philo;

typedef struct s_data
{
	t_philo	*philo;
	t_table	*table;
}				t_data;

t_data		*manage_philo(t_args	*args);
int			parse_args(char **argv, t_args *args, int argc);
void		execute_philo(t_data *data);
int			check_is_alive(int *var, pthread_mutex_t *mutex_stop);
void		activity(t_philo *philo, t_table *table);	
int			change_status(int *var, int new_var, pthread_mutex_t *mutex_stop);

//utils
int			ft_error(char *str);
void		ft_puchar_fd(char c, int fd);
void		ft_putstr_fd(char *str, int fd);
int			ft_atoi(char *str);
int			get_time(void);
void		custom_sleep(int time, t_table *table);
void		print_msg(int time, char *msg, t_philo *philo, t_table *table);
void		*handle_philo(void *arg);
void		destroy_all(t_data *data);

#endif
