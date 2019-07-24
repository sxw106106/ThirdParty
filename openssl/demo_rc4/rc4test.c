#include <stdlib.h>
#include <openssl/rc4.h>
#include <string.h>
#include "cryptotest.h"
 
char * RC4_Encrypt(const char *cleartext, const char * key, int cleartextlen, int keylen)
{
	RC4_KEY rc4key;
	char* tmp = malloc(cleartextlen + 1);
	memset(tmp, 0, cleartextlen + 1);
 
	RC4_set_key(&rc4key, keylen, (const unsigned char*)key);
	RC4(&rc4key, cleartextlen, (const unsigned char*)cleartext, tmp);
 
	return tmp;
}
 
char * RC4_Decrypt(const char * ciphertext, const char * key, int cleartextlen, int keylen)
{
	RC4_KEY rc4key;
	unsigned char* tmp = malloc(cleartextlen + 1);
	memset(tmp, 0, cleartextlen + 1);
 
	RC4_set_key(&rc4key, keylen, (const unsigned char*)key);
	RC4(&rc4key, cleartextlen, (const unsigned char*)ciphertext, tmp);
 
	return tmp;
}

