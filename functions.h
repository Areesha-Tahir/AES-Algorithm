#include<iostream>
#include<math.h>
using namespace std;

// substitutes a byte
unsigned char substitute(unsigned char byte) {

	static unsigned char sbox[256] = {
	   0x63, 0x7C, 0x77, 0x7B, 0xF2, 0x6B, 0x6F, 0xC5, 0x30, 0x01, 0x67, 0x2B, 0xFE, 0xD7, 0xAB, 0x76,
	   0xCA, 0x82, 0xC9, 0x7D, 0xFA, 0x59, 0x47, 0xF0, 0xAD, 0xD4, 0xA2, 0xAF, 0x9C, 0xA4, 0x72, 0xC0,
	   0xB7, 0xFD, 0x93, 0x26, 0x36, 0x3F, 0xF7, 0xCC, 0x34, 0xA5, 0xE5, 0xF1, 0x71, 0xD8, 0x31, 0x15,
	   0x04, 0xC7, 0x23, 0xC3, 0x18, 0x96, 0x05, 0x9A, 0x07, 0x12, 0x80, 0xE2, 0xEB, 0x27, 0xB2, 0x75,
	   0x09, 0x83, 0x2C, 0x1A, 0x1B, 0x6E, 0x5A, 0xA0, 0x52, 0x3B, 0xD6, 0xB3, 0x29, 0xE3, 0x2F, 0x84,
	   0x53, 0xD1, 0x00, 0xED, 0x20, 0xFC, 0xB1, 0x5B, 0x6A, 0xCB, 0xBE, 0x39, 0x4A, 0x4C, 0x58, 0xCF,
	   0xD0, 0xEF, 0xAA, 0xFB, 0x43, 0x4D, 0x33, 0x85, 0x45, 0xF9, 0x02, 0x7F, 0x50, 0x3C, 0x9F, 0xA8,
	   0x51, 0xA3, 0x40, 0x8F, 0x92, 0x9D, 0x38, 0xF5, 0xBC, 0xB6, 0xDA, 0x21, 0x10, 0xFF, 0xF3, 0xD2,
	   0xCD, 0x0C, 0x13, 0xEC, 0x5F, 0x97, 0x44, 0x17, 0xC4, 0xA7, 0x7E, 0x3D, 0x64, 0x5D, 0x19, 0x73,
	   0x60, 0x81, 0x4F, 0xDC, 0x22, 0x2A, 0x90, 0x88, 0x46, 0xEE, 0xB8, 0x14, 0xDE, 0x5E, 0x0B, 0xDB,
	   0xE0, 0x32, 0x3A, 0x0A, 0x49, 0x06, 0x24, 0x5C, 0xC2, 0xD3, 0xAC, 0x62, 0x91, 0x95, 0xE4, 0x79,
	   0xE7, 0xC8, 0x37, 0x6D, 0x8D, 0xD5, 0x4E, 0xA9, 0x6C, 0x56, 0xF4, 0xEA, 0x65, 0x7A, 0xAE, 0x08,
	   0xBA, 0x78, 0x25, 0x2E, 0x1C, 0xA6, 0xB4, 0xC6, 0xE8, 0xDD, 0x74, 0x1F, 0x4B, 0xBD, 0x8B, 0x8A,
	   0x70, 0x3E, 0xB5, 0x66, 0x48, 0x03, 0xF6, 0x0E, 0x61, 0x35, 0x57, 0xB9, 0x86, 0xC1, 0x1D, 0x9E,
	   0xE1, 0xF8, 0x98, 0x11, 0x69, 0xD9, 0x8E, 0x94, 0x9B, 0x1E, 0x87, 0xE9, 0xCE, 0x55, 0x28, 0xDF,
	   0x8C, 0xA1, 0x89, 0x0D, 0xBF, 0xE6, 0x42, 0x68, 0x41, 0x99, 0x2D, 0x0F, 0xB0, 0x54, 0xBB, 0x16
	};

	return sbox[byte];
}

