#include<iostream>
#include"functions.h"
using namespace std;

int main()
{
	/*unsigned char key[] = { 0x54,0x68,0x61,0x74,0x73,			//original key of "Thats My Kung Fu" 
		0x20,0x6D,0x79,0x20,
		0x4B,0x75,0x6E,0x67,
		0x20,0x46,0x75 };
		*/
	unsigned char key[] = { "Thats my Kung Fu" };
	unsigned char plaintext[] = {"Two One Nine Two"};			//plain text that needs to encrypted
	unsigned char ciphertext[16];
	unsigned char plain[16];	
	Encrypt(plaintext, key, ciphertext);
	for (int i = 0; i < 16; i++)
	{
		printf("%X", ciphertext[i]);
		cout << "  ";
	}
	cout << endl;
	Decrypt(ciphertext, key, plain);
	for (int i = 0; i < 16; i++)
	{
		cout << plain[i] << " ";
	}

	return 0;
}