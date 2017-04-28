#	Library output
NAME = ft_ls

#	GCC flags
CFLAGS =  -Weverything
#	Includes directories
INC_TR = includes
INCLUDES += $(addprefix -iquote , $(INC_TR))

#	Sources
FT_LS_SOURCES = $(shell find src | grep "\.c$$" | sed "s/\.c$$//g")
FT_LS_HEADERS = $(shell find includes | grep "\.h$$")
SRCS = $(addsuffix .c, $(FT_LS_SOURCES))
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo ">>>>> Génération de FT_LS"
	@gcc $(OBJS) -o $(NAME)
	@echo "Terminée"

# To obtain object files
%.o: %.c $(FT_LS_HEADERS)
	@$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

# To remove generated files
clean:
	@echo "RM\ttous les objects (.o)"
	@$(RM) $(OBJS)

fclean: clean
	@echo "RM\tprojet ($(NAME))"
	@$(RM) $(NAME)

re: fclean all

git:
	@git add .
	@echo "Enter Your Commit :"
	@read var1 ; git commit -m "$$var1"
	@git push