unsigned char reverse_substitute(unsigned char byte) {
	static unsigned char rsbox[256] = { 
	0x52, 0x09, 0x6a, 0xd5, 0x30, 0x36, 0xa5, 0x38, 0xbf, 0x40, 0xa3, 0x9e, 0x81, 0xf3, 0xd7, 0xfb
	, 0x7c, 0xe3, 0x39, 0x82, 0x9b, 0x2f, 0xff, 0x87, 0x34, 0x8e, 0x43, 0x44, 0xc4, 0xde, 0xe9, 0xcb
	, 0x54, 0x7b, 0x94, 0x32, 0xa6, 0xc2, 0x23, 0x3d, 0xee, 0x4c, 0x95, 0x0b, 0x42, 0xfa, 0xc3, 0x4e
	, 0x08, 0x2e, 0xa1, 0x66, 0x28, 0xd9, 0x24, 0xb2, 0x76, 0x5b, 0xa2, 0x49, 0x6d, 0x8b, 0xd1, 0x25
	, 0x72, 0xf8, 0xf6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xd4, 0xa4, 0x5c, 0xcc, 0x5d, 0x65, 0xb6, 0x92
	, 0x6c, 0x70, 0x48, 0x50, 0xfd, 0xed, 0xb9, 0xda, 0x5e, 0x15, 0x46, 0x57, 0xa7, 0x8d, 0x9d, 0x84
	, 0x90, 0xd8, 0xab, 0x00, 0x8c, 0xbc, 0xd3, 0x0a, 0xf7, 0xe4, 0x58, 0x05, 0xb8, 0xb3, 0x45, 0x06
	, 0xd0, 0x2c, 0x1e, 0x8f, 0xca, 0x3f, 0x0f, 0x02, 0xc1, 0xaf, 0xbd, 0x03, 0x01, 0x13, 0x8a, 0x6b
	, 0x3a, 0x91, 0x11, 0x41, 0x4f, 0x67, 0xdc, 0xea, 0x97, 0xf2, 0xcf, 0xce, 0xf0, 0xb4, 0xe6, 0x73
	, 0x96, 0xac, 0x74, 0x22, 0xe7, 0xad, 0x35, 0x85, 0xe2, 0xf9, 0x37, 0xe8, 0x1c, 0x75, 0xdf, 0x6e
	, 0x47, 0xf1, 0x1a, 0x71, 0x1d, 0x29, 0xc5, 0x89, 0x6f, 0xb7, 0x62, 0x0e, 0xaa, 0x18, 0xbe, 0x1b
	, 0xfc, 0x56, 0x3e, 0x4b, 0xc6, 0xd2, 0x79, 0x20, 0x9a, 0xdb, 0xc0, 0xfe, 0x78, 0xcd, 0x5a, 0xf4
	, 0x1f, 0xdd, 0xa8, 0x33, 0x88, 0x07, 0xc7, 0x31, 0xb1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xec, 0x5f
	, 0x60, 0x51, 0x7f, 0xa9, 0x19, 0xb5, 0x4a, 0x0d, 0x2d, 0xe5, 0x7a, 0x9f, 0x93, 0xc9, 0x9c, 0xef
	, 0xa0, 0xe0, 0x3b, 0x4d, 0xae, 0x2a, 0xf5, 0xb0, 0xc8, 0xeb, 0xbb, 0x3c, 0x83, 0x53, 0x99, 0x61
	, 0x17, 0x2b, 0x04, 0x7e, 0xba, 0x77, 0xd6, 0x26, 0xe1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0c, 0x7d };

	return rsbox[byte];
}

unsigned char mul2[256] = { 0x00,0x02,0x04,0x06,0x08,0x0a,0x0c,0x0e,0x10,0x12,0x14,0x16,0x18,0x1a,0x1c,0x1e,
	0x20,0x22,0x24,0x26,0x28,0x2a,0x2c,0x2e,0x30,0x32,0x34,0x36,0x38,0x3a,0x3c,0x3e,
	0x40,0x42,0x44,0x46,0x48,0x4a,0x4c,0x4e,0x50,0x52,0x54,0x56,0x58,0x5a,0x5c,0x5e,
	0x60,0x62,0x64,0x66,0x68,0x6a,0x6c,0x6e,0x70,0x72,0x74,0x76,0x78,0x7a,0x7c,0x7e,
	0x80,0x82,0x84,0x86,0x88,0x8a,0x8c,0x8e,0x90,0x92,0x94,0x96,0x98,0x9a,0x9c,0x9e,
	0xa0,0xa2,0xa4,0xa6,0xa8,0xaa,0xac,0xae,0xb0,0xb2,0xb4,0xb6,0xb8,0xba,0xbc,0xbe,
	0xc0,0xc2,0xc4,0xc6,0xc8,0xca,0xcc,0xce,0xd0,0xd2,0xd4,0xd6,0xd8,0xda,0xdc,0xde,
	0xe0,0xe2,0xe4,0xe6,0xe8,0xea,0xec,0xee,0xf0,0xf2,0xf4,0xf6,0xf8,0xfa,0xfc,0xfe,
	0x1b,0x19,0x1f,0x1d,0x13,0x11,0x17,0x15,0x0b,0x09,0x0f,0x0d,0x03,0x01,0x07,0x05,
	0x3b,0x39,0x3f,0x3d,0x33,0x31,0x37,0x35,0x2b,0x29,0x2f,0x2d,0x23,0x21,0x27,0x25,
	0x5b,0x59,0x5f,0x5d,0x53,0x51,0x57,0x55,0x4b,0x49,0x4f,0x4d,0x43,0x41,0x47,0x45,
	0x7b,0x79,0x7f,0x7d,0x73,0x71,0x77,0x75,0x6b,0x69,0x6f,0x6d,0x63,0x61,0x67,0x65,
	0x9b,0x99,0x9f,0x9d,0x93,0x91,0x97,0x95,0x8b,0x89,0x8f,0x8d,0x83,0x81,0x87,0x85,
	0xbb,0xb9,0xbf,0xbd,0xb3,0xb1,0xb7,0xb5,0xab,0xa9,0xaf,0xad,0xa3,0xa1,0xa7,0xa5,
	0xdb,0xd9,0xdf,0xdd,0xd3,0xd1,0xd7,0xd5,0xcb,0xc9,0xcf,0xcd,0xc3,0xc1,0xc7,0xc5,
	0xfb,0xf9,0xff,0xfd,0xf3,0xf1,0xf7,0xf5,0xeb,0xe9,0xef,0xed,0xe3,0xe1,0xe7,0xe5 };

