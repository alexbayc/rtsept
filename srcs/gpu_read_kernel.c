/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gpu_read_kernel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 15:31:07 by odale-dr          #+#    #+#             */
/*   Updated: 2019/09/21 16:30:37 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int						print_error(t_gpu *gpu)
{
	size_t				len;
	char				*b;
	cl_program			p;
	cl_device_id		d;

	p = gpu->program;
	d = gpu->device_id;
	if (gpu->err != CL_SUCCESS)
	{
		b = ft_strnew(99999);
		clGetProgramBuildInfo(p, d, CL_PROGRAM_BUILD_LOG, 100000, b, &len);
		printf("%s\n", b);
		ft_strdel(&b);
		return (EXIT_FAILURE);
	}
	return (0);
}

int						gpu_read_kernel(t_gpu *gpu)
{
	char				ch;
	int					fd;
	char				*line;
	size_t				len;
	char				*buffer;

	fd = open("srcs/cl_files/main.cl", O_RDONLY);
	if (fd < 0)
		exit(EXIT_FAILURE);
	gpu->kernel_source = ft_strnew(0);
	while (get_next_line(fd, &line) > 0)
	{
		line = ft_strjoin(line, "\n");
		gpu->kernel_source = ft_strjoin(gpu->kernel_source, line);
		ft_strdel(&line);
	}
	close(fd);
	gpu->program = clCreateProgramWithSource(gpu->context, 1,
					(const char **)&gpu->kernel_source, NULL, &gpu->err);
	gpu->err = clBuildProgram(gpu->program, 0, NULL,
					" -I includes/cl_headers/ -I srcs/cl_files", NULL, NULL);
	print_error(gpu);
	return (0);
}
