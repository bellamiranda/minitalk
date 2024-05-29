# Supress the display of commands > output less verbose
.SILENT:
# Execute all lines in the same shell > preserve variables and directory changes
.ONESHELL:

S_NAME = server
C_NAME = client
PRINTF	= ft_printf/ft_printf.a

S_SRCS = server.c
S_OBJS = $(S_SRCS:.c=.o)

C_SRCS = client.c
C_OBJS = $(C_SRCS:.c=.o)

CC = cc
CFLAGS = -g -Wall -Wextra -Werror

all: $(PRINTF) $(S_NAME) $(C_NAME)

$(PRINTF):
	@echo "\033[1;36m[ ✔ ] Compiling ft_printf...\033[0m"
	@make -C ft_printf > /dev/null 2>&1
# /dev/null > discart all data written to it
# 2>&1 > redirects fd 1 (stderr) to fd 1 (stdout) (will also be discarted)

$(S_NAME): $(S_SRCS) $(S_OBJS)
	$(CC) $(CFLAGS) $(S_OBJS) $(PRINTF) -o $(S_NAME)
	@echo "\033[1;32m[ ✔ ] $(S_NAME) ready!\033[0m"

$(C_NAME): $(C_SRCS) $(C_OBJS)
	$(CC) $(CFLAGS) $(C_OBJS) $(PRINTF) -o $(C_NAME)
	@echo "\033[1;32m[ ✔ ] $(C_NAME) ready!\033[0m"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "\033[1;36m[ ✔ ] Compiling objects...\033[0m"

S_BONUS = server_bonus
C_BONUS = client_bonus

S_BONUS_SRCS = server_bonus.c
S_BONUS_OBJS = $(S_BONUS_SRCS:.c=.o)

C_BONUS_SRCS = client_bonus.c
C_BONUS_OBJS = $(C_BONUS_SRCS:.c=.o)

bonus: $(PRINTF) $(S_BONUS) $(C_BONUS)

$(S_BONUS):$(S_BONUS_OBJS)
	$(CC) $(CFLAGS) $(S_BONUS_OBJS) $(PRINTF) -o $(S_BONUS)
	@echo "\033[1;32m[ ✔ ] $(S_BONUS) ready!\033[0m"

$(C_BONUS):$(C_BONUS_OBJS)
	$(CC) $(CFLAGS) $(C_BONUS_OBJS) $(PRINTF) -o $(C_BONUS)
	@echo "\033[1;32m[ ✔ ] $(C_BONUS) ready!\033[0m"

clean:
	@make clean -C ./ft_printf > /dev/null 2>&1
	@rm -rf $(S_OBJS) $(C_OBJS)
	@echo "\033[1;31m[ ✔ ] Objects files removed\033[0m"

fclean: clean
	@make fclean -C ./ft_printf > /dev/null 2>&1
	@rm -rf $(S_NAME) $(C_NAME)
	@echo "\033[1;31m[ ✔ ] Executables removed\033[0m"

re: fclean all

# Declare these targets as .PHONY so they are not treated as files
.PHONY: all clean fclean re bonus