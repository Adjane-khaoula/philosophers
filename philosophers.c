/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:35:24 by kadjane           #+#    #+#             */
/*   Updated: 2022/11/04 17:30:01 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


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

void	create_philosophers(t_philo *philosophers,t_data *data)
{
	int				i;
	struct timeval	current_time;

	i = -1;
	gettimeofday(&current_time, NULL);
	pthread_mutex_init(&(data->print), NULL);
	data->start_time = (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
	while (++i < data->nbr_of_philo)
	{
		pthread_mutex_init(&(philosophers[i].last_eat), NULL);
		pthread_mutex_init(&(philosophers[i].is_eat), NULL);
		pthread_mutex_init(&(philosophers[i].nbr_eat), NULL);
		pthread_mutex_init(&(data->forks[i]),NULL);
		philosophers[i].id = i + 1;
		philosophers[i].last_time_eat = 0;
		philosophers[i].eat = 0;
		philosophers[i].nbr_times_eat = 0;
		philosophers[i].data = data;
	}
	i = -1;
	while(++i < data->nbr_of_philo)
	{
		if (pthread_create(&(philosophers[i].philo), NULL, &routine, &(philosophers[i])) != 0)
			return ;
		usleep(50);
	}
}

void	init_data(char **av, t_data **data)
{
	
	(*data) = malloc(sizeof(t_data));
	(*data)->nbr_of_philo = ft_atoi(av[1]);
	(*data)->time_to_die = ft_atoi(av[2]);
	(*data)->time_to_eat = ft_atoi(av[3]);
	(*data)->time_to_sleep = ft_atoi(av[4]);
	(*data)->nbr_time_each_philo_eat = ft_atoi(av[5]);
	(*data)->forks = malloc(sizeof(pthread_mutex_t) * (*data)->nbr_of_philo);
}

int	main(int ac, char **av)
{
	t_data	*data;
	t_philo	*philosophers;
	int		i;
	
	data = NULL;
	if (ac == 6)
	{
		while (--ac)
		{
			if (ft_atoi(av [ac]) == -1)
			{
				ft_putstr("check you parameters");
				return(0);
			}
		}
		init_data(av,&data);
		// data = malloc(sizeof(t_data));
		// data->nbr_of_philo= ft_atoi(av[1]);
		// data->time_to_die = ft_atoi(av[2]);
		// data->time_to_eat = ft_atoi(av[3]);
		// data->time_to_sleep = ft_atoi(av[4]);
		// data->nbr_time_each_philo_eat = ft_atoi(av[5]);
		philosophers = malloc(sizeof(t_philo) * (data->nbr_of_philo));
		// data->forks = malloc(sizeof(pthread_mutex_t) * data->nbr_of_philo);
		create_philosophers(philosophers, data);
		while (1)
		{
			i = -1;
			while(++i < data->nbr_of_philo)
			{
				pthread_mutex_lock(&(philosophers[i].last_eat));
				pthread_mutex_lock(&(philosophers[i].is_eat));
				pthread_mutex_lock(&(philosophers[i].nbr_eat));
				if(((get_time(data) - philosophers[i].last_time_eat) > data->time_to_die
					&& philosophers[i].eat == 0)
					|| philosophers[i].nbr_times_eat >= data->nbr_time_each_philo_eat)
				{
					pthread_mutex_lock(&(data->print));
					printf("%d %d died\n",get_time(data),philosophers[i].id);
					return (0);
				}
				pthread_mutex_unlock(&(philosophers[i].last_eat));
				pthread_mutex_unlock(&(philosophers[i].is_eat));
				pthread_mutex_unlock(&(philosophers[i].nbr_eat));
			}
		}
	}
	else
	{
		ft_putstr("check you parameters");
		return (0);
	}
	i = -1;
	while(++i < data->nbr_of_philo)
	{
		if(pthread_join(philosophers[i].philo, NULL) !=0)
			return (0) ;
	}
}