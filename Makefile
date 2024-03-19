CC = gcc
CFLAGS = -Wall
LDFLAGS = 
LDLIBS = -lm

SRCS := main.c vec_math.c raytracer.c raytracer.h shapes.h vec_math.h
OBJS := $(patsubst %.c,build/%.o,$(SRCS)) 
EXECUTABLE := rundle

all: build/$(EXECUTABLE)

build/main.o: main.c
    # Compile the main.c source file into an object file in build/main.o using the $(CC) compiler and flags specified by $(CFLAGS).
    $(CC) $(CFLAGS) -c $< -o $@

build/vec_math.o: vec_math.c vec_math.h 
    # Compile the vec_math.c source file into an object file in build/vec_math.o using the $(CC) compiler and flags specified by $(CFLAGS).
    $(CC) $(CFLAGS) -c $< -o $@

build/raytracer.o: raytracer.c raytracer.h vec_math.h shapes.h
    # Compile the raytracer.c source file into an object file in build/raytracer.o using the $(CC) compiler and flags specified by $(CFLAGS).
    $(CC) $(CFLAGS) -c $< -o $@

$(EXECUTABLE): $(OBJS)
    # Link all the object files specified by $(OBJS) together to form a final executable called rundle using the $(CC) compiler, linking any libraries specified in $(LDLIBS).
    echo "Linking" $@
    $(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJS) $(LDLIBS)

$(OBJS): build/%.o : %.c
    # Compile any source file into its corresponding .o object file using the $(CC) compiler and flags specified by $(CFLAGS).
    $(CC) $(CFLAGS) -c $< -o $@

clean:
    rm -f build/*.o build/*.d build/rundle

rebuild: clean all
    # Rebuild all object files by first cleaning them using the "clean" target defined above.
