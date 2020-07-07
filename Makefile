# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabriand <mabriand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/16 14:05:40 by mabriand          #+#    #+#              #
#    Updated: 2020/01/23 15:36:22 by mabriand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3D

##################################### PATH #####################################

PARSE = cub3d_sources/parsing/
GAME = cub3d_sources/game/

#################################### SOURCES ###################################

#------------------------------PARSE-#
SRCS +=	$(PARSE)create_map.c			$(PARSE)gnl.c \
		$(PARSE)parse_init.c 			$(PARSE)parse_colors.c \
		$(PARSE)parse_config.c			$(PARSE)parse_map.c \
		$(PARSE)parse_resolution.c		$(PARSE)parse_texture.c \
		$(PARSE)parsing.c				$(PARSE)parse_utils.c	\
		$(PARSE)update_pars.c			$(PARSE)map_cp.c
#-------------------------------GAME-#
SRCS += $(GAME)draw.c					$(GAME)event.c \
		$(GAME)game_init.c				$(GAME)game_utils.c \
		$(GAME)input.c					$(GAME)move.c \
		$(GAME)player.c					$(GAME)print_sprite.c \
		$(GAME)raycast.c				$(GAME)rotate.c \
		$(GAME)save.c					$(GAME)sprite_gathering.c \
		$(GAME)start.c					$(GAME)texture_mapping.c \
		$(GAME)texture.c				$(GAME)wall.c \
		$(GAME)free.c
#-------------------------------MAIN-#
SRCS += cub3d_sources/main.c

##################################### BASIC ####################################

CFLAGS 	=	-Wall -Wextra -Werror

CC		= 	clang

INC		= 	cub3d_header/

HEADER	= 	$(INC)cub3d.h

OBJS	=	$(SRCS:.c=.o)

LIB 	= 	libft/libft.a

MLX 	+=	minilibx-linux/libmlx.a \
			minilibx-linux/libmlx_Linux.a #sert à rien

##################################### RULES ####################################

all: complib compmlx $(NAME)

$(OBJS): %.o: %.c $(HEADER)
		$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

#-------------------------------COMP-#

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) $(MLX) -lm -lXext -lX11 -o $@

complib:
	$(MAKE) -C libft all

compmlx:
	$(MAKE) -C minilibx-linux all

#------------------------------CLEAN-#

cleanlib:
	$(MAKE) -C libft clean

cleanmlx:
	$(MAKE) -C minilibx-linux clean

cleancub:
	rm -f $(PARSE)*.o
	rm -f $(GAME)*.o
	rm -f cub3d_sources/main.o

clean: cleanlib cleanmlx cleancub

fclean: clean
	rm $(NAME)

#---------------------------------RE-#

re: fclean all

.PHONY:	all clean fclean re
.SILENT:
