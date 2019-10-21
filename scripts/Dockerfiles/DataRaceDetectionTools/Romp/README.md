How to use this docker image


# compile the code 

sudo docker run --rm -it -v $(pwd):/root gleisonsdm/romp:latest /usr/src/llvm-build/bin/clang -g -O0 -L/usr/src/romp//pkgs-src/romp-lib/lib -L/usr/src/romp/pkgs-src/gperftools/gperftools-install/lib -L/usr/src/romp/pkgs-src/llvm-openmp/openmp/llvm-openmp-install/lib -fopenmp -fpermissive -ltcmalloc <source_code.c> -o program.run


chmod +X program.run

# instrument the code

The next step is run dyninst-client to instrument your binary:
* sudo docker run --rm -it -v $(pwd):/root gleisonsdm/romp:latest /usr/src/romp/pkgs-src/dyninst-client/omp_race_client program.run


This generates a new executable
* instrumented_app

# run it 

The next step is run your binary. You need to run on docker to have access to the libraries needed:
* sudo docker run --rm -it -v $(pwd):/root gleisonsdm/romp:latest ./instrumented_app

