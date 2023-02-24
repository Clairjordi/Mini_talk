# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clorcery <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/23 14:11:12 by clorcery          #+#    #+#              #
#    Updated: 2022/08/08 21:07:42 by clorcery         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# /* ~~~~~~~ Colors ~~~~~~~ */
GREEN:="\033[1;32m"
YELLOW:="\033[1;33m"
EOC:="\033[0;0m"
# /* ~~~~~~~~~~~~~~ */

SRCC = Mandatory/client.c

SRCS = 	Mandatory/server.c \
		Mandatory/server_utils.c

BSRCC = Bonus/client_bonus.c

BSRCS = Bonus/server_bonus.c \
		Bonus/server_utils_bonus.c

OBJC = ${SRCC:.c=.o}

OBJS = ${SRCS:.c=.o}

BOBJC = ${BSRCC:.c=.o}

BOBJS = ${BSRCS:.c=.o}

NAME_C = client

NAME_S = server

BNAME_C = client_bonus

BNAME_S = server_bonus

LIBFT = ./Libft/libft.a

FLAGS = -Wall -Werror -Wextra -g 

RM = rm -rf

all: ${NAME_C} ${NAME_S}

.c.o:
	@gcc ${FLAGS} -c $< -o $@

${LIBFT}:
		@make -C ./Libft --no-print-directory
		

${NAME_C}: ${OBJC} ${LIBFT}
		@gcc ${FLAGS} ${OBJC} ${LIBFT} -o ${NAME_C}
		@echo ${GREEN}"compilation client complete"${EOC}

${NAME_S}: ${OBJS} ${LIBFT}
		@gcc ${FLAGS} ${OBJS} ${LIBFT} -o ${NAME_S}
		@echo ${GREEN}"compilation server complete"${EOC}
clean:
		@make -C ./Libft clean --no-print-directory
		@${RM} ${OBJC}
		@${RM} ${OBJS}
		@${RM} ${BOBJC}
		@${RM} ${BOBJS}
		@echo ${YELLOW}"clean ok"${EOC}

fclean: clean
		@${RM} ${LIBFT}
		@${RM} ${NAME_C}
		@${RM} ${NAME_S}
		@${RM} ${BNAME_C}
		@${RM} ${BNAME_S}
		@echo ${YELLOW}"fclean ok"${EOC}

re: fclean all

bonus: ${BNAME_C} ${BNAME_S}

${BNAME_C}: ${BOBJC} ${LIBFT}
		@gcc ${FLAGS} ${BOBJC} ${LIBFT} -o ${BNAME_C}
		@echo ${GREEN}"compilation client_bonus complete"${EOC}

${BNAME_S}: ${BOBJS} ${LIBFT}
		@gcc ${FLAGS} ${BOBJS} ${LIBFT} -o ${BNAME_S}
		@echo ${GREEN}"compilation server_bonus complete"${EOC}


.PHONY: clean fclean re all

