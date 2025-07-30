CC = cc

CFLAGS = -g -Wall -Wextra -Werror

# Sources
SRCSCL = ./client.c
SRCSSV = ./server.c

# Object files
OBJSCL = $(SRCSCL:.c=.o)
OBJSSV = $(SRCSSV:.c=.o)

# Output binary name
SERVER = server
CLIENT = client

# printf
PRINTF_DIR = ./ft_printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a
MAKE = make

# Main rule
all: $(SERVER) $(CLIENT)

# Linking rule
$(SERVER): $(OBJSSV) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJSSV) $(PRINTF_LIB) -o $(SERVER)

$(CLIENT): $(OBJSCL) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJSCL) $(PRINTF_LIB) -o $(CLIENT)

$(PRINTF_LIB):
	$(MAKE) -C $(PRINTF_DIR)

# Rule to compile .c files to .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Cleaning rules
clean:
	rm -f $(OBJSSV) $(OBJSCL)
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(SERVER) $(CLIENT)
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: fclean clean re all