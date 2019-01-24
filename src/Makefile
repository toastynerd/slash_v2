INC = -I../include
OBJ = main.c init.c game_map.c texture.c render.c
SRCS = $(OBJ:%.o=%.c)

all: slash

slash: $(SRCS)
	gcc -g -o $@ $(CFLAGS) $(LIB) $(INC) $(SRCS)

clean:
	rm -rf *.o