unsigned char mul9[256] = { 0x00,0x09,0x12,0x1b,0x24,0x2d,0x36,0x3f,0x48,0x41,0x5a,0x53,0x6c,0x65,0x7e,0x77,
	0x90,0x99,0x82,0x8b,0xb4,0xbd,0xa6,0xaf,0xd8,0xd1,0xca,0xc3,0xfc,0xf5,0xee,0xe7,
	0x3b,0x32,0x29,0x20,0x1f,0x16,0x0d,0x04,0x73,0x7a,0x61,0x68,0x57,0x5e,0x45,0x4c,
	0xab,0xa2,0xb9,0xb0,0x8f,0x86,0x9d,0x94,0xe3,0xea,0xf1,0xf8,0xc7,0xce,0xd5,0xdc,
	0x76,0x7f,0x64,0x6d,0x52,0x5b,0x40,0x49,0x3e,0x37,0x2c,0x25,0x1a,0x13,0x08,0x01,
	0xe6,0xef,0xf4,0xfd,0xc2,0xcb,0xd0,0xd9,0xae,0xa7,0xbc,0xb5,0x8a,0x83,0x98,0x91,
	0x4d,0x44,0x5f,0x56,0x69,0x60,0x7b,0x72,0x05,0x0c,0x17,0x1e,0x21,0x28,0x33,0x3a,
	0xdd,0xd4,0xcf,0xc6,0xf9,0xf0,0xeb,0xe2,0x95,0x9c,0x87,0x8e,0xb1,0xb8,0xa3,0xaa,
	0xec,0xe5,0xfe,0xf7,0xc8,0xc1,0xda,0xd3,0xa4,0xad,0xb6,0xbf,0x80,0x89,0x92,0x9b,
	0x7c,0x75,0x6e,0x67,0x58,0x51,0x4a,0x43,0x34,0x3d,0x26,0x2f,0x10,0x19,0x02,0x0b,
	0xd7,0xde,0xc5,0xcc,0xf3,0xfa,0xe1,0xe8,0x9f,0x96,0x8d,0x84,0xbb,0xb2,0xa9,0xa0,
	0x47,0x4e,0x55,0x5c,0x63,0x6a,0x71,0x78,0x0f,0x06,0x1d,0x14,0x2b,0x22,0x39,0x30,
	0x9a,0x93,0x88,0x81,0xbe,0xb7,0xac,0xa5,0xd2,0xdb,0xc0,0xc9,0xf6,0xff,0xe4,0xed,
	0x0a,0x03,0x18,0x11,0x2e,0x27,0x3c,0x35,0x42,0x4b,0x50,0x59,0x66,0x6f,0x74,0x7d,
	0xa1,0xa8,0xb3,0xba,0x85,0x8c,0x97,0x9e,0xe9,0xe0,0xfb,0xf2,0xcd,0xc4,0xdf,0xd6,
	0x31,0x38,0x23,0x2a,0x15,0x1c,0x07,0x0e,0x79,0x70,0x6b,0x62,0x5d,0x54,0x4f,0x46 };

unsigned char mul11[256] = { 0x00,0x0b,0x16,0x1d,0x2c,0x27,0x3a,0x31,0x58,0x53,0x4e,0x45,0x74,0x7f,0x62,0x69,
	0xb0,0xbb,0xa6,0xad,0x9c,0x97,0x8a,0x81,0xe8,0xe3,0xfe,0xf5,0xc4,0xcf,0xd2,0xd9,
	0x7b,0x70,0x6d,0x66,0x57,0x5c,0x41,0x4a,0x23,0x28,0x35,0x3e,0x0f,0x04,0x19,0x12,
	0xcb,0xc0,0xdd,0xd6,0xe7,0xec,0xf1,0xfa,0x93,0x98,0x85,0x8e,0xbf,0xb4,0xa9,0xa2,
	0xf6,0xfd,0xe0,0xeb,0xda,0xd1,0xcc,0xc7,0xae,0xa5,0xb8,0xb3,0x82,0x89,0x94,0x9f,
	0x46,0x4d,0x50,0x5b,0x6a,0x61,0x7c,0x77,0x1e,0x15,0x08,0x03,0x32,0x39,0x24,0x2f,
	0x8d,0x86,0x9b,0x90,0xa1,0xaa,0xb7,0xbc,0xd5,0xde,0xc3,0xc8,0xf9,0xf2,0xef,0xe4,
	0x3d,0x36,0x2b,0x20,0x11,0x1a,0x07,0x0c,0x65,0x6e,0x73,0x78,0x49,0x42,0x5f,0x54,
	0xf7,0xfc,0xe1,0xea,0xdb,0xd0,0xcd,0xc6,0xaf,0xa4,0xb9,0xb2,0x83,0x88,0x95,0x9e,
	0x47,0x4c,0x51,0x5a,0x6b,0x60,0x7d,0x76,0x1f,0x14,0x09,0x02,0x33,0x38,0x25,0x2e,
	0x8c,0x87,0x9a,0x91,0xa0,0xab,0xb6,0xbd,0xd4,0xdf,0xc2,0xc9,0xf8,0xf3,0xee,0xe5,	
	0x3c,0x37,0x2a,0x21,0x10,0x1b,0x06,0x0d,0x64,0x6f,0x72,0x79,0x48,0x43,0x5e,0x55,
	0x01,0x0a,0x17,0x1c,0x2d,0x26,0x3b,0x30,0x59,0x52,0x4f,0x44,0x75,0x7e,0x63,0x68,
	0xb1,0xba,0xa7,0xac,0x9d,0x96,0x8b,0x80,0xe9,0xe2,0xff,0xf4,0xc5,0xce,0xd3,0xd8,
	0x7a,0x71,0x6c,0x67,0x56,0x5d,0x40,0x4b,0x22,0x29,0x34,0x3f,0x0e,0x05,0x18,0x13,
	0xca,0xc1,0xdc,0xd7,0xe6,0xed,0xf0,0xfb,0x92,0x99,0x84,0x8f,0xbe,0xb5,0xa8,0xa3 };

