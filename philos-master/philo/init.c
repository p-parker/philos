/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmellahi <hmellahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 23:41:44 by hamza             #+#    #+#             */
/*   Updated: 2021/10/03 19:20:30 by hmellahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_0.h"

void	init_state(t_state *state, t_string *av, int ac)
{
	state->count = ft_atoi(av[1]);
	state->die_time = ft_atoi(av[2]);
	state->eat_time = ft_atoi(av[3]);
	state->sleep_time = ft_atoi(av[4]);
	if (ac == 6)
		state->n_must_eat = ft_atoi(av[5]);
	else
		state->n_must_eat = -1;
	state->forks = malloc(sizeof(pthread_mutex_t) * state->count);
}

void	init(int ac, char **av, t_state *state, t_philo **philos)
{
	int	i;

	init_state(state, av, ac);
	pthread_mutex_init(&state->print_mutex, NULL);
	i = -1;
	while (++i < state->count)
		pthread_mutex_init(&state->forks[i], NULL);
	*philos = malloc(sizeof(t_philo) * state->count);
	i = -1;
	state->start_time = get_time();
	while (++i < state->count)
	{
		(*philos)[i].state = state;
		(*philos)[i].status = THINKING;
		(*philos)[i].index = i;
		(*philos)[i].eat_count = 0;
		pthread_mutex_init(&(*philos)[i].eat_mutex, NULL);
		(*philos)[i].last_time_eat = state->start_time;
	}
}
