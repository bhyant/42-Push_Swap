# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbhuiyan <tbhuiyan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/22 00:00:00 by tbhuiyan          #+#    #+#              #
#    Updated: 2025/10/23 22:26:17 by tbhuiyan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap
CC				= cc
CFLAGS			= -Wall -Wextra -Werror -MMD -MP -g3
RM				= rm -f

OBJDIR			= .objs
INC_DIR			= includes
LIBFT_DIR		= libft
LIBFT			= $(LIBFT_DIR)/libft.a

SRCS_CMD		= srcs/commands/push.c \
				  srcs/commands/reverse_rotate.c \
				  srcs/commands/rotate.c \
				  srcs/commands/swap.c

SRCS_PARSING	= srcs/parsing/create_array.c \
				  srcs/parsing/parsing.c

SRCS_SORT		= srcs/sort/choose_sort.c \
				  srcs/sort/radix_sort.c

SRCS_UTILS		= srcs/utils/clean_utils.c \
				  srcs/utils/lst_utils.c \
				  srcs/utils/lst_utils2.c \
				  srcs/utils/parsing_utils.c \
				  srcs/utils/sort_utils.c

SRCS_MAIN		= srcs/push_swap.c

ALL_SRCS		= $(SRCS_CMD) $(SRCS_PARSING) $(SRCS_SORT) $(SRCS_UTILS) $(SRCS_MAIN)

OBJS			= $(ALL_SRCS:%.c=$(OBJDIR)/%.o)
DEPS			= $(ALL_SRCS:%.c=$(OBJDIR)/%.d)

.PHONY: all clean fclean re

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "✅ push_swap created successfully!"

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIBFT_DIR)/includes -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@$(RM) -r $(OBJDIR)
	@make -C $(LIBFT_DIR) clean
	@echo "🧹 push_swap objects cleaned!"

fclean: clean
	@$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "🗑️  push_swap removed!"

re: fclean all

-include $(DEPS)
