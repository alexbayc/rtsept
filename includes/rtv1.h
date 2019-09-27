#ifndef RTV1_H
#define RTV1_H

#define WIN_W 1000
#define WIN_H 700
#define CL_SILENCE_DEPRECATION
#include <sys/types.h>
#include "SDL2/SDL.h"
#include "libsdl.h"
#include "libft.h"
#include <fcntl.h>
#include <limits.h>
#include <float.h>
#include <math.h>
#include "cl_error.h"
#ifdef __APPLE__
#include <OpenCL/opencl.h>
#else
#include <Cl/cl.h>
#endif

#ifndef DEVICE
#define DEVICE CL_DEVICE_TYPE_DEFAULT
#endif
//#include "libmath.h"
# define DROUND(d)	ABS(d) < 0.00001 ? 0 : (d)
//#define float double
typedef enum e_figure {
	 SPHERE, CYLINDER, CONE, PLANE
	} t_type;

typedef struct s_vertex t_vertex;
typedef struct s_sector t_sector;
typedef struct s_object t_object;
typedef struct s_coord t_coord;
typedef	struct 	s_vec3 t_vec3;
typedef	struct 	s_vec4 t_vec4;



typedef struct Object{
	float radius;
	cl_float3 position;
	cl_float3 color;
	cl_float3 emission;
	cl_float3 v;
	t_type type;
	cl_float refraction;
	cl_float reflection;
	cl_float plane_d;
} t_obj;

typedef struct s_objpoint{
	t_obj		*fig;
	struct s_objpoint	*next;
	char		*s;
	int			start;
	int			end;
	char		**file;
} t_objpoint;



// typedef struct Sphere1
// {
//  cl_float radius;
//  cl_float dummy1;   
//  cl_float dummy2;
//  cl_float dummy3;
//  cl_float3 position;
//  cl_float3 color;
//  cl_float3 emission;
// } t_spher;

typedef	struct s_point3
{
	float x;
	float y;
	float z;
} t_point3;

struct 	s_vec3
{
	float x;
	float y;
	float z;
	float w;
};

struct 	s_vec4
{
	float x;
	float y;
	float z;
	float w;
};

typedef	struct s_normal3
{
	float x;
	float y;
	float z;
} t_normal3;

typedef struct 	s_mat3
{
	double matrix[3][3];
} t_mat3;

typedef struct 	s_mat4
{
	double matrix[4][4];
} t_mat4;

typedef struct s_p2d
{
	float x;
	float y;
} t_p2d;

typedef struct s_quaternion
{
	float s; //scalar
	t_vec3 v;
} t_quaternion;

typedef struct s_ray
{
	t_vec3 orig;
	t_vec3 dir;
	t_vec3 hit;
	double t;

} t_ray;

typedef struct	Material {
	t_vec3 diffuse_color;
	t_vec3 albendo;
	float specular_exponent;
	float refractive_index;
}				t_material;

typedef struct s_light {
	t_vec3 position;
	float intensity;
} t_light;

typedef struct s_lights {
	t_light *lights;
	//t_vector light;
	int number;
} t_lights;

typedef struct		s_triangle
{
	t_vec3		a;
	t_vec3		b;
	t_vec3		c;
	t_material material;
} t_triangle;

// struct s_object
// {
// 	void *object;
// 	double (*intersect)();
// 	t_vec3 (*get_normal)();
// }; 

struct s_object
{
	cl_int		type;
	cl_float	radius;
	cl_float3	pos;
	cl_float3	color;
	cl_float3	emission;
	cl_float3	dir;
	cl_float	angle;
	cl_float	plane_d;
}; 

typedef struct s_sphere
{
	t_vec3 		center;
	t_material	material;
	float		radius;
	t_vec3 		v;
	double		angle;
	t_vec3		tip;
	int			type;
} t_sphere;


typedef	struct s_cylinder
{
	t_vec3		center;
	t_material	material;
	float		radius;
	t_vec3		v;
	int			min;
	int			max;
	int			type;
}				t_cylinder;

typedef	struct		s_cone
{
	// t_vec3		tip;
	// t_vec3		direction;
	// double			angle;
	// t_material material;
	t_vec3		center;
	t_material	material;
	float		radius;
	t_vec3		v;
	double		angle;
	t_vec3		tip;
	int			type;
}					t_cone;


