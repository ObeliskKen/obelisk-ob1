#include <stdint.h>
#include <stdio.h>
#include "blake256.h"
#include "dcrverify.h"

int main(void) {
	uint8_t TestOneDCRHeader[180] = {
			0x00, 0x00, 0x00, 0x04, 0xFE, 0x11, 0xF5, 0x1A, 0x98, 0x06, 0xE4, 0x67, 0x00, 0xFE, 0xDC, 0x54,
			0xAE, 0x4B, 0x51, 0xC5, 0x8B, 0x73, 0x6E, 0x50, 0xA6, 0xC6, 0xF6, 0xAB, 0x00, 0x00, 0x01, 0x2B,
			0x00, 0x00, 0x00, 0x00, 0x96, 0x08, 0xD9, 0x48, 0x87, 0x6E, 0xFE, 0x29, 0x7F, 0xF9, 0x33, 0x66,
			0x35, 0x38, 0x09, 0xF4, 0x05, 0xE2, 0xE6, 0x0B, 0x3A, 0xDE, 0x14, 0x10, 0xD6, 0x44, 0x3A, 0x73,
			0x51, 0x87, 0xEE, 0xD1, 0xB1, 0x95, 0x37, 0x3D, 0xC1, 0x11, 0x98, 0x9B, 0x9C, 0x58, 0xB6, 0x72,
			0xED, 0x22, 0x53, 0xEA, 0xBF, 0x86, 0x00, 0x5F, 0x77, 0x37, 0x8A, 0x5D, 0x21, 0xD0, 0xD2, 0x0D,
			0x9E, 0xD2, 0xC4, 0x8F, 0xB4, 0x58, 0x00, 0x01, 0x83, 0xC4, 0xF3, 0x35, 0x00, 0x04, 0x00, 0x05,
			0x00, 0x00, 0xA0, 0x19, 0x1A, 0x01, 0x47, 0x29, 0x60, 0xE1, 0x04, 0x62, 0x00, 0x00, 0x00, 0x01,
			0x00, 0x02, 0x5C, 0x6A, 0x00, 0x00, 0x20, 0x39, 0x59, 0x7B, 0x01, 0x74, 0x76, 0x1D, 0xEE, 0x64,
			0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x04};
	uint8_t TestOneDCRHashResult[32] = {
			0x2E, 0xAB, 0x80, 0x1B, 0x7F, 0xA6, 0x4C, 0xBF, 0x38, 0xAD, 0x99, 0x57, 0xB6, 0x80, 0xC1, 0x9C,
			0x44, 0xA7, 0x5B, 0x3E, 0x2F, 0xFB, 0xD6, 0xEA, 0x30, 0x77, 0x58, 0x34, 0x00, 0x00, 0x00, 0x00,
	};
	uint8_t midstate[32];
	dcrCompressToMidstate(midstate, TestOneDCRHeader);
	bool result = dcrMidstateMeetsMinimumTarget(midstate, (TestOneDCRHeader) + 128);
	if (!result) {
		printf("TEST ONE FAILED\n");
		printf("TEST ONE FAILED\n");
		printf("TEST ONE FAILED\n");
	} else {
		printf("test one passed\n");
	}

	// Same as test one, we are actually testing that it's safe to re-use the
	// midstate in the way that we are re-using it.
	uint8_t TestTwoDCRHeader[180] = {
			0x00, 0x00, 0x00, 0x04, 0xFE, 0x11, 0xF5, 0x1A, 0x98, 0x06, 0xE4, 0x67, 0x00, 0xFE, 0xDC, 0x54,
			0xAE, 0x4B, 0x51, 0xC5, 0x8B, 0x73, 0x6E, 0x50, 0xA6, 0xC6, 0xF6, 0xAB, 0x00, 0x00, 0x01, 0x2B,
			0x00, 0x00, 0x00, 0x00, 0x96, 0x08, 0xD9, 0x48, 0x87, 0x6E, 0xFE, 0x29, 0x7F, 0xF9, 0x33, 0x66,
			0x35, 0x38, 0x09, 0xF4, 0x05, 0xE2, 0xE6, 0x0B, 0x3A, 0xDE, 0x14, 0x10, 0xD6, 0x44, 0x3A, 0x73,
			0x51, 0x87, 0xEE, 0xD1, 0xB1, 0x95, 0x37, 0x3D, 0xC1, 0x11, 0x98, 0x9B, 0x9C, 0x58, 0xB6, 0x72,
			0xED, 0x22, 0x53, 0xEA, 0xBF, 0x86, 0x00, 0x5F, 0x77, 0x37, 0x8A, 0x5D, 0x21, 0xD0, 0xD2, 0x0D,
			0x9E, 0xD2, 0xC4, 0x8F, 0xB4, 0x58, 0x00, 0x01, 0x83, 0xC4, 0xF3, 0x35, 0x00, 0x04, 0x00, 0x05,
			0x00, 0x00, 0xA0, 0x19, 0x1A, 0x01, 0x47, 0x29, 0x60, 0xE1, 0x04, 0x62, 0x00, 0x00, 0x00, 0x01,
			0x00, 0x02, 0x5C, 0x6A, 0x00, 0x00, 0x20, 0x39, 0x59, 0x7B, 0x01, 0x74, 0x76, 0x1D, 0xEE, 0x64,
			0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x04};
	uint8_t TestTwoDCRHashResult[32] = {
			0x2E, 0xAB, 0x80, 0x1B, 0x7F, 0xA6, 0x4C, 0xBF, 0x38, 0xAD, 0x99, 0x57, 0xB6, 0x80, 0xC1, 0x9C,
			0x44, 0xA7, 0x5B, 0x3E, 0x2F, 0xFB, 0xD6, 0xEA, 0x30, 0x77, 0x58, 0x34, 0x00, 0x00, 0x00, 0x00,
	};
	dcrCompressToMidstate(midstate, TestTwoDCRHeader);
	result = dcrMidstateMeetsMinimumTarget(midstate, (TestTwoDCRHeader) + 128);
	// Ensure the arguments are not modified by running the verification
	// function.
	bool result2 = dcrMidstateMeetsMinimumTarget(midstate, (TestTwoDCRHeader) + 128);
	if (!result || !result2) {
		printf("TEST TWO FAILED\n");
		printf("TEST TWO FAILED\n");
		printf("TEST TWO FAILED\n");
	} else {
		printf("test two passed\n");
	}

	// Same as test two, but with 1 byte changed.
	uint8_t TestThreeDCRHeader[180] = {
			0x00, 0x00, 0x00, 0x04, 0xFE, 0x11, 0xF5, 0x1A, 0x98, 0x06, 0xE4, 0x67, 0x00, 0xFE, 0xDC, 0x54,
			0xAE, 0x4B, 0x51, 0xC5, 0x8B, 0x73, 0x6E, 0x50, 0xA6, 0xC6, 0xF6, 0xAB, 0x00, 0x00, 0x01, 0x2B,
			0x00, 0x00, 0x00, 0x00, 0x96, 0x08, 0xD9, 0x48, 0x87, 0x6E, 0xFE, 0x29, 0x7F, 0xF9, 0x33, 0x66,
			0x35, 0x38, 0x09, 0xF4, 0x05, 0xE2, 0xE6, 0x0B, 0x3A, 0xDE, 0x14, 0x10, 0xD6, 0x44, 0x3A, 0x73,
			0x51, 0x87, 0xEF, 0xD1, 0xB1, 0x95, 0x37, 0x3D, 0xC1, 0x11, 0x98, 0x9B, 0x9C, 0x58, 0xB6, 0x72,
			0xED, 0x22, 0x53, 0xEA, 0xBF, 0x86, 0x00, 0x5F, 0x77, 0x37, 0x8A, 0x5D, 0x21, 0xD0, 0xD2, 0x0D,
			0x9E, 0xD2, 0xC4, 0x8F, 0xB4, 0x58, 0x00, 0x01, 0x83, 0xC4, 0xF3, 0x35, 0x00, 0x04, 0x00, 0x05,
			0x00, 0x00, 0xA0, 0x19, 0x1A, 0x01, 0x47, 0x29, 0x60, 0xE1, 0x04, 0x62, 0x00, 0x00, 0x00, 0x01,
			0x00, 0x02, 0x5C, 0x6A, 0x00, 0x00, 0x20, 0x39, 0x59, 0x7B, 0x01, 0x74, 0x76, 0x1D, 0xEE, 0x64,
			0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x04};
	uint8_t TestThreeDCRHashResult[32] = {
			0x2E, 0xAB, 0x80, 0x1B, 0x7F, 0xA6, 0x4C, 0xBF, 0x38, 0xAD, 0x99, 0x57, 0xB6, 0x80, 0xC1, 0x9C,
			0x44, 0xA7, 0x5B, 0x3E, 0x2F, 0xFB, 0xD6, 0xEA, 0x30, 0x77, 0x58, 0x34, 0x00, 0x00, 0x00, 0x00,
	};
	dcrCompressToMidstate(midstate, TestThreeDCRHeader);
	result = dcrMidstateMeetsMinimumTarget(midstate, (TestThreeDCRHeader) + 128);
	if (result) {
		printf("TEST THREE FAILED\n");
		printf("TEST THREE FAILED\n");
		printf("TEST THREE FAILED\n");
	} else {
		printf("test three passed\n");
	}

	// Same as test two.
	uint8_t TestFourDCRHeader[180] = {
			0x00, 0x00, 0x00, 0x04, 0xFE, 0x11, 0xF5, 0x1A, 0x98, 0x06, 0xE4, 0x67, 0x00, 0xFE, 0xDC, 0x54,
			0xAE, 0x4B, 0x51, 0xC5, 0x8B, 0x73, 0x6E, 0x50, 0xA6, 0xC6, 0xF6, 0xAB, 0x00, 0x00, 0x01, 0x2B,
			0x00, 0x00, 0x00, 0x00, 0x96, 0x08, 0xD9, 0x48, 0x87, 0x6E, 0xFE, 0x29, 0x7F, 0xF9, 0x33, 0x66,
			0x35, 0x38, 0x09, 0xF4, 0x05, 0xE2, 0xE6, 0x0B, 0x3A, 0xDE, 0x14, 0x10, 0xD6, 0x44, 0x3A, 0x73,
			0x51, 0x87, 0xEE, 0xD1, 0xB1, 0x95, 0x37, 0x3D, 0xC1, 0x11, 0x98, 0x9B, 0x9C, 0x58, 0xB6, 0x72,
			0xED, 0x22, 0x53, 0xEA, 0xBF, 0x86, 0x00, 0x5F, 0x77, 0x37, 0x8A, 0x5D, 0x21, 0xD0, 0xD2, 0x0D,
			0x9E, 0xD2, 0xC4, 0x8F, 0xB4, 0x58, 0x00, 0x01, 0x83, 0xC4, 0xF3, 0x35, 0x00, 0x04, 0x00, 0x05,
			0x00, 0x00, 0xA0, 0x19, 0x1A, 0x01, 0x47, 0x29, 0x60, 0xE1, 0x04, 0x62, 0x00, 0x00, 0x00, 0x01,
			0x00, 0x02, 0x5C, 0x6A, 0x00, 0x00, 0x20, 0x39, 0x59, 0x7B, 0x01, 0x74, 0x76, 0x1D, 0xEE, 0x64,
			0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x04};
	uint8_t TestFourDCRHashResult[32] = {
			0x2E, 0xAB, 0x80, 0x1B, 0x7F, 0xA6, 0x4C, 0xBF, 0x38, 0xAD, 0x99, 0x57, 0xB6, 0x80, 0xC1, 0x9C,
			0x44, 0xA7, 0x5B, 0x3E, 0x2F, 0xFB, 0xD6, 0xEA, 0x30, 0x77, 0x58, 0x34, 0x00, 0x00, 0x00, 0x00,
	};
	dcrCompressToMidstate(midstate, TestFourDCRHeader);
	result = dcrMidstateMeetsProvidedDifficulty(midstate, (TestFourDCRHeader) + 128, 4);
	result2 = dcrMidstateMeetsProvidedDifficulty(midstate, (TestFourDCRHeader) + 128, 6);
	if (!result || result2) {
		printf("TEST FOUR FAILED\n");
		printf("TEST FOUR FAILED\n");
		printf("TEST FOUR FAILED\n");
	} else {
		printf("test four passed\n");
	}

	printf("test 5 removed for being incorrect.\n");

	uint8_t TestSixDCRHeader[180] = {
			0x01, 0x00, 0x00, 0x00, 0x80, 0xd9, 0x21, 0x2b, 0xf4, 0xce, 0xb0, 0x66, 0xde, 0xd2, 0x86, 0x6b,
			0x39, 0xd4, 0xed, 0x89, 0xe0, 0xab, 0x60, 0xf3, 0x35, 0xc1, 0x1d, 0xf8, 0xe7, 0xbf, 0x85, 0xd9,
			0xc3, 0x5c, 0x8e, 0x29, 0x47, 0x63, 0x69, 0x67, 0x50, 0xe6, 0x72, 0x86, 0x7f, 0x91, 0x00, 0x68,
			0x79, 0x94, 0x18, 0xdb, 0x8d, 0xa6, 0x07, 0xba, 0xf2, 0x28, 0x08, 0x55, 0x22, 0x48, 0xb5, 0xd0,
			0xb9, 0x5f, 0x89, 0xb4, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x01, 0x1b, 0x00, 0xc2, 0xeb, 0x0b, 0x00, 0x00, 0x00, 0x00,
			0x01, 0x00, 0x00, 0x00, 0x71, 0xbb, 0x01, 0x00, 0x27, 0xd8, 0xb8, 0x56, 0x6e, 0x83, 0xd6, 0xda,
			0x38, 0x2a, 0x09, 0x36, 0xed, 0x7f, 0x17, 0x77, 0x43, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00};
	dcrPrepareMidstate(midstate, TestSixDCRHeader);
	result = dcrMidstateMeetsProvidedDifficulty(midstate, (TestSixDCRHeader) + 128, 240000);
	result2 = dcrMidstateMeetsProvidedDifficulty(midstate, (TestSixDCRHeader) + 128, 260000);
	if (!result || result2) {
		printf("TEST SIX FAILED\n");
		printf("TEST SIX FAILED\n");
		printf("TEST SIX FAILED\n");
	} else {
		printf("test six passed\n");
	}

	uint8_t TestSevenDCRHeader[180] = {
			0x01, 0x00, 0x00, 0x00, 0x80, 0xd9, 0x21, 0x2b, 0xf4, 0xce, 0xb0, 0x66, 0xde, 0xd2, 0x86, 0x6b,
			0x39, 0xd4, 0xed, 0x89, 0xe0, 0xab, 0x60, 0xf3, 0x35, 0xc1, 0x1d, 0xf8, 0xe7, 0xbf, 0x85, 0xd9,
			0xc3, 0x5c, 0x8e, 0x29, 0x47, 0x63, 0x69, 0x67, 0x50, 0xe6, 0x72, 0x86, 0x7f, 0x91, 0x00, 0x68,
			0x79, 0x94, 0x18, 0xdb, 0x8d, 0xa6, 0x07, 0xba, 0xf2, 0x28, 0x08, 0x55, 0x22, 0x48, 0xb5, 0xd0,
			0xb9, 0x5f, 0x89, 0xb4, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x01, 0x1b, 0x00, 0xc2, 0xeb, 0x0b, 0x00, 0x00, 0x00, 0x00,
			0x01, 0x00, 0x00, 0x00, 0x71, 0xbb, 0x01, 0x00, 0x27, 0xd8, 0xb8, 0x56, 0x6e, 0x83, 0xd6, 0xda,
			0x38, 0x2a, 0x09, 0x36, 0xed, 0x7f, 0x17, 0x77, 0x43, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00};
	dcrPrepareMidstate(midstate, TestSevenDCRHeader);
	result = dcrMidstateMeetsProvidedDifficulty(midstate, (TestSevenDCRHeader) + 128, 240000);
	result2 = dcrMidstateMeetsProvidedDifficulty(midstate, (TestSevenDCRHeader) + 128, 260000);
	if (!result || result2) {
		printf("%u, %u\n", result, result2);
		printf("TEST SEVEN FAILED\n");
		printf("TEST SEVEN FAILED\n");
		printf("TEST SEVEN FAILED\n");
	} else {
		printf("test seven passed\n");
	}

	uint8_t TestEightDCRHeader[180] = {
			0x05, 0x00, 0x00, 0x00, 0x05, 0x9d, 0xb0, 0xe2, 0x5a, 0xf5, 0x3d, 0x23, 0x4a, 0x71, 0x7f, 0xbb,
			0x1a, 0xfd, 0x9d, 0xd7, 0x0f, 0x8c, 0x3f, 0xd1, 0xfc, 0x63, 0xcc, 0xd0, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x01, 0xad, 0xc0, 0x41, 0xa0, 0x21, 0x00, 0x1c, 0x84, 0xcf, 0x4a, 0xcb,
			0xcb, 0x93, 0x12, 0x78, 0x63, 0x6c, 0x28, 0x72, 0xf3, 0x12, 0x80, 0x0e, 0x1e, 0x7e, 0xaf, 0x83,
			0x2b, 0xfa, 0x88, 0x25, 0x0e, 0xa4, 0xa0, 0x0f, 0x09, 0x78, 0xa2, 0xba, 0xb4, 0x89, 0x61, 0x31,
			0x76, 0x85, 0xa7, 0x43, 0xbd, 0xdd, 0x7f, 0x61, 0x02, 0x2d, 0x4e, 0x01, 0x86, 0x82, 0xff, 0xec,
			0x64, 0x2b, 0x62, 0xc3, 0x01, 0x00, 0x57, 0x10, 0x8d, 0xa8, 0xfc, 0xaa, 0x05, 0x00, 0x07, 0x00,
			0x87, 0xa0, 0x00, 0x00, 0x77, 0xff, 0x00, 0x19, 0xb5, 0x2b, 0xce, 0x53, 0x02, 0x00, 0x00, 0x00,
			0x3b, 0x06, 0x04, 0x00, 0xcc, 0x1d, 0x00, 0x00, 0x08, 0x1c, 0x6b, 0x5b, 0x3c, 0x0f, 0x43, 0xc2,
			0x10, 0x00, 0x00, 0x01, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x05, 0x00, 0x00, 0x00};

	dcrPrepareMidstate(midstate, TestEightDCRHeader);
	result = dcrMidstateMeetsMinimumTarget(midstate, (TestEightDCRHeader) + 128);
	result2 = dcrMidstateMeetsProvidedDifficulty(midstate, (TestEightDCRHeader) + 128, 6);
	bool result3 = dcrMidstateMeetsProvidedDifficulty(midstate, (TestEightDCRHeader) + 128, 8);
	if (!result || !result2 || result3) {
		printf("TEST EIGHT FAILED\n");
		printf("TEST EIGHT FAILED\n");
		printf("TEST EIGHT FAILED\n");
	} else {
		printf("test eight passed.\n");
	}

	return (0);
}
