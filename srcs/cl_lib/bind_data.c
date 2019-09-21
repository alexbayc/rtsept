/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bind_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 16:39:54 by odale-dr          #+#    #+#             */
/*   Updated: 2019/09/21 17:15:52 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int					bind_data(t_gpu *gpu, t_main_obj *main)
{
	int data_size = sizeof(t_vec3) * WIN_W * WIN_H;
	int w = WIN_W; 
	int h = WIN_H;
	size_t global = WIN_W * WIN_H;
	const int count = global;
	const int n_spheres = quan_of_obj(gpu->f);
	int i;
	int j;
	static t_vec3 *h_a;
	gpu->vec_temp = ft_memalloc(sizeof(cl_float3) * global);
	gpu->camera = camera_new(WIN_W, WIN_H);
	gpu->cl_cpu_vectemp = clCreateBuffer(gpu->context, CL_MEM_READ_WRITE, count * sizeof(cl_float3), NULL, &gpu->err);
	gpu->cl_bufferOut = clCreateBuffer(gpu->context, CL_MEM_WRITE_ONLY, count * sizeof(cl_int), NULL, &gpu->err);
	gpu->cl_cpuSpheres= clCreateBuffer(gpu->context, CL_MEM_READ_ONLY, n_spheres * sizeof(t_obj), NULL, &gpu->err);
	gpu->err = clEnqueueWriteBuffer(gpu->commands, gpu->cl_cpuSpheres, CL_TRUE, 0,
			n_spheres * sizeof(t_obj), gpu->spheres, 0, NULL, NULL);
	gpu->err |= clSetKernelArg(gpu->kernel, 0, sizeof(cl_mem), &gpu->cl_bufferOut);
	gpu->err |= clSetKernelArg(gpu->kernel, 1, sizeof(cl_int), &w);
	gpu->err |= clSetKernelArg(gpu->kernel, 2, sizeof(cl_int), &h);
	gpu->err |= clSetKernelArg(gpu->kernel, 3, sizeof(cl_int), &n_spheres);
	gpu->err |= clSetKernelArg(gpu->kernel, 4, sizeof(cl_mem), &gpu->cl_cpuSpheres);
	gpu->err |= clSetKernelArg(gpu->kernel, 5, sizeof(cl_mem), &gpu->cl_cpu_vectemp);
	gpu->err |= clSetKernelArg(gpu->kernel, 6, sizeof(cl_int), &gpu->samples);

	BLURT;
	return (0);
}