struct s_vertex
{
	t_vec3 position;
	float U, V;
};

typedef struct s_coord
{
	t_vertex original;
	t_vertex rotated;
	char processed;
} t_coord;

typedef struct s_polygon
{
t_vertex **vertices;
	int nvertices;
	//Texture
	t_sector *sector;
	//Plane
} t_polygon;

typedef struct s_plane
{
	t_vec3		point;
	t_vec3		normal;
	t_material	material;
	int			type;
} t_plane;

struct s_sector
{
	t_polygon *polygons;
};

typedef  struct s_world
{
	t_sector *sectors;
} t_world;

typedef struct	s_main_obj
{
	t_object	*figures;
	int			figures_num;
	t_light		*lights;
	int			elum_num;
	double		closest;

}				t_main_obj;

typedef struct s_camera
{
	cl_float3 position;
	cl_float3		axis_x;
	cl_float3		axis_y;
	cl_float3		axis_z;
	cl_float3		forward;
	int				width;
	int				height;
} t_camera;

typedef enum		e_camera_direction
{
	left,
	right,
	up,
	down,
	forward,
	backward
}					t_camera_direction;


typedef struct s_gpu
{
    cl_device_id		device_id;     // compute device id
    cl_context			context;       // compute context
    cl_command_queue	commands;      // compute command queue
    cl_program			program;       // compute program
    cl_kernel			kernel;       // compute kernel
	cl_uint				numPlatforms;
	cl_int				err;
	char*				kernel_source;
	int * cpuOutput;
	cl_float3 *vec_temp;
	t_obj *spheres;
	cl_mem cl_bufferOut;
	cl_mem cl_cpuSpheres;
	cl_mem  cl_cpu_vectemp;
	cl_mem  cl_cpu_camera;
	t_camera *camera;
	char	*scene;
	int samples;
	t_objpoint *f;
}				t_gpu;




typedef struct s_game
{
	t_sdl *sdl;
	t_surface *image;
	t_list *verties;
	t_sphere *spheres;
	t_cone *cones;
	t_cylinder *cylinders;
	int n_spheres;
	int n_cones;
	int n_cylinders;
	int wsad[8];
	t_vec3 origin;
	t_main_obj	main_objs;
	t_gpu *gpu;
	int init_render;
	t_objpoint *f;
} t_game;

typedef struct s_superfloat
{
	float		xdeg;
	float		ydeg;
	float		zdeg;
	float		sx;
	float		sy;
	float		sz;
	float		cx;
	float		cy;
	float		cz;
} t_superfloat;

int bind_data(t_gpu *gpu, t_main_obj *main);
void release_gpu(t_gpu *gpu);
void ft_run_gpu(t_gpu *gpu);
void	configure_sphere(char *map_name, t_sphere *sphere);
// inline t_vec3 ft_vec3_create(float x, float y, float z);
// inline t_vec3	ft_vec3_sum(t_vec3 a, t_vec3 b);
// inline  t_vec3	ft_vec3_substract(t_vec3 a, t_vec3 b);
// inline  float ft_vec3_dot_multiply(t_vec3 a, t_vec3 b);
// inline t_vec3 ft_vec3_scalar_multiply(t_vec3 a, float b);
// inline t_vec3 ft_vec3_cross_multiply(t_vec3 a, t_vec3 b);
// inline  float ft_vec3_norm(t_vec3 vect);
// inline  t_vec3 ft_vec3_normalize(t_vec3 vect);
// inline float ft_vec3_projection(t_vec3 a, t_vec3 b);
// inline void ft_vec3_print(t_vec3 a);

// extern inline t_vec3 ft_vec3_create(float x, float y, float z);
// extern inline t_vec3	ft_vec3_sum(t_vec3 a, t_vec3 b);
//  extern inline t_vec3	ft_vec3_substract(t_vec3 a, t_vec3 b);
//  extern inline float ft_vec3_dot_multiply(t_vec3 a, t_vec3 b);
//  extern inline t_vec3 ft_vec3_scalar_multiply(t_vec3 a, float b);
// extern inline t_vec3 ft_vec3_cross_multiply(t_vec3 a, t_vec3 b);
//  extern inline float ft_vec3_norm(t_vec3 vect);
//  extern inline t_vec3 ft_vec3_normalize(t_vec3 vect);
//  extern inline float ft_vec3_projection(t_vec3 a, t_vec3 b);
// extern inline void ft_vec3_print(t_vec3 a);


