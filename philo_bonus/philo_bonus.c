/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 00:18:15 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/08/24 23:23:36 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	parser(int ac, char **av)
{
	t_data	st;

	if (checker(ac, av))
	{
		write (2, "some thing wrong in the args\n", 29);
		how_to_use();
		return (1);
	}
	st.philo_n = my_atoi(av[1]);
	st.time_2_die = my_atoi(av[2]);
	st.time_2_eat = my_atoi(av[3]);
	st.time_2_sleep = my_atoi(av[4]);
	if (ac == 6)
		st.eat_n = my_atoi(av[5]);
	else
		st.eat_n = -1;
	if (!st.eat_n || !st.philo_n)
		return (0);
	if (st.time_2_die == -1
		|| st.time_2_eat == -1 || st.time_2_sleep == -1)
		return (write(2, "some thing wrong in the args\n", 29)
			, how_to_use(), 1);
	return (initializing_philos(&st));
}

int	main(int ac, char **av)
{
	if (ac < 5 || ac > 6)
	{
		write(2, "invalid number of args\n", 23);
		how_to_use();
		return (1);
	}
	if (parser(ac, av))
		return (1);
	return (0);
}

int	check_meals(t_philo *philo, t_data *st)
{
	sem_wait(philo->meals_n_);
	if (philo->meals_n <= st->eat_n)
		return (sem_post(philo->meals_n_), 1);
	sem_post(philo->meals_n_);
	sem_wait(st->die);
	sem_post(st->die_2);
	return (0);
}

void	wait_death(t_data *st, t_philo *philo)
{
	sem_wait(st->start);
	while (1)
	{
		if (st->eat_n != -1
			&& !check_meals(st->s_philo, st))
			return ;
		sem_wait(philo->last_meal_);
		if (get_time() - philo->last_meal > (size_t)st->time_2_die)
		{
			sem_wait(st->die);
			printf("%lu %d died\n", get_time() - st->time, philo->index);
			sem_post(st->die_2);
			sem_post(philo->last_meal_);
			return ;
		}
		sem_post(philo->last_meal_);
	}
}
