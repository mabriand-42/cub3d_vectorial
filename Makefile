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

NAME = libcub3d.a

##################################### PATH #####################################

PARSE = cub3d_sources/parsing/
LIBFT = libft/libft_sources/

#################################### SOURCES ###################################

#------------------------------PARSE-#
SRCS +=	$(PARSE)create_map.c			$(PARSE)gnl.c \
		$(PARSE)parse_init.c 			$(PARSE)parse_colors.c \
		$(PARSE)parse_config.c			$(PARSE)parse_map.c \
		$(PARSE)parse_resolution.c		$(PARSE)parse_texture.c \
		$(PARSE)parsing.c				$(PARSE)parse_utils.c	\
		$(PARSE)update_pars.c	

##################################### BASIC ####################################

CFLAGS 	= -Wall -Wextra -Werror

CC		= gcc

INC		= cub3d_header/

HEADER	= $(INC)cub3d.h

OBJS	= $(SRCS:.c=.o)

OBJLIB =	$(LIBFT)ft_printf/*.o		$(LIBFT)get-next-line/*.o \
			$(LIBFT)libft_char/*.o		$(LIBFT)libft_convert/*.o \
			$(LIBFT)libft_list/*.o		$(LIBFT)libft_memory/*.o \
			$(LIBFT)libft_nbr/*.o		$(LIBFT)libft_output/*.o \
			$(LIBFT)libft_string/*.o
			
##################################### RULES ####################################

all: complib $(NAME)

complib:
		$(MAKE) -C libft all

$(OBJS): %.o: %.c $(HEADER)
		$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(NAME): $(OBJS)
	ar rc $@ $(OBJS) $(OBJLIB)
	ranlib $(NAME)

clean:
	$(MAKE) -C libft clean
	rm -f $(PARSE)*.o

fclean: clean
	$(MAKE) -C libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re
.SILENT: #pour pas que ca affiche tout ce qu'il fait