//point
t_point3 ft_point3_sum(t_point3 a, t_point3 b);
t_point3 ft_point3_substract(t_point3 a, t_point3 b);
t_point3 ft_point3_substract_vec3(t_point3 a, t_vec3 b);
double ft_point3_substract_sum_2(t_point3 a, t_vec3 b);
double ft_point3_dist(t_point3 a, t_vec3 b);
t_point3 ft_point3_scalar_multiply(t_point3 a, double b);

	t_vec3 ft_vec3_create(float x, float y, float z);
	t_vec3	ft_vec3_sum(t_vec3 a, t_vec3 b);
	t_vec3	ft_vec3_substract(t_vec3 a, t_vec3 b);
	float ft_vec3_dot_multiply(t_vec3 a, t_vec3 b);
	t_vec3 ft_vec3_scalar_multiply(t_vec3 a, float b);
	t_vec3 ft_vec3_cross_multiply(t_vec3 a, t_vec3 b);
	float ft_vec3_norm(t_vec3 vect);
	t_vec3 ft_vec3_normalize(t_vec3 vect);
	float ft_vec3_projection(t_vec3 a, t_vec3 b);
	void ft_vec3_print(t_vec3 a);
	t_vec3 ft_vec3_neg(t_vec3 v);
	t_vec3	ft_vec3_multiply_matrix(t_vec3 v, t_mat4 m);
	double	ft_vec3_angle(t_vec3 a, t_vec3 b);
	double			ft_vec3_length(t_vec3 v1);

t_quaternion t_quaternion_sum(t_quaternion a, t_quaternion b);
t_quaternion t_quaternion_substract(t_quaternion a, t_quaternion b);
float ft_quaternion_norm(t_quaternion q);
float ft_degree_to_rad(float degree);
t_quaternion ft_quaternion_normalize(t_quaternion q);
t_quaternion ft_quaternion_covert_to_unit_norm(t_quaternion q);
t_quaternion ft_quaternion_conjugate(t_quaternion q);
t_quaternion ft_quaternion_inverse(t_quaternion q);
t_quaternion ft_quaternion_multiply(t_quaternion a, t_quaternion b);
t_quaternion ft_quaternion_multiply2(t_quaternion a, t_quaternion b);
t_quaternion ft_quaternion_local_rotation(t_vec3 axis, float angle);

//mat
t_mat4	ft_mat4_identity_matrix(void);
t_vec3 ft_mat3_multiply_vec3(t_mat3 matrix, t_vec3 vector);
t_mat4	ft_mat4_multiply_mat4(t_mat4 a, t_mat4 b);
t_mat4	ft_mat4_scalar_multiply(t_mat4 m, double n);
t_mat4	ft_mat4_sum_mat4(t_mat4 a, t_mat4 b);
t_mat4	ft_mat4_translation_matrix(t_vec3 v);
t_mat4	ft_mat4_scale_matrix(double a, double b, double c);
t_point3 ft_mat3_multiply_point3(t_mat3 matrix, t_point3 point);
t_vec3 ft_mat3_multiply_vec3(t_mat3 matrix, t_vec3 vector);
t_mat4	ft_mat4_rotation_matrix(t_vec3 axis, double alpha);
void ft_mat4_print(t_mat4 mat);
//rot
t_vec3	ft_vec3_rotate_quaterion(float angle, t_vec3 vector, t_vec3 axis);
t_vec3	ft_vec3_rotate_quaterion2(float angle, t_vec3 vector, t_vec3 axis);
t_vec3 ft_vec3_project_test1(t_vec3 p);
t_vec3 ft_vec3_rotate_test1(t_vec3 p, t_vec3 angle);
t_vec3 ft_vec3_project_test2(t_vec3 p);
t_vec3 ft_vec3_rotate_test2(t_vec3 p, t_vec3 angle);
t_mat4 ft_mat4_transpose(t_mat4 mat);
t_mat4 ft_look_at(t_vec3 eye, t_vec3 up);
//normals
extern inline t_normal3 ft_normal3_neg(t_normal3 v);
extern inline t_normal3 ft_normal3_scalar_multiply(t_normal3 a, float b);
extern inline t_normal3	ft_normal3_sum(t_normal3 a, t_normal3 b);
 float ft_normal3_dot_multiply_vec3(t_normal3 a, t_vec3 b);
