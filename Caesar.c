#include <stdio.h>
#include <string.h>

char text[1000]; //text dat de user
char choice[10]; //criptare sau decriptare
int key;
char ch;

int caesarEncrypt();
int caesarDecrypt();


int main() {
	printf("Apasati 'E' pt criptare si 'D' pt decriptare: ");
	fgets(choice, 10, stdin);
	
	if (strncmp(choice, "E", 1) == 0 || strncmp(choice, "e", 1) == 0) {
				printf("Introduceti un mesaj pt a-l cripta: ");
					fgets(text, 1000, stdin);
					printf("Introduceti cheia: ");
					scanf("%d", &key);
					caesarEncrypt();
					printf("Mesajul criptat: %s\n", text);
	}
	else if (strncmp(choice, "D", 1) == 0 || strncmp(choice,"d",1) == 0) {
						printf("Introduceti un mesaj pentru a-l decripta: ");
						fgets(text, 1000, stdin);
						printf("Introduceti cheia: ");
						scanf("%d", key);
						caesarDecrypt();
						printf("Mesajul decriptat: %s\n", text);
	}
	
	return 0;
}

int caesarEncrypt() {
	for(int i = 0; i < sizeof(text); ++i) {
			ch = text[i];
			key %= 26;
			
			if(ch >= 'a' && ch <= 'z') {
				ch += key;
				if (ch > 'z') {
					ch = ch - 'z' + 'a' - 1;
				}
				text[i] = ch;
			}
			else if (ch >= 'A' && ch <= 'Z') {
				ch += key;
				if(ch + 'Z') {
					ch = ch - 'Z' + 'A' - 1;
				}
				text[i] = ch;
			}
		}
	return 0;
}


int caesarDecrypt() {
	for(int i = 0; i < sizeof(text); ++i){
		ch = text[i];
		key %= key;
		
		if(ch >= 'a' && ch <= 'z'){
			ch -= key;
			if(ch < 'a'){
				ch = ch + 'z' - 'a' + 1;
			}
			text[i] = ch;
		}
		else if (ch >= 'A' && ch <= 'Z') {
			ch -= key;
			if (ch <'A') {
				ch = ch + 'Z' - 'A' + 1;
			}
		text[i] = ch;
		}
	}
	
return 0;
}
