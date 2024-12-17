NAME	=	printf.a

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f

INCDIR	=	./includes
SRCDIR	=	./srcs

# ソースファイルリスト
SRCS_LIST = 	ft_printf.c \
				ft_putchar.c \
				ft_putnbr.c \
				ft_putstr.c \
				ft_vprintf.c

# ソースファイルへのフルパス
SRCS = $(addprefix $(SRCDIR)/, $(SRCS_LIST))

# オブジェクトファイルのリスト
OBJS = $(SRCS:.c=.o)

# ルール: .cファイルを.oファイルにコンパイル
.c.o:
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $(<:.c=.o)

# ルール: ライブラリを作成
$(NAME): $(OBJS)
	@echo "Compiling $(NAME)"
	ar -rcs $(NAME) $(OBJS)
	@echo "==== DONE ===="

# すべてのターゲット
all: $(NAME)

# クリーンルール: 中間ファイルの削除
clean:
	$(RM) $(OBJS)

# フルクリーンルール: 生成ファイルの削除
fclean: clean
	$(RM) $(NAME)

# 再ビルドルール
re: fclean all

# phonyターゲット
.PHONY: all clean fclean re