unsigned char mul13[256] = { 0x00,0x0d,0x1a,0x17,0x34,0x39,0x2e,0x23,0x68,0x65,0x72,0x7f,0x5c,0x51,0x46,0x4b,
	0xd0,0xdd,0xca,0xc7,0xe4,0xe9,0xfe,0xf3,0xb8,0xb5,0xa2,0xaf,0x8c,0x81,0x96,0x9b,
	0xbb,0xb6,0xa1,0xac,0x8f,0x82,0x95,0x98,0xd3,0xde,0xc9,0xc4,0xe7,0xea,0xfd,0xf0,
	0x6b,0x66,0x71,0x7c,0x5f,0x52,0x45,0x48,0x03,0x0e,0x19,0x14,0x37,0x3a,0x2d,0x20,
	0x6d,0x60,0x77,0x7a,0x59,0x54,0x43,0x4e,0x05,0x08,0x1f,0x12,0x31,0x3c,0x2b,0x26,
	0xbd,0xb0,0xa7,0xaa,0x89,0x84,0x93,0x9e,0xd5,0xd8,0xcf,0xc2,0xe1,0xec,0xfb,0xf6,
	0xd6,0xdb,0xcc,0xc1,0xe2,0xef,0xf8,0xf5,0xbe,0xb3,0xa4,0xa9,0x8a,0x87,0x90,0x9d,
	0x06,0x0b,0x1c,0x11,0x32,0x3f,0x28,0x25,0x6e,0x63,0x74,0x79,0x5a,0x57,0x40,0x4d,
	0xda,0xd7,0xc0,0xcd,0xee,0xe3,0xf4,0xf9,0xb2,0xbf,0xa8,0xa5,0x86,0x8b,0x9c,0x91,
	0x0a,0x07,0x10,0x1d,0x3e,0x33,0x24,0x29,0x62,0x6f,0x78,0x75,0x56,0x5b,0x4c,0x41,
	0x61,0x6c,0x7b,0x76,0x55,0x58,0x4f,0x42,0x09,0x04,0x13,0x1e,0x3d,0x30,0x27,0x2a,
	0xb1,0xbc,0xab,0xa6,0x85,0x88,0x9f,0x92,0xd9,0xd4,0xc3,0xce,0xed,0xe0,0xf7,0xfa,
	0xb7,0xba,0xad,0xa0,0x83,0x8e,0x99,0x94,0xdf,0xd2,0xc5,0xc8,0xeb,0xe6,0xf1,0xfc,
	0x67,0x6a,0x7d,0x70,0x53,0x5e,0x49,0x44,0x0f,0x02,0x15,0x18,0x3b,0x36,0x21,0x2c,
	0x0c,0x01,0x16,0x1b,0x38,0x35,0x22,0x2f,0x64,0x69,0x7e,0x73,0x50,0x5d,0x4a,0x47,
	0xdc,0xd1,0xc6,0xcb,0xe8,0xe5,0xf2,0xff,0xb4,0xb9,0xae,0xa3,0x80,0x8d,0x9a,0x97 };

unsigned char mul14[256] = { 0x00,0x0e,0x1c,0x12,0x38,0x36,0x24,0x2a,0x70,0x7e,0x6c,0x62,0x48,0x46,0x54,0x5a,
	0xe0,0xee,0xfc,0xf2,0xd8,0xd6,0xc4,0xca,0x90,0x9e,0x8c,0x82,0xa8,0xa6,0xb4,0xba,
	0xdb,0xd5,0xc7,0xc9,0xe3,0xed,0xff,0xf1,0xab,0xa5,0xb7,0xb9,0x93,0x9d,0x8f,0x81,
	0x3b,0x35,0x27,0x29,0x03,0x0d,0x1f,0x11,0x4b,0x45,0x57,0x59,0x73,0x7d,0x6f,0x61,
	0xad,0xa3,0xb1,0xbf,0x95,0x9b,0x89,0x87,0xdd,0xd3,0xc1,0xcf,0xe5,0xeb,0xf9,0xf7,
	0x4d,0x43,0x51,0x5f,0x75,0x7b,0x69,0x67,0x3d,0x33,0x21,0x2f,0x05,0x0b,0x19,0x17,
	0x76,0x78,0x6a,0x64,0x4e,0x40,0x52,0x5c,0x06,0x08,0x1a,0x14,0x3e,0x30,0x22,0x2c,
	0x96,0x98,0x8a,0x84,0xae,0xa0,0xb2,0xbc,0xe6,0xe8,0xfa,0xf4,0xde,0xd0,0xc2,0xcc,
	0x41,0x4f,0x5d,0x53,0x79,0x77,0x65,0x6b,0x31,0x3f,0x2d,0x23,0x09,0x07,0x15,0x1b,
	0xa1,0xaf,0xbd,0xb3,0x99,0x97,0x85,0x8b,0xd1,0xdf,0xcd,0xc3,0xe9,0xe7,0xf5,0xfb,
	0x9a,0x94,0x86,0x88,0xa2,0xac,0xbe,0xb0,0xea,0xe4,0xf6,0xf8,0xd2,0xdc,0xce,0xc0,
	0x7a,0x74,0x66,0x68,0x42,0x4c,0x5e,0x50,0x0a,0x04,0x16,0x18,0x32,0x3c,0x2e,0x20,
	0xec,0xe2,0xf0,0xfe,0xd4,0xda,0xc8,0xc6,0x9c,0x92,0x80,0x8e,0xa4,0xaa,0xb8,0xb6,
	0x0c,0x02,0x10,0x1e,0x34,0x3a,0x28,0x26,0x7c,0x72,0x60,0x6e,0x44,0x4a,0x58,0x56,
	0x37,0x39,0x2b,0x25,0x0f,0x01,0x13,0x1d,0x47,0x49,0x5b,0x55,0x7f,0x71,0x63,0x6d,
	0xd7,0xd9,0xcb,0xc5,0xef,0xe1,0xf3,0xfd,0xa7,0xa9,0xbb,0xb5,0x9f,0x91,0x83,0x8d };

