#!/bin/bash

echo "Running emcmake..."
emcmake cmake -B build -S .

echo "Running emmake..."
emmake make -C build
