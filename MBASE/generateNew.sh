#!/bin/bash

BASE_PATH=$HOME/Documents/Maratona/BASE
CURRENT_PATH=${PWD}

mkdir ${1}

cp $BASE_PATH/Makefile $CURRENT_PATH/${1}/
cp $BASE_PATH/0000.cpp $CURRENT_PATH/${1}/${1}.cpp

sed -i "s/0000/${1}/g" $CURRENT_PATH/${1}/Makefile

