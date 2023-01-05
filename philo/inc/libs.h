/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:52:05 by psegura-          #+#    #+#             */
/*   Updated: 2023/01/05 11:38:06 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBS_H
# define LIBS_H

//Write, Read, Usleep
# include <unistd.h>

//Gettimeofday
# include <sys/time.h>

/*
Pthread_create, Pthread_detach, Pthread_joi
Pthread_mutex_init, Pthread_mutex_destroy
Pthread_mutex_lock, Pthread_mutex_unlock
*/
# include <pthread.h>

//Printf
# include <stdio.h>

//Memset
# include <string.h>

//Malloc, Free, Exit
# include <stdlib.h>

#endif
