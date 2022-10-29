/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:53:46 by kadjane           #+#    #+#             */
/*   Updated: 2022/10/29 18:35:16 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	get_time()
{
	int				time;
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	time = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
	return (time);
}

void	eat(t_philo *philosopher)
{
	pthread_mutex_lock(&(philosopher->data->forks[philosopher->id - 1]));

	pthread_mutex_lock(&(philosopher->data->print));
	printf("\033[91m%d %d take the left fork\033[00m \n",get_time() - philosopher->start_time, philosopher->id);
	pthread_mutex_unlock(&(philosopher->data->print));
	
	pthread_mutex_lock(&(philosopher->data->forks[(philosopher->id)
						% philosopher->data->nbr_of_philo]));
						
	pthread_mutex_lock(&(philosopher->data->print));
	printf("\033[91m%d %d take the right fork\033[00m\n\n",get_time() - philosopher->start_time, philosopher->id);
	pthread_mutex_unlock(&(philosopher->data->print));
	
	pthread_mutex_lock(&(philosopher->data->print));
	printf("\033[92m%d %d is eating\033[00m\n\n", get_time() - philosopher->start_time, philosopher->id);
	pthread_mutex_unlock(&(philosopher->data->print));
	
	ft_usleep((philosopher->data->time_to_eat) * 1000);
	
	pthread_mutex_unlock(&(philosopher->data->forks[philosopher->id - 1]));
	pthread_mutex_unlock(&(philosopher->data->forks[(philosopher->id)
						% philosopher->data->nbr_of_philo]));
}

void	ft_sleep_think(t_philo *philosopher)
{
	pthread_mutex_lock(&(philosopher->data->print));
	printf("\033[94m%d %d is sleeping\033[00m\n", get_time() - philosopher->start_time, philosopher->id);
	ft_usleep((philosopher->data->time_to_sleep) * 1000);
	pthread_mutex_unlock(&(philosopher->data->print));

	pthread_mutex_lock(&(philosopher->data->print));
	printf("\033[93m%d %d is thinking\033[00m\n\n", get_time() - philosopher->start_time, philosopher->id);
	pthread_mutex_unlock(&(philosopher->data->print));
}

