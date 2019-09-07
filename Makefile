# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/16 12:58:07 by jblack-b          #+#    #+#              #
#    Updated: 2019/09/07 18:55:57 by odale-dr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1

FLAGS = -g
CC = gcc
LIBRARIES = -lft -L$(LIBFT_DIRECTORY)  -lsdl -L$(LIBSDL_DIRECTORY) -lm -framework OpenCL  #-lvect -L$(LIBVECT) -lgnl -L$(LIBGNL) -lcl -L$(LIBCL)#-lmath -L$(LIBMATH_DIRECTORY)
INCLUDES = -I$(HEADERS_DIRECTORY) -I$(LIBFT_HEADERS)  -I$(SDL_HEADERS) -I$(LIBSDL_HEADERS) -I$(LIBVECT)include/ -Isrcs/cl_error/ -I$(LIBGNL)include/ -I$(LIBCL)include/ # -I$(LIBMATH_HEADERS)
FRAMEWORKS = -framework OpenCL

LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = ./libft/
LIBFT_HEADERS = $(LIBFT_DIRECTORY)includes/

LIBMATH = $(LIBMATH_DIRECTORY)libmath.a
LIBMATH_DIRECTORY = ./libmath/
LIBMATH_HEADERS = $(LIBMATH_DIRECTORY)includes/

LIBVECT = libvect/
LIBCL	= libcl/
LIBGNL	= libgnl/


SDL_HEADERS = include/

LIBSDL = $(LIBSDL_DIRECTORY)libsdl.a
LIBSDL_DIRECTORY = ./libsdl/
LIBSDL_HEADERS = $(LIBSDL_DIRECTORY)includes/

HEADERS_DIRECTORY = ./includes/
HEADERS_LIST = rtv1.h
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

DIRECTORY =  $(shell pwd)
SDL_CFLAGS = $(shell sdl2-config --cflags)
SDL_LDFLAGS = $(shell sdl2-config --libs)
SDL_DIRECTORY = $(DIRECTORY)/lib
SDL_MAKE = $(DIRECTORY)/SDL2

LIB_LIST =	libSDL2.a\
			libSDL2.la\
			libSDL2_test.la\
			libSDL2main.la\
			libSDL2-2.0.0.dylib\
			libSDL2.dylib\
			libSDL2_test.a\
			libSDL2main.a

SRCS_DIRECTORY = ./srcs/

SRCS_LIST = main.c map_parser.c vectors.c quaternion.c rotate.c intersect.c matrix.c normals.c math.c \
			cl_lib/gpu_init.c

SRCS_LIST += camera/camera_new.c camera/camera_move.c
SRCS_LIST += pars/create_cfloat3x.c \
			 pars/read_scene.c pars/return_float.c pars/type.c \
			 pars/valid.c pars/memory_for_objpoint.c pars/read_fd.c \
			 pars/ft_putstrv.c pars/free_gnl.c pars/parsing.c \
			 pars/repit.c pars/fig_valid.c pars/numb_of_line.c \
			 pars/type_select.c pars/free_figures.c \
			 pars/valid_type.c pars/type_sphere.c \
			 pars/type_plane.c pars/type_cyl.c pars/type_cone.c \
			 pars/check_position.c pars/find_end_of_block.c \
			 pars/check_color.c pars/check_emission.c \
			 pars/check_num_of_param.c pars/check_reflection.c \
			 pars/pulling_out.c pars/check_rotation.c pars/check_plane.c \
			 pars/check_radius.c pars/pulling_sphere.c pars/pulling_cyl.c \
			 pars/pulling_plane.c pars/pulling_con.c \
			 pars/return_radius.c
			 
