NAME		=	so_long
DIR			=	./srcs/
HDIR		=	./includes/
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
RM			=	rm -f
DIR_SRCS	=	srcs/

SRCS		=	$(DIR)main.c		$(DIR)init_struct.c


OBJS	= $(patsubst %.c,%.o, $(SRCS))

HEAD		= $(HDIR)so_long.h

LIB			= libft/libft.a

all			:	$(NAME)

$(NAME)		:	$(OBJS) $(HEAD)
	$(MAKE) -C libft
	$(CC) -g $(CFLAGS) $(LIB) $(SRCS) -o $(NAME) 

clean 		:
	$(MAKE) clean -C libft
	$(RM) $(OBJS)

fclean		:	clean
	$(MAKE) clean -C libft
	$(RM) $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re bonus