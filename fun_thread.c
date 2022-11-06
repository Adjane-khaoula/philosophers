/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_thread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 18:15:27 by kadjane           #+#    #+#             */
/*   Updated: 2022/11/06 04:53:40 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	create_philosophers(t_philo *philosophers, t_data *data)
{
	int	i;

	i = -1;
	pthread_mutex_init(&(data->print), NULL);
	while (++i < data->nbr_of_philo)
	{
		pthread_mutex_init(&(philosophers[i].last_eat), NULL);
		pthread_mutex_init(&(philosophers[i].is_eat), NULL);
		pthread_mutex_init(&(philosophers[i].nbr_eat), NULL);
		pthread_mutex_init(&(data->forks[i]), NULL);
		philosophers[i].id = i + 1;
		philosophers[i].last_time_eat = 0;
		philosophers[i].eat = 0;
		philosophers[i].nbr_times_eat = 0;
		philosophers[i].data = data;
	}
	i = -1;
	while (++i < data->nbr_of_philo)
	{
		if (pthread_create(&(philosophers[i].philo), NULL, &routine,
				&(philosophers[i])) != 0)
			return ;
		usleep(100);
	}
}

void	ft_join(t_data *data, t_philo *philosophers)
{
	int	i;
	
	i = -1;
	while(++i < data->nbr_of_philo)
	{
		if(pthread_join(philosophers[i].philo, NULL) !=0)
			return ;
	}
}

int	ft_die(t_data *data, t_philo *philosophers)
{
	int	i;
	
	i = -1;
	while(++i < data->nbr_of_philo)
	{
		pthread_mutex_lock(&(philosophers[i].last_eat));
		pthread_mutex_lock(&(philosophers[i].is_eat));
		pthread_mutex_lock(&(philosophers[i].nbr_eat));
		if(((get_time(data) - philosophers[i].last_time_eat) > data->time_to_die
			&& philosophers[i].eat == 0)
			||( philosophers[i].nbr_times_eat >= data->nbr_time_each_philo_eat
			&& data->nbr_time_each_philo_eat != -1))
		{
			pthread_mutex_lock(&(data->print));
			printf("%d %d died\n",get_time(data),philosophers[i].id);
			return (1);
		}
		pthread_mutex_unlock(&(philosophers[i].last_eat));
		pthread_mutex_unlock(&(philosophers[i].is_eat));
		pthread_mutex_unlock(&(philosophers[i].nbr_eat));
	}
	return(0);
}

void	*routine(void *philosophers)
{
	t_philo	*philosopher;

	philosopher = (t_philo *)philosophers;
	while(1)
	{
		eat(philosopher);
		ft_sleep_think(philosopher);
		
	}
	return(0);
}