void Hex_Con (unsigned char arr[], unsigned char res[])				//function to convert plain text into its coresponding hexa values
{
	unsigned char hexaArray[53] = { 0x41,0x42,0x43,0x44,0x45,		//array conatins all the hexa values of alphabets and space
		0x46,0x47,0x48,0x49,0x4A,
		0x4B,0x4C,0x4D,0x4E,0x4F,
		0x50,0x51,0x52,0x53,0x54,
		0x55,0x56,0x57,0x58,0x59,
		0x5A,0x61,0x62,0x63,0x64,
		0x65,0x66,0x67,0x68,0x69,
		0x6A,0x6B,0x6C,0x6D,0x6E,
		0x6F,0x70,0x71,0x72,0x73,
		0x74,0x75,0x76,0x77,0x78,
		0x79,0x7A,0x20 };
	unsigned char letters[53] = { 'A','B','C','D','E',				//array contains all alphabets and space
		'F','G','H','I','J',
		'K','L','M','N','O',
		'P','Q','R','S','T',
		'U','V','W','X','Y','Z',
		'a','b','c','d','e','f',
		'g','h','i','j','k','l',
		'm','n','o','p','q','r',
		's','t','u','v','w','x',
		'y','z', ' ' };
	//unsigned char hexa_code[16]; 
	for (int i = 0; i < 16 ; i++)
	{
		for(int j = 0; j < 53 ; j++)
		if (arr[i] == letters[j])
		{
			res[i] = hexaArray[j];
		}
		else
			continue;
	}
}

void invHex_Con(unsigned char arr[], unsigned char con[])						//function to convert hexa values to coresponding alphabets
{
	unsigned char hexaArray[53] = { 0x41,0x42,0x43,0x44,0x45,
		0x46,0x47,0x48,0x49,0x4A,
		0x4B,0x4C,0x4D,0x4E,0x4F,
		0x50,0x51,0x52,0x53,0x54,
		0x55,0x56,0x57,0x58,0x59,
		0x5A,0x61,0x62,0x63,0x64,
		0x65,0x66,0x67,0x68,0x69,
		0x6A,0x6B,0x6C,0x6D,0x6E,
		0x6F,0x70,0x71,0x72,0x73,
		0x74,0x75,0x76,0x77,0x78,
		0x79,0x7A,0x20 };
	unsigned char letters[53] = { 'A','B','C','D','E',
		'F','G','H','I','J',
		'K','L','M','N','O',
		'P','Q','R','S','T',
		'U','V','W','X','Y','Z',
		'a','b','c','d','e','f',
		'g','h','i','j','k','l',
		'm','n','o','p','q','r',
		's','t','u','v','w','x',
		'y','z', ' ' };
	//unsigned char hexa_code[16]; 
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 53; j++)
			if (arr[i] == hexaArray[j])
			{
				con[i] = letters[j];
			}
			else
				continue;
	}
}
void Transpose(unsigned char r[])
{
	unsigned char a[16];
	a[0] = r[0];
	a[5] = r[5];
	a[10] = r[10];
	a[15] = r[15];
	a[1] = r[4];
	a[2] = r[8];
	a[3] = r[12];
	a[4] = r[1];
	a[6] = r[9];
	a[7] = r[13];
	a[8] = r[2];
	a[9] = r[6];
	a[11] = r[14];
	a[12] = r[3];
	a[13] = r[7];
	a[14] = r[11];
	for (int i = 0; i < 16; i++)
		r[i] = a[i];
	
}
void rotate_left(unsigned char *byte_array) {									//function to rotate the rows to the left 
	Transpose(byte_array);
	unsigned char R_left[16];			//temp array to shift the rows
	//the first row remains unchanged
	R_left[0] = byte_array[0];
	R_left[4] = byte_array[4];
	R_left[8] = byte_array[8];
	R_left[12] = byte_array[12];
	//one byte shifted to the left for the second row
	R_left[1] = byte_array[5];
	R_left[5] = byte_array[9];
	R_left[9] = byte_array[13];
	R_left[13] = byte_array[1];
	//two bytes shifted to the left for the third row
	R_left[2] = byte_array[10];
	R_left[6] = byte_array[14];
	R_left[10] = byte_array[2];
	R_left[14] = byte_array[6];
	//three bytes shifted to the left for the fourth row
	R_left[3] = byte_array[15];
	R_left[7] = byte_array[3];
	R_left[11] = byte_array[7];
	R_left[15] = byte_array[11];
	for (int i = 0; i < 16; i++)
	{
		byte_array[i] = R_left[i];
	}
}

void SubBytes(unsigned char *state) {								//function to substitute values of state from the sbox
	unsigned char temp[16];
	for (int i = 0; i < 16; i++)
	{
		temp[i] = substitute(state[i]);
	}
	for (int i = 0; i < 16; i++)
	{
		state[i] = temp[i];
	}
}

void InvSubBytes(unsigned char *state) {							//function to substitute values of state from the inverse sbox
	unsigned char temp[16];
	for (int i = 0; i < 16; i++)
	{
		temp[i] = reverse_substitute(state[i]);
	}
	for (int i = 0; i < 16; i++)
	{
		state[i] = temp[i];
	}
}

