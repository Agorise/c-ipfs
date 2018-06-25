#! /bin/bash
	
	git clone https://www.github.com/chronaeon/c-ipfs.git
	git clone https://github.com/jmjatlanta/lmdb.git
	git clone https://github.com/Agorise/c-protobuf.git
	git clone https://github.com/Agorise/c-multihash.git
	git clone https://github.com/Agorise/c-multiaddr.git
	git clone https://github.com/Agorise/c-libp2p.git
		
	cd lmdb/libraries/liblmdb
		make all
		cd ..
		cd ..
		cd ..
	cd c-protobuf
		make all
		cd ..
	cd c-multihash
		make all
		cd ..
	cd c-multiaddr
		make all
		cd ..
	cd c-libp2p
		cd ..
make all
		
