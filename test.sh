#!/bin/bash

make
./encoder/encoder.bin "Hello World" >out | ./decoder/decoder.bin
