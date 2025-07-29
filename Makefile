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

# Main rule
all: $(SERVER) $(CLIENT)

# Linking rule
$(SERVER): $(OBJSSV) 
	$(CC) $(CFLAGS) $(OBJSSV) -o $(SERVER)

$(CLIENT): $(OBJSCL) 
	$(CC) $(CFLAGS) $(OBJSCL) -o $(CLIENT)

# Rule to compile .c files to .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Cleaning rules
clean:
	rm -f $(OBJSSV) $(OBJSCL)

fclean: clean
	rm -f $(SERVER) $(CLIENT)

re: fclean all

.PHONY: fclean clean re all