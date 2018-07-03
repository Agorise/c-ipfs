#include <stdlib.h>
#include <string.h>

#include "ipfs/multibase/multibase.h"
#include "libp2p/crypto/encoding/base58.h"
#include "libp2p/crypto/encoding/base16.h"

/**
 * Encode data in multibase format. NOTE: currently only supports MULTIBASE_BASE58_BTC and MULTIBASE_BASE16
 * @param base the format to use (i.e. MULTIBASE_BASE58_BTC)
 * @param incoming the data to encode
 * @param incoming_length the length of the data to encode
 * @param results where to put the results
 * @param results_max_length the size of the results buffer
 * @param results_length the size of the results after being encoded
 * @returns true(1) on success
 */
int multibase_encode(const char base, const unsigned char* incoming, size_t incoming_length, unsigned char* results, size_t results_max_length, size_t* results_length) {
	*results_length = results_max_length;
	int retVal = 0;

	switch (base) {
		case (MULTIBASE_BASE58_BTC):
			retVal = libp2p_crypto_encoding_base58_encode(incoming, incoming_length, &results, results_length);
			break;
		case(MULTIBASE_BASE16):
			retVal = libp2p_crypto_encoding_base16_encode(incoming, incoming_length, results, results_length);
			break;
		defalt: // unsupported format
			return 0;
	}
	// check to see if there was a problem
	if (retVal == 0)
		return 0;

	// we have the hash, now add the code to the first byte (if there is room)

	if (*results_length >= results_max_length) { // It could be equal, but should never be greater. But just in case.
		return 0; // buffer isn't big enough
	}

	memcpy(&results[1], results, *results_length);
	results[0] = base;
	*results_length += 1;

	return 1;
}

/***
 * Calculates the size of the buffer neccessary to encode the incoming byte array
 * @param base the encoding to use
 * @param incoming the incoming array of bytes
 * @param incoming_length the length of the array in bytes
 * @returns the appropriate size of the buffer
 */
int multibase_encode_size(const char base, const unsigned char* incoming, size_t incoming_length) {
	switch (base) {
	case (MULTIBASE_BASE58_BTC):
			return libp2p_crypto_encoding_base58_encode_size(incoming_length) + 1;
	case (MULTIBASE_BASE16):
			return libp2p_crypto_encoding_base16_encode_size(incoming_length);
	}
	return 0;
}

/**
 * Decode data that was encoded in multibase format
 * @param incoming the data to decode
 * @param incoming_length the length of the data to decode
 * @param results where to put the results
 * @param results_max_length the size of the results buffer
 * @param results_length the size of the results after being encoded
 * @returns true(1) on success
 */
int multibase_decode(const unsigned char* incoming, size_t incoming_length, unsigned char* results, size_t results_max_length, size_t* results_length) {
	*results_length = results_max_length;
	int retVal = 0;

	const char base = incoming[0];

	switch (base) {
		case (MULTIBASE_BASE58_BTC):
			retVal = libp2p_crypto_encoding_base58_decode(&incoming[1], incoming_length - 1, &results, results_length);
			break;
		case(MULTIBASE_BASE16):
			retVal = libp2p_crypto_encoding_base16_decode(&incoming[1], incoming_length - 1, results, results_length);
			break;
		default: // unsupported format
			return 0;
	}
	// check to see if there was a problem
	if (retVal == 0)
		return 0;

	return 1;
}

/***
 * Calculates the size of the buffer neccessary to decode the incoming byte array
 * @param base the encoding to use
 * @param incoming the incoming array of bytes
 * @param incoming_length the length of the array in bytes
 * @returns the appropriate size of the buffer
 */
int multibase_decode_size(const char base, const unsigned char* incoming, size_t incoming_length) {
	switch (base) {
	case (MULTIBASE_BASE58_BTC):
			return libp2p_crypto_encoding_base58_decode_size(incoming_length) + 1;
	case (MULTIBASE_BASE16):
			return libp2p_crypto_encoding_base16_decode_size(incoming_length);
	}
	return 0;
}
