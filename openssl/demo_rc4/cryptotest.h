#ifndef _CRYPTOTEST_H_
#define _CRYPTOTEST_H_
 
 
typedef enum {
	GENERAL = 0,
	ECB,
	CBC,
	CFB,
	OFB,
	TRIPLE_ECB,
	TRIPLE_CBC
}CRYPTO_MODE;
 
//string DES_Encrypt(const string cleartext, const string key, CRYPTO_MODE mode);
//string DES_Decrypt(const string ciphertext, const string key, CRYPTO_MODE mode);
 
char * RC4_Encrypt(const char *cleartext, const char * key, int cleartextlen, int keylen);
char * RC4_Decrypt(const char * ciphertext, const char * key, int cleartextlen, int keylen);
 
#endif //_CRYPTOTEST_H_

