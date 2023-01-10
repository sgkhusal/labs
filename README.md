# Development of a Data Analysis and Compression Application

## Concepts

In order to do this project I had to learn some new concepts:

1. Encoding and decoding
2. Data Compression
3. Huffman Coding
4. Use of shared memory between programs

### 1. Encoding and decoding

In computers, encoding is the process of putting a sequence of characters into a specialized format for efficient transmission or storage.

Decoding is the opposite process: the conversion of an encoded format back into the original sequence of characters.

PS: these terms should not be confused with encryption and decryption, which focus on hiding and securing data. (We can encrypt data without changing the code or encode data without deliberately concealing the content.)

### 2. Data compression

Data compression is the process of encoding information using fewer bits than the original representation. Compression is useful because it reduces the resources required to store and transmit data.

A device that performs data compression is an encoder, and one that performs the reversal of the process (decompression) is a decoder.

A compression can be lossy or lossless:
- Lossless compression reduces bits by identifying and eliminating redundancy. For example, the sequence "AAAAAA" (6 bytes) could be represented by the sequence "6A" (only 2 bytes). No information is lost in lossless compression.
- Lossy compression reduces bits by removing unnecessary or less important information. For example, for  music, videos and images compression some informations are not relevant and can be lost in the process.

### Sources:
1. [encoding and decoding](https://www.techtarget.com/searchnetworking/definition/encoding-and-decoding)
2. [Data compression](https://en.wikipedia.org/wiki/Data_compression)
