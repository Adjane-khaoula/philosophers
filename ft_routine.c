/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:53:46 by kadjane           #+#    #+#             */
/*   Updated: 2022/10/31 13:22:49 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	get_time(t_philo *philosopher)
{
	int				time;
	struct timeval	current_time;
	
	gettimeofday(&current_time, NULL);
	time = (current_time.tv_sec * 1000 + current_time.tv_usec / 1000)
			- philosopher->start_time;
	return (time);
}

void	ft_usleep(int time, t_philo *philosopher)
{
	int	current_time;

	int time_to_sleep;

	current_time = get_time(philosopher);
	time_to_sleep = current_time + time;
	while(current_time < time_to_sleep)
	{
		current_time = get_time(philosopher);
		usleep(150);
	}
}

void	eat(t_philo *philosopher)
{

	pthread_mutex_lock(&(philosopher->data->forks[philosopher->id - 1]));

	pthread_mutex_lock(&(philosopher->data->print));
	printf("\033[91m%d %d has taken a fork\033[00m \n",get_time(philosopher), philosopher->id);
	pthread_mutex_unlock(&(philosopher->data->print));
	
	pthread_mutex_lock(&(philosopher->data->forks[(philosopher->id)
						% philosopher->data->nbr_of_philo]));
						
	pthread_mutex_lock(&(philosopher->data->print));
	printf("\033[91m%d %d has taken a fork\033[00m\n\n",get_time(philosopher), philosopher->id);
	pthread_mutex_unlock(&(philosopher->data->print));
	
	pthread_mutex_lock(&(philosopher->data->print));
	printf("\033[92m%d %d is eating\033[00m\n\n", get_time(philosopher), philosopher->id);
	pthread_mutex_unlock(&(philosopher->data->print));
	ft_usleep((philosopher->data->time_to_eat), philosopher);
	pthread_mutex_unlock(&(philosopher->data->forks[philosopher->id - 1]));
	pthread_mutex_unlock(&(philosopher->data->forks[(philosopher->id)
						% philosopher->data->nbr_of_philo]));
}

void	ft_sleep_think(t_philo *philosopher)
{
	pthread_mutex_lock(&(philosopher->data->print));
	printf("\033[94m%d %d is sleeping\033[00m\n", get_time(philosopher), philosopher->id);
	pthread_mutex_unlock(&(philosopher->data->print));
	ft_usleep((philosopher->data->time_to_sleep), philosopher);

	pthread_mutex_lock(&(philosopher->data->print));
	printf("\033[93m%d %d is thinking\033[00m\n\n", get_time(philosopher), philosopher->id);
	pthread_mutex_unlock(&(philosopher->data->print));
}