void InvShiftRows(unsigned char *state) {
	Transpose(state);
	unsigned char inv_shift[16];			//temp array to shift the rows
//the first row remains unchanged
	inv_shift[0] = state[0];
	inv_shift[4] = state[4];
	inv_shift[8] = state[8];
	inv_shift[12] = state[12];
	//one byte shifted to the left for the second row
	inv_shift[1] = state[13];
	inv_shift[5] = state[1];
	inv_shift[9] = state[5];
	inv_shift[13] = state[9];
	//two bytes shifted to the left for the third row
	inv_shift[2] = state[10];
	inv_shift[6] = state[14];
	inv_shift[10] = state[2];
	inv_shift[14] = state[6];
	//three bytes shifted to the left for the fourth row
	inv_shift[3] = state[7];
	inv_shift[7] = state[11];
	inv_shift[11] = state[15];
	inv_shift[15] = state[3];
	for (int i = 0; i < 16; i++)
	{
		state[i] = inv_shift[i];
	}
	Transpose(state);
}

void ShiftRows(unsigned char *state) {										//function to shift rows to the left 
	rotate_left(state); 
	Transpose(state);
	
}

void addRoundKey(unsigned char *state, unsigned char *roundKey ) {			//function to add round key

	unsigned char temp[16];
	for (int i = 0; i < 16; i++)
	{
		temp[i] = state[i] ^ roundKey[i];									//xoring state and roundkey and storing in temp[] array
	}
	for (int i = 0; i < 16; i++)
	{
		state[i] = temp[i];
	}
}

void Key_generation(unsigned char keynum, unsigned char* last_bytes)					//function used to perform 3 main steps of key expansion
{
	//step 1: circular byte left shift
	unsigned char tempval = last_bytes[0];
	last_bytes[0] = last_bytes[1];
	last_bytes[1] = last_bytes[2];
	last_bytes[2] = last_bytes[3];
	last_bytes[3] = tempval;				//the last value moves to the front

	//step 2: we substitute the values of the bytes using the sbox
	unsigned char temp[4];
	for (int i = 0; i < 4; i++)							//fetch values from the sbox
	{
		temp[i] = substitute(last_bytes[i]);
	}
	for (int i = 0; i < 4; i++)						//copying the values into last_byte array
	{
		last_bytes[i] = temp[i];
	}
	//int keynum = 0;
	//step 3: adding round constant
	unsigned char round_Constant[10] = { 0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80,0x1b,0x36 }; //round constant values for 10 round keys
	last_bytes[0] = last_bytes[0] ^ round_Constant[keynum];
	//keynum++;
}

void KeyExpansion(unsigned char *cipherkey, unsigned char *expandedkey) {			//function used to make all the 10 keys
/*
	unsigned char w0[4];
	unsigned char w1[4];
	unsigned char w2[4];
	 w0[0] = cipherkey[0];
	 w0[1] = cipherkey[1];
	 w0[2] = cipherkey[2];
	 w0[3] = cipherkey[3];

	 w1[0] = cipherkey[0];
	 w1[1] = cipherkey[1];
	 w1[2] = cipherkey[2];
	 w1[3] = cipherkey[3];

	 w2[0] = cipherkey[0];
	 w2[1] = cipherkey[1];
	 w2[2] = cipherkey[2];
	 w2[3] = cipherkey[3];
	 */
	unsigned char bytes_gen = 0;       //to keep track of the number of bytes generated
	for (int i = 0; i < 16; i++)
	{
		expandedkey[i] = cipherkey[i]; //the first 16 bits of the original key are stored
	}
	bytes_gen = 16;			//as the frist 16 bytes have been copied so bytes generated are now 16
	unsigned char key_Num = 0;			//key_num is used for the addition of correct round constant
	unsigned char temparr[4];			//temp[] to store the last four bytes

	while (bytes_gen < 176)			//condition to check if the number of bytes generated are < 176. (for 10 round keys plus the original round key we have a total of 176 
	{
		for (int i = 0; i < 4; i++)
		{
			temparr[i] = expandedkey[bytes_gen - 4 + i];		//store the last 4 bytes on which we have o perform the three steps 
		}

		if (bytes_gen % 16 == 0)				//after the completion of key call key_gen function for the next key
		{
			Key_generation(key_Num, temparr);     //function called to perform the three steps on the last four bytes
			key_Num++;								//increment key_num by one. 
		}
		//unsigned char first_four[4];
		for (int k = 0; k < 4; k++)
		{
			expandedkey[bytes_gen] = expandedkey[bytes_gen - 16] ^ temparr[k];		//XOR the first four bytes with the new temparr after the key_gen function
			bytes_gen++;										//to move to next storing postion and reading position
		}
		/*
		for (int i = 0; i < 4; i++)
		{
			expandedkey[bytes_gen - 4] = first_four[i];
			bytes_gen++;
		}
		*/
	}
}

