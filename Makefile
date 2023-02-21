CC			= 		gcc

CFLAGS		=		-Werror -Wextra -Wall

all:                 server client

server:             server.c libft.a
					@$(CC) $(CFLAGS) server.c src/libft/libft.a -o server

client:             client.c libft.a
					@$(CC) $(CFLAGS) client.c src/libft/libft.a -o client

libft.a:
					@make all -C ./src/libft

clean:
					@make clean -C libft/

fclean:
					@rm -f server
					@rm -f client
					@make fclean -C ./src/libft

re:					fclean all