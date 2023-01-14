#!/bin/bash

make
./enconder/encoder.bin "Hello World"
./decoder/decoder.bin
