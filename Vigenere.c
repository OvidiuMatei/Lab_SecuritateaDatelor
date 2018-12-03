#include <stdio.h>
#include <string.h>
#include <ctype.h>

void vigenereCipher(char* plainText, char* k);

int main(){
	char* k = "hello;
	char plaintText[101];
	
	printf("Please enther a sentente or word you want to encrypt: ");
	fgets(plaintText, sizeof(plainText), stdin);
	
	printf("The ciphered text with (key shift - '%s') is: ", k);
	
	vigenereCipher(plainText, k);
	
return 0;
}

void vigenereCipher(char* plainText, char* k){
	int i;
	char cipher;
	int cipherValue;
	int len = strlen(k);
	
	for(i=0; i<strlen(plainText); ++i){
		if(islower(plainText[i])){
			cipherValue = ( (int)plainText[i]-'a'+ (int)tolower(k[i % len])-'a' ) % 26 + 'a';
			cipher = (char)ciperValue;
		}
		else{
			cipherValue = ( (int)plainText[i]-'A' + (int)toupper(k[i % len])-'A' ) % 26 + 'A';
		}
		
		if(isalpha(plainText[i])){
			printf("%c", cipher);
		}
		else{
			printf("%c", plainText[i]);
		}
		
	}
	
}