void MixColumn(unsigned char *state) {
	Transpose(state);
	unsigned char ColMatrix[16] = { 0x02,0x03,0x01,0x01,						//the fixed column matrix
			0x01,0x02,0x03,0x01,
			0x01,0x01,0x02,0x03,
			0x03,0x01,0x01,0x02 };
	unsigned char temparr[16];													//temp rray to store the answer after multiplying and xoring 
	//from index 0 to 3
	temparr[0] = (mul2[state[0]] ^ (mul2[state[1]] ^ state[1]) ^ state[2] ^ state[3]);	//mul the values in 1st row, than XORing and storing them at 0 index in temparr[]
	temparr[1] = (state[0] ^ mul2[state[1]] ^ (mul2[state[2]] ^ state[2]) ^ state[3]);	//mul the values in 2nd row, than XORing and storing them at 1 index in temparr[]
	temparr[2] = (state[0] ^ state[1] ^ mul2[state[2]] ^ (mul2[state[3]] ^ state[3]));	//mul the values in 3rd row, than XORing and storing them at 2 index in temparr[]
	temparr[3] = ((mul2[state[0]] ^ state[0]) ^ state[1] ^ state[2] ^ mul2[state[3]]);	//mul the values in 4th row, than XORing and storing them at 3 index in temparr[]
	//from index 4 to 7
	temparr[4] = (mul2[state[4]] ^ (mul2[state[5]] ^ state[5]) ^ state[6] ^ state[7]);	//mul the values in 1st row, than XORing and storing them at 4 index in temparr[]
	temparr[5] = (state[4] ^ mul2[state[5]] ^ (mul2[state[6]] ^ state[6]) ^ state[7]);	//mul the values in 1st row, than XORing and storing them at 5 index in temparr[]
	temparr[6] = (state[4] ^ state[5] ^ mul2[state[6]] ^ (mul2[state[7]] ^ state[7]));	//mul the values in 1st row, than XORing and storing them at 6 index in temparr[]
	temparr[7] = ((mul2[state[4]] ^ state[4]) ^ state[5] ^ state[6] ^ mul2[state[7]]);//mul the values in 1st row, than XORing and storing them at 7 index in temparr[]
	//from index 8 to 11
	temparr[8] = (mul2[state[8]] ^ (mul2[state[9]] ^ state[9]) ^ state[10] ^ state[11]);//mul the values in 1st row, than XORing and storing them at 8 index in temparr[]
	temparr[9] = (state[8] ^ mul2[state[9]] ^ (mul2[state[10]] ^ state[10]) ^ state[11]);//mul the values in 1st row, than XORing and storing them at 9 index in temparr[]
	temparr[10] = (state[8] ^ state[9] ^ mul2[state[10]] ^ (mul2[state[11]] ^ state[11]));//mul the values in 1st row, than XORing and storing them at 10 index in temparr[]
	temparr[11] = ((mul2[state[8]] ^ state[8]) ^ state[9] ^ state[10] ^ mul2[state[11]]);//mul the values in 1st row, than XORing and storing them at 11 index in temparr[]
	//from index 12 to 15
	temparr[12] = (mul2[state[12]] ^ (mul2[state[13]] ^ state[13]) ^ state[14] ^ state[15]);//mul the values in 1st row, than XORing and storing them at 12 index in temparr[]
	temparr[13] = (state[12] ^ mul2[state[13]] ^ (mul2[state[14]] ^ state[14]) ^ state[15]);//mul the values in 1st row, than XORing and storing them at 13 index in temparr[]
	temparr[14] = (state[12] ^ state[13] ^ mul2[state[14]] ^ (mul2[state[15]] ^ state[15]));//mul the values in 1st row, than XORing and storing them at 14 index in temparr[]
	temparr[15] = ((mul2[state[12]] ^ state[12]) ^ state[13] ^ state[14] ^ mul2[state[15]]);//mul the values in 1st row, than XORing and storing them at 15 index in temparr[]

	for (int i = 0; i < 16; i++)
	{
		state[i] = temparr[i];
	}
	Transpose(state);
}

void InvMixColumn(unsigned char* state) {														//funtion for the inverse mix column operation
	Transpose(state);
	unsigned char temparr[16];																	//temp[] to store the XORed values before copying them in state
	//storing values at first four indexes
	temparr[0] = (mul14[state[0]] ^ mul11[state[1]] ^ mul13[state[2]] ^ mul9[state[3]]);		//mul the values in 1st row, than XORing and storing them at 0 index in temparr[]
	temparr[1] = (mul9[state[0]] ^ mul14[state[1]] ^ mul11[state[2]] ^ mul13[state[3]]);		//mul the values in 2nd row, than XORing and storing them at 1 index in temparr[]
	temparr[2] = (mul13[state[0]] ^ mul9[state[1]] ^ mul14[state[2]] ^ mul11[state[3]]);		//mul the values in 3rd row, than XORING and storing them at 2 index in temparr[]
	temparr[3] = (mul11[state[0]] ^ mul13[state[1]] ^ mul9[state[2]] ^ mul14[state[3]]);		//mul the values in 4th row, than XORing and storing them at 3 index in temparr[]
	//for next four indexes (from 4 to 7)
	temparr[4] = (mul14[state[4]] ^ mul11[state[5]] ^ mul13[state[6]] ^ mul9[state[7]]);		//mul the values in 1st row,than XORing and storing them at 4 index in temparr[]
	temparr[5] = (mul9[state[4]] ^ mul14[state[5]] ^ mul11[state[6]] ^ mul13[state[7]]);		//mul the values in 2nd row, than XORing and storing them at 5 index in temparr[]
	temparr[6] = (mul13[state[4]] ^ mul9[state[5]] ^ mul14[state[6]] ^ mul11[state[7]]);		//mul the values in 3rd row, than Xoring and storing them at 6 index in temparr[]
	temparr[7] = (mul11[state[4]] ^ mul13[state[5]] ^ mul9[state[6]] ^ mul14[state[7]]);		//mul the values in 4th row, than XORing and storing them at 7 index in temparr[]
	//for index 8 to 11
	temparr[8] = (mul14[state[8]] ^ mul11[state[9]] ^ mul13[state[10]] ^ mul9[state[11]]);		//mul the values in 1st row, than XORing and storing them at 8 index in temparr[]
	temparr[9] = (mul9[state[8]] ^ mul14[state[9]] ^ mul11[state[10]] ^ mul13[state[11]]);		//mul the values in 2nd row, than XORing and storing them at 9 index in temparr[]
	temparr[10] = (mul13[state[8]] ^ mul9[state[9]] ^ mul14[state[10]] ^ mul11[state[11]]);		//mul the values in 3rd row,than XORing and storing them at 10 index in temparr[]
	temparr[11] = (mul11[state[8]] ^ mul13[state[9]] ^ mul9[state[10]] ^ mul14[state[11]]);		//mul the values in 4th row,than XORing and storing them at 11 index in temparr[]
	//for index 12 to 15
	temparr[12] = (mul14[state[12]] ^ mul11[state[13]] ^ mul13[state[14]] ^ mul9[state[15]]);	//mul the values in 1st row,than XORing and storing them at 12 index in temparr[]
	temparr[13] = (mul9[state[12]] ^ mul14[state[13]] ^ mul11[state[14]] ^ mul13[state[15]]);	//mul the values in 2nd row,than XORing and storing them at 13 index in temparr[]
	temparr[14] = (mul13[state[12]] ^ mul9[state[13]] ^ mul14[state[14]] ^ mul11[state[15]]);	//mul the values in 3rd row, than XORing and storing them at 14 index in temparr[]
	temparr[15] = (mul11[state[12]] ^ mul13[state[13]] ^ mul9[state[14]] ^ mul14[state[15]]);	//mul the values in 4th row,than XORing and storing them at 15 index in temparr[]
	

	for (int i = 0; i < 16; i++)
	{
		state[i] = temparr[i];
	}
	Transpose(state);
}

