# C-IPFS
IPFS implementation in C.

## Quick start for users:
* **ipfs init** to create an ipfs repository on your machine
* **ipfs add MyFile.txt** to add a file to the repository, will return with a hash that can be used to retrieve the file.
* **ipfs cat _hash_** to retrieve a file from the repository

## For techies (ipfs spec docs):
* [getting started](https://github.com/ipfs/specs/blob/master/overviews/implement-ipfs.md)
* [specifications](https://github.com/ipfs/specs)
* [getting started](https://github.com/ipfs/community/issues/177)
* [libp2p](https://github.com/libp2p/specs)

## Prerequisites: To compile the C version you will need:
* [lmdb](https://github.com/jmjatlanta/lmdb)
* [c-protobuf](https://github.com/Agorise/c-protobuf)
* [c-multihash](https://github.com/Agorise/c-multihash)
* [c-multiaddr](https://github.com/Agorise/c-multiaddr)
* [c-libp2p](https://github.com/Agorise/c-libp2p)

And of course this project at https://github.com/Agorise/c-ipfs

The compilation at this point is simple, but not very flexible. Place all of these projects in a directory. Compile all (the order above is recommended) by going into each one and running "make all".
