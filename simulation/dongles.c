/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrajaon <nyrajaon@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 08:45:40 by nyrajaon          #+#    #+#             */
/*   Updated: 2026/09/21 09:56:17 by nyrajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	take_dongles(t_coder *coder)
{
	pthread_mutex_lock(
		&coder->sim->dongles[coder->left_dongle].mutex);
	printf("Coder %d took dongle %d\n",
		coder->id, coder->left_dongle);
	pthread_mutex_lock(
		&coder->sim->dongles[coder->right_dongle].mutex);
	printf("Coder %d took dongle %d\n",
		coder->id, coder->right_dongle);
}

void	release_dongles(t_coder *coder)
{
	pthread_mutex_unlock(
		&coder->sim->dongles[coder->left_dongle].mutex);
	pthread_mutex_unlock(
		&coder->sim->dongles[coder->right_dongle].mutex);
}
