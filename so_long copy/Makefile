NAME			=	so_long
HEADER			=	includes
LIB_HEADER 		=	libft
CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra
RM				=	rm -f
DIR_SRCS		=	srcs/

SRCS			=	$(DIR_SRCS)main.c				$(DIR_SRCS)init_struct.c			$(DIR_SRCS)valid.c \
					$(DIR_SRCS)reading_in_buf.c		$(DIR_SRCS)minilibx.c				$(DIR_SRCS)draw.c \
					$(DIR_SRCS)play.c

OBJS			=	$(SRCS:.c=.o)

HEAD			=	$(HEADER)/so_long.h

LIB				=	libft/libft.a

LIB_MLX 		=	./minilibx
OPENGL			=	-lz -framework OpenGL -framework AppKit
MLX_A			=	libmlx.dylib
MINILIBX_DIR 	=	minilibx/
MINILIBX_A_DIR	=	$(MINILIBX_DIR)/$(MLX_A)

#colors
F_NONE			= \033[37m
F_BOLD			= \033[1m
F_RED			= \033[31m
F_ORANGE		= \033[38m
F_YELLOW		= \033[33m
F_GREEN			= \033[32m
F_CYAN			= \033[36m
F_BLUE			= \033[34m

.c.o:	
	$(CC) $(CFLAGS) -c  -I$(HEADER) -I$(LIB_HEADER) $< -o $(<:.c=.o)

all				:	$(NAME) $(MLX_A)

$(MLX_A):
		@echo "$(F_CYAN)Compile libmlx.a ...$(F_NONE)"
		$(MAKE)  -C $(LIB_MLX)
		@echo "$(F_CYAN)Compile libmlx.a END !...$(F_NONE)"
		@echo "$(F_CYAN)Copy libmlx.a ...$(F_NONE)"
		cp $(MINILIBX_A_DIR) $(MLX_A)
		@echo "$(F_CYAN)Copy libmlx.a END !...$(F_NONE)"

$(NAME)		:	$(OBJS) $(HEAD)
	$(MAKE) -C libft
	$(CC) -g $(CFLAGS)  $(LIB) -I$(HEADER) $(SRCS)  -L. $(LIB_NAME)  $(MINILIBX_A_DIR) $(OPENGL) -o $(NAME) 

clean 		:
	$(MAKE) clean -C libft
	# $(MAKE) clean -C $(MINILIBX_DIR)
	$(RM) $(OBJS)

fclean		:	clean
	$(MAKE) clean -C libft
	# $(MAKE) clean -C $(MINILIBX_DIR) // НЕ УДАЛЯЕТ!
	$(RM) $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re bonus