void Encrypt(unsigned char *plaintext, unsigned char *cipherkey, unsigned char *ciphertext) {
	unsigned char res[16];
	unsigned char expandedkey[176];								//array to store all the round keys
	int c = 1;																
	int index;
	int count = 0;
	int i = 0;
	int round_num = 10;											//variable used to break condition (when round 9 has been reached)								
	unsigned char key[16];
	Hex_Con(cipherkey , res);
	for (int i = 0; i < 16; i++)
	{
		cipherkey[i] = res[i];
	}
	KeyExpansion(cipherkey, expandedkey);						//function called to make and store all the round round keys
	Hex_Con(plaintext, res);									//function called to covert the plaintext into its corresponding hexa values
	for (int j =0 ; j < 16 ; j++)								//storing the first round key in the key[] array
	{
		key[j] = expandedkey[j];
	}
	addRoundKey(res, key);														
	while (c < round_num)										//loop for the first 9 rounds
	{
		index = (c + 1) * 16;									//index will contain the last + 1 index of the round key being used
		count = (index - 16);									//count will contain the first index of the round key being used
		for (; count < index; count++, i++)						//loop to store the next round key into key[] array
		{
			key[i] = expandedkey[count];
		}
		i = 0;
		SubBytes(res);
		Transpose(res);
		ShiftRows(res);
		MixColumn(res);
		Transpose(res);
		addRoundKey(res, key);
		c++;	

	}
	//final round (we don't need mix columns)
	i = 0;
	for (count = 160; count < 176; count++, i++)				//last round key being stored in the key[] array
	{
		key[i] = expandedkey[count];
	}
	SubBytes(res);
	Transpose(res);
	ShiftRows(res);
	Transpose(res);
	addRoundKey(res, key );
	for (int i = 0; i < 16; i++)
	{
		ciphertext[i] = res[i];
	}
}

void Decrypt(unsigned char *ciphertext, unsigned char *cipherkey, unsigned char *plaintext) {

	unsigned char con[16];
	unsigned char expandedkey[176];								//array to store all the round keys
	int c = 9;
	int index;
	int count = 0;
	int i = 0;
	int round_num = 0;											//variable used to break condition (when round 9 has been reached)								
	unsigned char key[16];
	KeyExpansion(cipherkey, expandedkey);						//function called to make and store all the round round keys
//	Hex_Con(plaintext, res);									//function called to covert the plaintext into its corresponding hexa values
	//final round (we don't need mix columns)
	i = 0;
	for (count = 160; count < 176; count++, i++)				//last round key being stored in the key[] array
	{
		key[i] = expandedkey[count];
	}
	//Transpose(ciphertext);
	addRoundKey(ciphertext, key);
	Transpose(ciphertext);
	InvShiftRows(ciphertext);
	Transpose(ciphertext);
	InvSubBytes(ciphertext);
	//invHex_Con(ciphertext, con);
	while (c > round_num)										//loop for the first 9 rounds
	{
		index = (c + 1) * 16;									//index will contain the last + 1 index of the round key being used
		count = (index - 16);
		i = 0;
		for (; i < 16; count++, i++)						//loop to store the next round key into key[] array
		{
			key[i] = expandedkey[count];
		}
		i = 0;
		addRoundKey(ciphertext, key);
		Transpose(ciphertext);
		InvMixColumn(ciphertext);
		InvShiftRows(ciphertext);
		Transpose(ciphertext);
		InvSubBytes(ciphertext);
		c--;
	}
	for (int j = 0; j < 16; j++)								//storing the first round key in the key[] array
	{
		key[j] = expandedkey[j];
	}
	addRoundKey(ciphertext, key);
	invHex_Con(ciphertext, con);
	for (int i = 0; i < 16; i++)
	{
		plaintext[i] = con[i];
	}

}

