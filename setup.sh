#! /bin/bash
	git submodule init --recursive --remote
	git submodule update --recursive --remote	
		mv lmdb ../
		mv c-protobuf ../
		mv c-multihash ../
		mv c-multiaddr ../
		mv c-libp2p ../
		cd ..	
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
		make all
		cd ..
	cd c-ipfs
	make all

