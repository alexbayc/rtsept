/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gpu_init2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 14:49:41 by odale-dr          #+#    #+#             */
/*   Updated: 2019/09/21 18:30:01 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void					release_gpu(t_gpu *gpu)
{
	clReleaseProgram(gpu->program);
	clReleaseKernel(gpu->kernel);
	clReleaseCommandQueue(gpu->commands);
	clReleaseContext(gpu->context);
	clReleaseMemObject(gpu->cl_bufferOut);
	clReleaseMemObject(gpu->cl_cpuSpheres);
}

void					ft_run_gpu(t_gpu *gpu)
{
	size_t				global;
	const int			count = WIN_W * WIN_H;

	global = WIN_W * WIN_H;
	gpu->samples += 15;
	gpu->err |= clSetKernelArg(gpu->kernel, 6, sizeof(cl_int), &gpu->samples);
	gpu->err = clEnqueueNDRangeKernel(gpu->commands, gpu->kernel,
				1, NULL, &global, NULL, 0, NULL, NULL);
	gpu->err = clEnqueueReadBuffer(gpu->commands, gpu->cl_bufferOut, CL_TRUE, 0,
				count * sizeof(cl_int), gpu->cpuOutput, 0, NULL, NULL);
}

int						gpu_control(t_gpu *gpu)
{
	gpu->context = clCreateContext(0, 1,
					&gpu->device_id, NULL, NULL, &gpu->err);
	gpu->commands = clCreateCommandQueue(gpu->context,
					gpu->device_id, 0, &gpu->err);
	gpu_read_kernel(gpu);
	gpu->kernel = clCreateKernel(gpu->program, "render_kernel", &gpu->err);
	if ((gpu->cpuOutput = malloc(sizeof(int) * (WIN_H * WIN_H))) == NULL)
		return (0);
	if ((gpu->spheres = malloc(sizeof(t_obj) * quan_of_obj(gpu->f))) == NULL)
		return (0);
	gpu->samples = 0;
	return (1);
}

int						opencl_init3(t_gpu *gpu, t_game *game)
{
	int					i;
	cl_platform_id		pl[gpu->numPlatforms];

	i = -1;
	gpu->err = clGetPlatformIDs(gpu->numPlatforms, pl, NULL);
	while (++i < gpu->numPlatforms)
	{
		gpu->err = clGetDeviceIDs(pl[i], DEVICE, 1, &gpu->device_id, NULL);
		if (gpu->err == CL_SUCCESS)
			break ;
	}
	if (gpu->device_id == NULL)
		return (1);
	if (gpu_control(gpu) == 0)
		return (1);
	initscene2(gpu->spheres, quan_of_obj(gpu->f), gpu->f);
	bind_data(gpu, &game->main_objs);
	return (gpu->err);
}

int						opencl_init2(t_gpu *gpu, t_game *game)
{
	int					i;

	gpu->err = clGetPlatformIDs(0, NULL, &gpu->numPlatforms);
	if (gpu->numPlatforms == 0)
		return (EXIT_FAILURE);
	i = opencl_init3(gpu, game);
	return (i);
}
