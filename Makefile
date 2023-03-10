#	Compilation setting

NAME	=	parsmath

CC		=	g++
DB		=	lldb

CFLAGS	=	-Wall
CFLAGS	+=	-Wextra
CFLAGS	+=	-Werror
CFLAGS	+=	-g
CFLAGS	+=	-Wfatal-errors
CFLAGS	+=	-std=c++98

OFLAGS	=	-fsanitize=address


#	Sources

SRCD	=	srcs

SRCS	=	$(SRCD)/main.cpp
SRCS	+=	$(SRCD)/color.cpp

SRCS	+=	$(SRCD)/Input.cpp
SRCS	+=	$(SRCD)/Tokenizer.cpp

SRCS	+=	$(SRCD)/TreeNode.cpp
SRCS	+=	$(SRCD)/Infix.cpp

SRCS	+=	$(SRCD)/Add.cpp
SRCS	+=	$(SRCD)/Subtract.cpp
SRCS	+=	$(SRCD)/Mult.cpp
SRCS	+=	$(SRCD)/Div.cpp

SRCS	+=	$(SRCD)/Number.cpp


#	Headers

INCD	=	headers

INCS	=	$(INCD)/color.hpp

INCS	+=	$(INCD)/Input.hpp
INCS	+=	$(INCD)/Tokenizer.hpp

INCS	+=	$(INCD)/TreeNode.hpp
INCS	+=	$(INCD)/Infix.hpp

INCS	+=	$(INCD)/Add.hpp
INCS	+=	$(INCD)/Subtract.hpp
INCS	+=	$(INCD)/Mult.hpp
INCS	+=	$(INCD)/Div.hpp

INCS	+=	$(INCD)/Number.hpp


#	Objets

OBJD	=	objs
OBJS	=	$(addprefix $(OBJD)/, $(notdir $(SRCS:.cpp=.o)))

RM		=	rm -rf

vpath %.cpp $(SRCD):$(SRCD)/class


all : $(NAME)

$(NAME):	$(OBJS)
	@printf "$(YELLOW)Creating executable..$(DEFAULT)\n"
	@$(CC) $(OBJS) $(OFLAGS) $(CLIB) -o $(NAME)
	@printf "$(GREEN)---> $(NAME) is ready$(DEFAULT)\n"

$(OBJD)/%.o : %.cpp | $(OBJD)
	@printf "$(YELLOW)Compiling $(DEFAULT)$<\n"
	@$(CC) $(CFLAGS) -I$(INCD) -o $@ -c $<

$(OBJD) :
	@mkdir -p $(OBJD)

clean:
	@$(RM) $(OBJD)
	@printf "$(RED)Removed $(CYAN)$(OBJD)$(DEFAULT)\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "$(RED)Removed $(CYAN)$(NAME)$(DEFAULT)\n"

re:	fclean all


db: all
	$(DB) $(NAME)

format:
	@cat $(SRCS) $(INCS) > /tmp/before
	@clang-format -i $(SRCS) $(INCS)
	@cat $(SRCS) $(INCS) > /tmp/after
	@diff -u --color=auto /tmp/before /tmp/after || true


diagram:
	asciidoctor -r asciidoctor-diagram assets/README.adoc -o assets/index.html

doc: diagram
	asciidoctor README.adoc -o index.html

.PHONY: all clean fclean libclean fullclean

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
CYAN = \033[1;36m
DEFAULT = \033[0m
