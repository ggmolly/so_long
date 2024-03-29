/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:36:06 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/25 15:20:20 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# define BUFFER_SIZE 32767

unsigned char	*read_n_bytes(char *path, size_t n);
char			*ft_read_file(char *path);
int				ft_file_size(int fd);
#endif