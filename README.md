# Development of a Data Analysis and Compression Application

## Concepts

In order to do this project I had to learn some new concepts:

1. [Encoding and decoding](https://github.com/42sp/42labs-selection-process-v4-sgkhusal#1-encoding-and-decoding)
2. [Data Compression](https://github.com/42sp/42labs-selection-process-v4-sgkhusal#2-data-compression)
3. Huffman Coding and Huffman Tree
4. Use of shared memory between programs

### 1. Encoding and decoding

In computers, encoding is the process of putting a sequence of characters into a specialized format for efficient transmission or storage.

Decoding is the opposite process: the conversion of an encoded format back into the original sequence of characters.

PS: these terms should not be confused with encryption and decryption, which focus on hiding and securing data. (We can encrypt data without changing the code or encode data without deliberately concealing the content.)

### 2. Data compression

Data compression is the process of encoding information using fewer bits than the original representation.
For example, each character from ASCII table is represented by 8 bits, or 1 byte - a sequence of zeros and ones. So a text (a sequence of characters) is also a big sequence of zeros and ones. The text compression aims to reduce this amount of zeros and ones, so that you need less bits to store the same information.

Compression reduces the resources required to store and transmit data (which implies in gaining performance, decreasing the time where these transmissions take place).

A device that performs data compression is an encoder, and one that performs the reversal of the process (decompression) is a decoder.

#### A compression can be lossy or lossless:

- Lossless compression reduces bits by identifying and eliminating redundancy. For example, the sequence "AAAAAA" (6 bytes) could be represented by the sequence "6A" (only 2 bytes). No information is lost in lossless compression. Text compression has to be losslessly.
- Lossy compression reduces bits by removing unnecessary or less important information. For example, for  music, videos and images compression some informations are not relevant and can be lost in the process.

### 3. Huffman Coding and Huffman Tree

Huffman coding is the basic foundation of modern text compression. It uses the frequencies of the charcarters in the data set to be compressed to determine variable length codes for each charcarter. Some charcarters will end up with less than 8 bits (the characters that are used very often) and others with more than 8 bits (the characters that are not used very often).

Here are the steps for the algorithm:

1. Count how many times each character is used
2. Order them in a list from the most used to the least used
3. Create the Huffman Tree:
- Put the 2 least used characters in the bottom branches and sum their frequencies into the top branch
- Add the node sum back to the list, in the right order
- Repeat the process until you have only one character on the list
4. Create the encoding/translation table according with the Huffman Tree

The Huffman Tree tells how to convert the text into ones and zeros: to know the sequence, you begin on the top and follow the path down:
- each time you take the left hand side, write 0
- each time you take the right hand side, write 1

***put some nice picture example***

5. Encode the text using the table  ***bitwise?***

## Decoding
There is no ambiguity in Huffman Coding: the bit sequences are assigned in such a way that the bits assigned to one character is not the prefix of bits assigned to any other character. This because the variable-length bit sequences assigned to the characters are [Prefix Codes](https://en.wikipedia.org/wiki/Prefix_code).

### 4. Use of shared memory between programs

### Sources:
1. [encoding and decoding](https://www.techtarget.com/searchnetworking/definition/encoding-and-decoding)
2. [Data compression](https://en.wikipedia.org/wiki/Data_compression)
3. [How Computers Compress Text: Huffman Coding and Huffman Trees](https://www.youtube.com/watch?v=JsTptu56GM8)
4. [Huffman Coding](https://www.geeksforgeeks.org/huffman-coding-greedy-algo-3/)
