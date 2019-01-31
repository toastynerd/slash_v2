INC = -I../include
OBJ = main.c init.c game_map.c texture.c render.c map_generation.c
SRCS = $(OBJ:%.o=%.c)

all: slash

slash: $(SRCS)
	gcc -o $@ $(CFLAGS) $(LIB) $(INC) $(SRCS)

clean:
	rm -rf *.o
