NAME	= libasm.a
TEST	= tests

FILES	= ft_strlen ft_strcpy
MAIN	= main

CC		= cc
NASM	= nasm
CFLAGS	= -Wall -Wextra -Werror
ASFLAGS	= -f elf64

SRC_DIR	= src/
OBJ_DIR	= obj/

SRCS 	= $(addprefix $(SRC_DIR), $(addsuffix .s, $(FILES)))
OBJS 	= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES))) $(OBJ_DIR)$(MAIN).o
S_MAIN	= $(SRC_DIR)$(MAIN).c
O_MAIN	= $(OBJ_DIR)$(MAIN).o


all: $(NAME)
test: $(TEST)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

$(TEST): $(OBJS) $(O_MAIN)
	$(CC) -o $@ $(OBJS)

obj/%.o: src/%.s
	mkdir -p $(dir $@)
	$(NASM) $(ASFLAGS) -o $@ $<

$(O_MAIN): $(S_MAIN)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm $(NAME) $(tests)

re: fclean all