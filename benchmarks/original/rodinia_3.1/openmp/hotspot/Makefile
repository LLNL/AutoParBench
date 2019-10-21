# C compiler
CC_FLAGS = -g -fopenmp
OFFLOAD_CC_FLAGS = -offload-option,mic,compiler,"-no-opt-prefetch"

#all: hotspot hotspot_offload 
all: hotspot 


hotspot: hotspot_openmp.cpp Makefile 
	$(CC) $(CC_FLAGS) hotspot_openmp.cpp -o hotspot 

clean:
	rm -f hotspot hotspot_offload
