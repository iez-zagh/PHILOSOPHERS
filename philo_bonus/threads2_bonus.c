/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:03:07 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/08/21 20:59:52 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	print(t_data *st, t_philo *philo, char *msg)
{
	if (st->die)
		return (1);
	printf("%lu %d %s\n", get_time() - st->time, philo->index, msg);
	return (0);
}

int	sleep_think(t_data *st, t_philo *philo)
{
	
	philo->meals_n++;
	
	if (print(st, philo, SLEEP))
		return (1);
	ft_usleep(st->time_2_sleep);
	if (print(st, philo, THINK))
		return (1);
	return (0);
}

void	*true_routine(t_data *st, t_philo *philo)
{
	while (1)
	{
		
		if (print(st, philo, FORK))
			return (NULL);
		if (st->philo_n == 1)
			return (NULL);
		if (print(st, philo, FORK))
			return (NULL);
		if (print(st, philo, EAT))
			return (NULL);

		philo->last_meal = get_time();

		ft_usleep(st->time_2_eat);
		//let the semaphore
		if (sleep_think(st, philo))
			return (NULL);
	}
}

void	*routine(void *arg)
{
	t_philo	*philo;
	t_data	*st;

	philo = NULL;
	st = (t_data *)arg;
	if (!true_routine(st, philo))
		return (NULL);
	return (NULL);
}
