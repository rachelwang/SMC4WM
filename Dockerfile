FROM gcc:8.0

RUN mkdir -p /smc4wm

# Checkout transfer learning code
WORKDIR /smc4wm
RUN git clone https://github.com/rachelwang/SMC4WM.git

WORKDIR /usr/local/bin

# Change `app` to whatever your binary is called
#Add app .
#CMD ["./app"]
