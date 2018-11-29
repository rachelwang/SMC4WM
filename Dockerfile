FROM library/gcc:8.2

# Checkout transfer learning code
WORKDIR /
RUN git clone https://github.com/rachelwang/SMC4WM.git

# Update and install cmake
RUN apt-get update -y && \
    apt-get update && \
    apt-get install cmake -y && \
    apt-get update && \
    apt-get install libboost-all-dev -y && \
    apt-get install libgsl0-dev -y
    
# Set environment variabes for CMake
ENV CC /usr/local/bin/gcc
ENV CXX /usr/local/bin/g++

# Buid and test smc4wm
RUN ln -s /usr/local/bin/g++ /usr/local/bin/g++-8 && \
    cd SMC4WM && \
    mkdir build && \
    cd build  && \
    cmake ../src && \
    make

# Test smc4wm
WORKDIR /SMC4WM/build
RUN ./SMC_wm -testfile ../testcase/test -modelfile ../testcase/cra_cag_to_praise_code.dat -propfile ../testcase/prop -interfile ../testcase/intervention

