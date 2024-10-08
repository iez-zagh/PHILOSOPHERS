/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads3_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:48:35 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/08/24 23:10:47 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	check_death(t_data *st, int n, t_philo *philo)
{
	int	i;

	i = 0;
	sem_wait(st->die_2);
	while (i < n)
	{
		sem_close(philo->last_meal_);
		sem_close(philo->meals_n_);
		sem_unlink("/meals_n");
		sem_unlink("/last_meal");
		kill(philo->pid, SIGKILL);
		i++;
		philo = philo->next;
	}
	sem_close(st->forks);
	sem_close(st->die);
	sem_close(st->die_2);
	sem_close(st->start);
	sem_unlink("/sema2");
	sem_unlink("/start");
	sem_unlink("/kill");
	sem_unlink("/print");
	ft_free(st);
}

int	create_philos(t_data *st)
{
	t_philo		*philo;
	int			i ;
	int			n;

	42 && (philo = st->s_philo, i = 0, n = st->philo_n);
	st->index = 0;
	st->time = get_time();
	sem_wait(st->start);
	while (i++ < n)
	{
		philo->last_meal = get_time();
		philo->pid = fork();
		if (!philo->pid)
			routine(st, philo);
		else
		{
			philo = philo->next;
			st->index++;
		}
	}
	sem_post(st->start);
	check_death(st, n, philo);
	return (0);
}
