NAME = fdf
SRCSFOLDER = ./srcs/
SRCS = main.c hextocolor.c projection.c switchcolor.c error.c switchcamtype.c readfile.c ui.c readcollors.c fdfrotate.c view.c drawlinelerp.c draw.c drawmap.c inputinit.c mouseclick.c presskey1.c presskey2.c
OBJNAME = $(SRCS:.c=.o)
OBJDIR = ./obj/
OBJ = $(addprefix $(OBJDIR),$(OBJNAME))
INCLUDES = ./includes/
GCCFLAG = -Wall -Wextra -Werror
BUILDFOLDER = ./build/

GRAPHICSFOLDER = ./ft_graphics/
GRAPHICSINCLUDES = $(GRAPHICSFOLDER)includes/
GRAPHICSINK = -I $(GRAPHICSINCLUDES) -L $(GRAPHICSFOLDER) -lftgraphics

LIBFTFOLDER = ./libft/
LIBFTINCLUDES = $(LIBFTFOLDER)
LIBFTINK = -I $(LIBFTINCLUDES) -L $(LIBFTFOLDER) -lft

MLXLINKLINUX = -I /usr/local/include -L /usr/local/lib -lmlx -lXext -lX11 -lm
MLXLINTMACOS = -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(GRAPHICSFOLDER)
	$(MAKE) -C $(LIBFTFOLDER)
	gcc $(GCCFLAG) $(OBJ) $(MLXLINTMACOS) $(GRAPHICSINK) $(LIBFTINK) -o $(NAME)

debugmacos: $(OBJ)
	if [ ! -d $(BUILDFOLDER) ]; then \
		mkdir $(BUILDFOLDER); \
	fi
	$(MAKE) -C $(GRAPHICSFOLDER)
	$(MAKE) -C $(LIBFTFOLDER)
	gcc -g $(GCCFLAG) $(OBJ) $(MLXLINTMACOS) $(GRAPHICSINK) $(LIBFTINK) -I $(INCLUDES) -o $(BUILDFOLDER)$(NAME)

debuglinux: $(OBJ)
	if [ ! -d $(BUILDFOLDER) ]; then \
		mkdir $(BUILDFOLDER); \
	fi
	$(MAKE) -C $(GRAPHICSFOLDER)
	$(MAKE) -C $(LIBFTFOLDER)
	gcc -g $(GCCFLAG) $(OBJ) $(GRAPHICSINK) $(MLXLINKLINUX) $(LIBFTINK) -I $(INCLUDES) -o $(BUILDFOLDER)$(NAME)

clean:
	$(MAKE) -C $(GRAPHICSFOLDER) clean
	$(MAKE) -C $(LIBFTFOLDER) clean
	rm -rf $(OBJDIR)
	rm -rf *.o

fclean: clean
	$(MAKE) -C $(GRAPHICSFOLDER) fclean
	$(MAKE) -C $(LIBFTFOLDER) fclean
	rm -rf $(BUILDFOLDER)
	rm -rf $(NAME)

$(OBJDIR)%.o:$(SRCSFOLDER)%.c
	@mkdir -p $(OBJDIR)
	@gcc $(GCCFLAG) -I $(INCLUDES) -o $@ -c $<

re:	fclean $(NAME)

re_d_macos: fclean debugmacos

re_d_linux: fclean debuglinux

makegraphics:
	$(MAKE) -C $(GRAPHICSFOLDER)

makeft:
	$(MAKE) -C $(LIBFTFOLDER)
	
