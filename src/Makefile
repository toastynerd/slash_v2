INC = -I../include
OBJ = main.c
SRCS = $(OBJ:%.o=%.c)

all: slash

slash: $(SRCS)
	gcc -o $@ $(CFLAGS) $(LIB) $(INC) $(SRCS)

clean:
	rm -rf *.o
