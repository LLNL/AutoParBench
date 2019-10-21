# STAGE 1: build PRAGMA FINDER
FROM ubuntu:bionic as build

ENV ROOT_FOLDER="/usr/src"
ENV PYSCRIPTS_PATH="${ROOT_FOLDER}/PYSCRIPTS"

# install build dependencies
RUN apt-get update
RUN apt-get install -y make vim cmake gcc-8 g++-8 git wget python zip unzip libomp-dev python-pip
RUN apt-get -y upgrade

WORKDIR /usr/src

# install python libraries
RUN pip install pandas
RUN python -mpip install matplotlib
RUN apt-get -y install apt-utils
RUN python -m pip install plotnine
RUN DEBIAN_FRONTEND=noninteractive apt-get install dialog -y
RUN DEBIAN_FRONTEND=noninteractive apt-get -y -q install python-tk

#NOTE: Remove the token when AutoParBench be a public repository
RUN git clone https://gleisonsdm:78e48c089ce620d071324e3d202546b457f9e8b9@github.com/chunhualiao/AutoParBench.git ${PYSCRIPTS_PATH}

#Go back to root folder
WORKDIR /root
