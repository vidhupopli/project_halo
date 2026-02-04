#!/bin/bash

echo "Deleting existing build folder..."
rm -rf build

echo "Making build folder..."
mkdir build

echo "Running emcmake..."
emcmake cmake -B build -S .

echo "Running emmake..."
emmake make -C build
