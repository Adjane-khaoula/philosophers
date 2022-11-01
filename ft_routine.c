/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:53:46 by kadjane           #+#    #+#             */
/*   Updated: 2022/11/02 00:40:59 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	get_time(t_data *data)
{
	int				time;
	struct timeval	current_time;
	
	gettimeofday(&current_time, NULL);
	time = (current_time.tv_sec * 1000 + current_time.tv_usec / 1000)
			- data->start_time;
	return (time);
}

void	ft_usleep(int time, t_philo *philosopher)
{
	int	current_time;

	int time_to_sleep;

	current_time = get_time(philosopher->data);
	time_to_sleep = current_time + time;
	while(current_time < time_to_sleep)
	{
		usleep(150);
		current_time = get_time(philosopher->data);
	}
}

void	eat(t_philo *philosopher)
{

	
	pthread_mutex_lock(&(philosopher->data->forks[philosopher->id - 1]));
	
	pthread_mutex_lock(&(philosopher->data->print));
	printf("\033[91m%d %d has taken a fork\033[00m \n",get_time(philosopher->data), philosopher->id);
	pthread_mutex_unlock(&(philosopher->data->print));
	
	pthread_mutex_lock(&(philosopher->data->forks[(philosopher->id)
						% philosopher->data->nbr_of_philo]));
	
	pthread_mutex_lock(&(philosopher->data->print));
	printf("\033[91m%d %d has taken a fork\033[00m\n\n",get_time(philosopher->data), philosopher->id);
	pthread_mutex_unlock(&(philosopher->data->print));
	
	pthread_mutex_lock(&(philosopher->data->last_eat));
	philosopher->last_time_eat = get_time(philosopher->data);
	philosopher->data->i = philosopher->id;
	pthread_mutex_unlock(&(philosopher->data->last_eat));
	
	// pthread_mutex_lock(&(philosopher->is_eat));
	philosopher->eat = 1;
	// pthread_mutex_unlock(&(philosopher->is_eat));

	pthread_mutex_lock(&(philosopher->data->print));
	printf("\033[92m%d %d is eating\033[00m\n\n", get_time(philosopher->data), philosopher->id);
	pthread_mutex_unlock(&(philosopher->data->print));
	
	ft_usleep((philosopher->data->time_to_eat), philosopher);
	
	philosopher->eat = 0;
	pthread_mutex_unlock(&(philosopher->data->forks[philosopher->id - 1]));
	pthread_mutex_unlock(&(philosopher->data->forks[(philosopher->id)
				% philosopher->data->nbr_of_philo]));
	// philosopher->eat = 0;
}

void	ft_sleep_think(t_philo *philosopher)
{
	pthread_mutex_lock(&(philosopher->data->print));
	printf("\033[94m%d %d is sleeping\033[00m\n", get_time(philosopher->data), philosopher->id);
	pthread_mutex_unlock(&(philosopher->data->print));
	ft_usleep((philosopher->data->time_to_sleep), philosopher);

	pthread_mutex_lock(&(philosopher->data->print));
	printf("\033[93m%d %d is thinking\033[00m\n\n", get_time(philosopher->data), philosopher->id);
	pthread_mutex_unlock(&(philosopher->data->print));
}
