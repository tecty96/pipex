NAME = pipex
BONUS_NAME = pipexb

OBJS_DIR = objs
INCS_DIR = includes
LIBS_DIR = libs

VPATH = ./srcs:\
	./srcs/tools: \
	./srcs/bonus: \
	./srcs/bonus/get_next_line

P_SRC = pipex.c
GP_SRCS = $(notdir $(wildcard srcs/tools/*.c))
B_SRCS = $(notdir $(wildcard srcs/bonus/*.c srcs/bonus/*/*.c))

P_OBJS = $(addprefix $(OBJS_DIR)/, $(P_SRC:.c=.o) $(GP_SRCS:.c=.o))
B_OBJS = $(addprefix $(OBJS_DIR)/, $(B_SRCS:.c=.o) $(GP_SRCS:.c=.o))

CC = gcc
CFLAGS = -Werror -Wextra -Wall

############################################################################

all: $(NAME) 

$(NAME): $(P_OBJS)
	$(CC) $(CFLAGS) -g $(P_OBJS) -o $@ -L $(LIBS_DIR) -lft -I $(INCS_DIR)

$(OBJS_DIR)/%.o: %.c
	@if [ ! -d $(OBJS_DIR) ]; then	\
		mkdir $(OBJS_DIR);			\
		echo mkdir $(OBJS_DIR);		\
	fi
	$(CC) $(CFLAGS) -g -c $< -o $@ -L $(LIBS_DIR) -lft -I $(INCS_DIR)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(B_OBJS)
	$(CC) $(CFLAGS) -g $(B_OBJS) -o $(BONUS_NAME) -L $(LIBS_DIR) -lft -I $(INCS_DIR)

############################################################################

clean:
	rm -rf $(OBJS_DIR)/*.o
	
fclean: clean
	rm -rf $(NAME) $(BONUS_NAME)

re: fclean all

############################################################################


.PHONY: all clean fclean re bonus
