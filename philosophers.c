/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:35:24 by kadjane           #+#    #+#             */
/*   Updated: 2022/11/05 22:17:12 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_data(int ac, char **av, t_data **data)
{
	(*data) = malloc(sizeof(t_data));
	(*data)->nbr_of_philo = ft_atoi(av[1]);
	(*data)->time_to_die = ft_atoi(av[2]);
	(*data)->time_to_eat = ft_atoi(av[3]);
	(*data)->time_to_sleep = ft_atoi(av[4]);
	if (ac == 5)
		(*data)->nbr_time_each_philo_eat = -1;
	else
		(*data)->nbr_time_each_philo_eat = ft_atoi(av[5]);
	(*data)->ac = ac;
	(*data)->forks = malloc(sizeof(pthread_mutex_t) * (*data)->nbr_of_philo);
}

int	ft_error(int ac, char **av)
{
	while (--ac)
	{
		if (ft_atoi(av[ac]) == -1)
		{
			ft_putstr("check you parameters");
			return(1);
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*data;
	t_philo	*philosophers;
	
	data = NULL;
	if (ac == 5 || ac == 6)
	{
		if(ft_error(ac, av) == 1)
			return (0);
		init_data(ac, av, &data);
		philosophers = malloc(sizeof(t_philo) * (data->nbr_of_philo));
		create_philosophers(philosophers, data);
		while (1)
		{
			if(ft_die(data, philosophers) == 1)
				return(0);
		}
	}
	else
	{
		ft_putstr("check you parameters");
		return (0);
	}
}