CC = gcc
CFLAGS = -Wall
LDFLAGS = 
LDLIBS = -lm

SRCS := main.c vec_math.c raytracer.c
OBJS := $(SRCS:%.c=build/%.o)
EXECUTABLE := rundle

all: build/$(EXECUTABLE)

build/$(EXECUTABLE): $(OBJS)
	@echo "Linking" $@
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJS) $(LDLIBS)

build/%.o: %.c
	@echo "Compiling" $<
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f build/*.o build/$(EXECUTABLE)

rebuild: clean all
