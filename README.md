# Development of a Data Analysis and Compression Application

## Concepts

In order to do this project I had to learn some new concepts:

1. [Encoding and decoding](https://github.com/42sp/42labs-selection-process-v4-sgkhusal#1-encoding-and-decoding)
2. [Data Compression](https://github.com/42sp/42labs-selection-process-v4-sgkhusal#2-data-compression)
3. [Huffman Coding](https://github.com/42sp/42labs-selection-process-v4-sgkhusal/edit/master/README.md#3-huffman-coding)
4. [Use of shared memory between programs](https://github.com/42sp/42labs-selection-process-v4-sgkhusal#4-use-of-shared-memory-between-programs)

### 1. Encoding and decoding

In computers, encoding is the process of putting a sequence of characters into a specialized format for efficient transmission or storage.

Decoding is the opposite process: the conversion of an encoded format back into the original sequence of characters.

PS: these terms should not be confused with encryption and decryption, which focus on hiding and securing data. (We can encrypt data without changing the code or encode data without deliberately hiding the content.)

### 2. Data compression

Data compression is the process of encoding information using fewer bits than the original representation.

For example, each character from ASCII table is represented by 8 bits, or 1 byte - a sequence of zeros and ones. So a text (a sequence of characters) is also a big sequence of zeros and ones. The text compression aims to reduce this amount of zeros and ones, so that you need less bits to store the same information.

Compression reduces the resources required to store and transmit data (which implies in gaining performance, decreasing the time of the transmissions).

A device that performs data compression is an encoder, and one that performs the reversal of the process (decompression) is a decoder.

#### A compression can be lossy or lossless:

- Lossless compression reduces bits by identifying and eliminating redundancy. For example, the sequence "AAAAAA" (6 bytes) could be represented by the sequence "6A" (only 2 bytes). No information is lost in lossless compression. Text compression has to be losslessly.
- Lossy compression reduces bits by removing unnecessary or less important information. For example, for  music, videos and images compression some informations are not relevant and can be lost in the process.

### 3. Huffman Coding

Huffman coding is the basic foundation of modern text compression. It uses the frequencies of the charcarters in the data set to be compressed to determine variable length codes for each charcarter. Some charcarters will end up with less than 8 bits (the characters that are used very often) and others with more than 8 bits (the characters that are not used very often).

#### Compression process

Here are the steps for the compression process:

1. Count how many times each character is used
# ***********************************************put some nice picture example
2. Order them in a linked list from the least used to the most used
# ***********************************************put some nice picture example
3. Create the Huffman Tree:
- Remove the 2 least used characters in the list (the two on the top), and create a new node for the tree and add their frequencies as the frequency (weight) of the node.
# ***********************************************put some nice picture example
- Add the node sum back to the list, in the sort order
# ***********************************************put some nice picture example
- Repeat the process until you have only one node on the list
# ***********************************************put some nice picture example
4. Create the encode table/dictionary using the Huffman Tree - the sequence of ones and zeros for each character

The Huffman Tree tells how to convert the text into ones and zeros: to know the sequence, you begin on the top and follow the path down:
- each time you take the left hand side, write 0
- each time you take the right hand side, write 1

# ***********************************************put some nice picture example

There is no ambiguity in Huffman Coding: the bit sequences are assigned in such a way that the bits assigned to one character is not the prefix of bits assigned to any other character. This because the variable-length bit sequences assigned to the characters are [Prefix Codes](https://en.wikipedia.org/wiki/Prefix_code).

5. Encode the text using the encode table
# ***********************************************put some nice picture example
6. Compress the encoded data putting each zero and one from the encoded string into bits
# ***********************************************put some nice picture example

#### Decompression process

For the decompress process we have the following steps:

7. Decompress the data converting the bits into one string of zeros and ones. It is the reverse process from step 6.
# ***********************************************put some nice picture example

8. Decode the string os zeros and ones into the original text. Here we use the Huffman Tree again instead of the encode table. This because it is not easy to know when a word begins or ends and we don't know how many characters are encoded. The Huffman Tree here works like magic!
# ***********************************************put some nice picture example

### 4. Use of shared memory between programs

### Sources:
1. [encoding and decoding](https://www.techtarget.com/searchnetworking/definition/encoding-and-decoding)
2. [Data compression](https://en.wikipedia.org/wiki/Data_compression)
3. [How Computers Compress Text: Huffman Coding and Huffman Trees](https://www.youtube.com/watch?v=JsTptu56GM8)
4. [Huffman Coding](https://www.geeksforgeeks.org/huffman-coding-greedy-algo-3/)
5. [Como comprimir dados com Código de Huffman](https://www.youtube.com/watch?v=o8UPZ_KDWdU&list=PLqJK4Oyr5WShtxF1Ch3Vq4b1Dzzb-WxbP&index=1)