OBJS_DIRECTORY = objects/
OBJS_LIST = $(patsubst %.c, %.o, $(SRCS_LIST))
OBJS = $(addprefix $(OBJS_DIRECTORY), $(OBJS_LIST))
SDL_LIBS = $(addprefix $(DIRECTORY)/lib/, $(LIB_LIST))
MAKES = makes
LIBFT = libft/libft.a
LIBSDL_EXIST = 0
err = no

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m
CLEAR_LINE	:= \033[2K
BEGIN_LINE	:= \033[A
COL_END		:= \033[0m
COL_RED		:= \033[1;31m
COL_GREEN	:= \033[1;32m
COL_YELLOW	:= \033[1;33m
COL_BLUE	:= \033[1;34m
COL_VIOLET	:= \033[1;35m
COL_CYAN	:= \033[1;36m
COL_WHITE	:= \033[1;37m

TOTAL_FILES := $(shell echo $(SRCS_LIST) | wc -w | sed -e 's/ //g')
CURRENT_FILES = $(shell find $(DIRECTORY)/objects/ -type f 2> /dev/null | wc -l | sed -e 's/ //g')

.PHONY: clean fclean re

all: $(MAKES) $(NAME)


$(NAME): $(LIBFT)  $(LIBSDL) $(OBJS_DIRECTORY) $(OBJS) $(HEADERS) #$(LIBMATH) 
	@$(CC) $(FLAGS) $(LIBSDL) $(INCLUDES) $(OBJS) $(SDL_CFLAGS) $(SDL_LDFLAGS) -o $(NAME) $(LIBRARIES)
	@echo "$(CLEAR_LINE)[`expr $(CURRENT_FILES) '*' 100 / $(TOTAL_FILES)`%] $(COL_BLUE)[$(NAME)] $(COL_GREEN)Finished compilation. Output file : $(COL_VIOLET)$(PWD)/$(NAME)$(COL_END)"

$(MAKES):
	@$(MAKE) -sC $(LIBFT_DIRECTORY)
	@$(MAKE) -sC $(LIBSDL_DIRECTORY)
	@$(MAKE) -sC $(LIBMATH_DIRECTORY)
	# @$(MAKE) -sC $(LIBVECT)
	# @$(MAKE) -sC $(LIBGNL)
	# @$(MAKE) -sC $(LIBCL)


$(OBJS_DIRECTORY):
	@mkdir -p $(OBJS_DIRECTORY)


$(OBJS_DIRECTORY)%.o : $(SRCS_DIRECTORY)%.c $(HEADERS)
	@mkdir -p $(@D)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(CLEAR_LINE)[`expr $(CURRENT_FILES) '*' 100 / $(TOTAL_FILES)`%] $(COL_BLUE)[$(NAME)] $(COL_GREEN)Compiling file [$(COL_VIOLET)$<$(COL_GREEN)].($(CURRENT_FILES) / $(TOTAL_FILES))$(COL_END)$(BEGIN_LINE)"

count:
	@echo $(TOTAL_FILES)
	@echo $(CURRENT_FILES)

depend:
						makedepend --$(SRCS_DIRECTORY)/$(SRCS_LIST); 
		
sdl:
	cd SDL2; ./configure --prefix=$(DIRECTORY); make;
	$(MAKE) -sC $(DIRECTORY)/SDL2 install

this:
	@rm -rf $(OBJS_DIRECTORY) && make;

$(SDL_LIBS):
	cd SDL2; ./configure --prefix=$(DIRECTORY); make;
	$(MAKE) -sC $(SDL_MAKE) install

$(LIBFT):
	@echo "$(NAME): $(GREEN)Creating $(LIBFT)...$(RESET)"
	@$(MAKE) -sC $(LIBFT_DIRECTORY)

$(LIBSDL):
	@echo "$(NAME): $(GREEN)Creating $(LIBSDL)...$(RESET)"
	@$(MAKE) -sC $(LIBSDL_DIRECTORY)

clean:
	@$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	@$(MAKE) -sC $(LIBSDL_DIRECTORY) clean
	@rm -rf $(OBJS_DIRECTORY)
	@echo "$(NAME): $(RED)$(OBJECTS_DIRECTORY) was deleted$(RESET)"
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"
	#@$(MAKE) -sC $(SDL_MAKE) clean
	@echo "$(SDL_MAKE): $(RED)object files were deleted$(RESET)"

dd:
	rm $(NAME)

lib:
	 @$(MAKE) -sC $(LIBSDL_DIRECTORY) re

fclean: clean
	@rm -r $(LIBFT)
	@echo "$(NAME): $(RED)$(LIBFT) was deleted$(RESET)"
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"
	@$(MAKE) -sC $(LIBFT_DIRECTORY) fclean
	@$(MAKE) -sC $(LIBSDL_DIRECTORY) fclean
	#@rm -f $(DIRECTORY)/bin/sdl2-config
	#@rm -f $(DIRECTORY)/lib/libSDL2.la
	#@rm -f $(DIRECTORY)/lib/libSDL2main.la
	#@rm -f $(DIRECTORY)/lib/libSDL2_test.la
	#@rm -f $(DIRECTORY)/share/aclocal/sdl2.m4
	#@rm -f $(DIRECTORY)/lib/pkgconfig/sdl2.pc
	#@rm -f $(DIRECTORY)/lib/cmake/SDL2/sdl2-config.cmake
	#@rm -rf lib bin share
	#@echo "$(SDL_MAKE): $(RED)was unistalled$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all
# DO NOT DELETE
