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

.PHONY		:	all clean fclean re bonus

.c.o:	
	$(CC) $(CFLAGS) -c  -I$(HEADER) -I$(LIB_HEADER) $< -o $(<:.c=.o)

all				:	$(NAME) $(MLX_A)

$(MLX_A)		:
	$(MAKE)  -C $(LIB_MLX)
	cp $(MINILIBX_A_DIR) $(MLX_A)

$(NAME)		:	$(OBJS) $(HEAD)
	$(MAKE) -C libft
	$(CC) -g $(CFLAGS)  $(LIB) -I$(HEADER) $(SRCS)  -L. $(LIB_NAME)  $(MINILIBX_A_DIR) $(OPENGL) -o $(NAME) 

clean 		:
	$(MAKE) clean -C libft
	# $(MAKE) clean -C $(MINILIBX_DIR) // та же фигня!!!!!!
	$(RM) $(OBJS)

fclean		:	clean
	$(MAKE) clean -C libft
	# $(MAKE) fclean -C $(MINILIBX_DIR) // НЕ УДАЛЯЕТ!
	$(RM) $(MLX_A)
	$(RM) $(NAME)

re			:	fclean all