inline t_normal3 ft_normal3_scalar_multiply(t_normal3 a, float b);

//intersect
double		sphere_intersection(void *figure, t_ray *ray, float *t0);
double		cone_intersection(void *object, t_ray *ray, float *t0);
double		cylinder_intersection(void *object, t_ray *ray, float *t0);
double		plane_intersection(void *object, t_ray *ray, float *t0);


int			opencl_init(t_gpu *gpu, t_game *game);
cl_float3 create_cfloat3 (float x, float y, float z);

cl_float3 cl_scalar_mul(cl_float3 vector, double scalar);

cl_float3 cl_add(cl_float3 v1, cl_float3 v2);
t_camera			*camera_new(int width, int height);
void 				camera_move
					(t_camera *camera,
					t_camera_direction direction,
					float length);

int					test(int i);
int					quan_type(char *s);
int					ft_valid(char **f, const int i, int *j);
cl_float3 			create_cfloat3x (float x, float y, float z);
float		   		return_float(char *s);
void				read_scene(t_obj* cpu_spheres, char *s);

int						valid(char	*json, t_objpoint *f);
t_objpoint			*memory_for_objpoint();
int						read_fd(int fd, t_objpoint *f);
void				ft_putstrv(char *s);
void				ft_putstrv2(char *s, int end);
void				free_gnl(char **s);
int						parsing(t_objpoint *f, char **file);
int					repit(int st, int end, char *sl, char **file);
int					fig_valid(int s, int end, char **file);
int						numb_of_line(int s, int end, char *sl, char **file);
int					type_select(char *s);
void				ft_putstrv1(char *s);
void				free_figures(t_objpoint *f);
int					valid_type(t_objpoint *f, int type);
int					type_sphere(t_objpoint *f);
int					type_cyl(t_objpoint *f);
int					type_plane(t_objpoint *f);
int					type_cone(t_objpoint *f);
int					check_position(t_objpoint *f);
int					find_end_of_block(int i, t_objpoint *f);
int					repit_d(int st, int end, char *sl, char **file);
int					check_color(t_objpoint *f);
int					check_emission(t_objpoint *f);
int					check_num_of_param(char *stroka, char *parametr);
int					check_reflection(t_objpoint *f);
int					pulling_out(t_objpoint *f, int type);
int					check_rotation(t_objpoint *f);
int					check_plane(t_objpoint *f);
int					check_radius(t_objpoint *f);
int					pulling_sphere(t_objpoint *f);
int					pulling_cyl(t_objpoint *f);
int					pulling_con(t_objpoint *f);
int					pulling_plane(t_objpoint *f);
float				return_float(char *s);
float				return_radius(t_objpoint *f);
float				return_reflection(t_objpoint *f);
float				return_xyz(char *str);
int					return_position(t_objpoint *f);
int					return_color(t_objpoint *f);
int					return_emission(t_objpoint *f);
float				return_clr(char *str);
int					quan_of_obj(t_objpoint *f);
int					return_rotation(t_objpoint *f);
float				return_plane_d(t_objpoint *f);

void 				initscene2(t_obj* cpu_spheres, int n, t_objpoint *ff);
cl_float3			create_cfloat3(float x, float y, float z);
int   				 gpu_read_kernel(t_gpu *gpu);
int					bind_data(t_gpu *gpu, t_main_obj *main);
int					opencl_init2(t_gpu *gpu, t_game *game);
double				quandratic_solve(double k1, double k2, double k3);
void				ft_mat4_print(t_mat4 mat);
t_mat4				ft_mat4_rotation_matrix(t_vec3 axis, double alpha);
void				game_init(t_game *game);

#endif