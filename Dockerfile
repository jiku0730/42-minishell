FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive
ARG VALGRIND_VERSION=3.21.0

RUN apt-get update && \
    apt-get install -y \
    build-essential \
    libreadline-dev \
    clang \
    git \
    curl \
    wget \
    ca-certificates \
    python3.10 \
    python3-pip \
    python3.10-venv \
    python3.10-distutils \
    libtool \
    automake \
    autoconf \
    libc6-dbg \
    && apt-get clean && rm -rf /var/lib/apt/lists/* /var/cache/apt/archives/*

RUN wget https://sourceware.org/pub/valgrind/valgrind-${VALGRIND_VERSION}.tar.bz2 && \
    tar -xjf valgrind-${VALGRIND_VERSION}.tar.bz2 && \
    cd valgrind-${VALGRIND_VERSION} && \
    ./configure && \
    make -j$(nproc) && \
    make install && \
    cd .. && rm -rf valgrind*

RUN python3.10 -m pip install --upgrade pip && \
    python3.10 -m pip install norminette
