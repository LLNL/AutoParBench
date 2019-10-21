# C compiler
CC_FLAGS = -g -fopenmp

all: bfs bfs_offload

bfs: bfs.cpp 
	$(CXX) $(CC_FLAGS) bfs.cpp -o bfs 

bfs_offload: bfs.cpp
	$(ICC) $(CC_FLAGS) bfs.cpp -o bfs_offload

clean:
	rm -f bfs bfs_offload result.txt
