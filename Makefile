NAME			=	so_long
BNAME			=	so_long_bonus
HEADER			=	includes
LIB_HEADER 		=	libft
CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra
RM				=	rm -f
DIR_SRCS		=	srcs/
DIR_BSRCS		=	bsrcs/

SRCS			=	$(DIR_SRCS)main.c				$(DIR_SRCS)init_struct.c			$(DIR_SRCS)draw.c \
					$(DIR_SRCS)reading_in_buf.c		$(DIR_SRCS)minilibx.c				$(DIR_SRCS)valid.c \
					$(DIR_SRCS)play.c

BSRCS   		= 	$(DIR_BSRCS)main.c				$(DIR_BSRCS)init_struct.c			$(DIR_BSRCS)valid.c \
					$(DIR_BSRCS)reading_in_buf.c	$(DIR_BSRCS)minilibx.c				$(DIR_BSRCS)draw.c \
					$(DIR_BSRCS)play.c				$(DIR_BSRCS)player.c

OBJS			=	$(SRCS:.c=.o)

BOBJS			=	$(BSRCS:.c=.o)

HEAD			=	$(HEADER)/so_long.h

BHEAD			=	$(HEADER)/so_long_bonus.h

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

bonus			:	$(BNAME) $(MLX_A)

$(BNAME)	:	$(BOBJS) $(BHEAD)
	$(MAKE) -C libft
	$(CC) -g $(CFLAGS)  $(LIB) -I$(HEADER) $(BSRCS)  -L. $(LIB_NAME)  $(MINILIBX_A_DIR) $(OPENGL) -o $(BNAME) 
  


clean 		:
	$(MAKE) clean -C libft
	$(MAKE) clean -C $(MINILIBX_DIR)
	$(RM) $(OBJS)
	$(RM) $(BOBJS)

fclean		:	clean
	$(MAKE) clean -C libft
	$(MAKE) fclean -C $(MINILIBX_DIR)
	$(RM) $(MLX_A)
	$(RM) $(NAME)
	$(RM) $(BOBJS)

re			:	fclean all
