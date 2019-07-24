#include "cryptotest.h"
#include <string.h>
#include <stdio.h>
 
int main()
{
	char cleartext[] = "中国北京12345$abcde%ABCDE@！！！";
	char *ciphertext;
	char key[] = "beijingchina1234567890ABCDEFGH!!!";
 
	ciphertext = RC4_Encrypt(cleartext, key, strlen(cleartext), strlen(key));
	char * decrypt = RC4_Decrypt(ciphertext, key, strlen(cleartext), strlen(key));
 
	printf("cleartext:%s\n", cleartext);
	printf("genarate ciphertext:%s\n", ciphertext);
	printf("src ciphertext:%s\n", ciphertext);
	printf("genarate ciphertext:%s\n", decrypt);
 
	if (strcmp(cleartext, decrypt) == 0)
		printf("RC4 crypto ok!!!\n");
	else
		printf("RC4 crypto error!!!\n");
	return 0;
}

