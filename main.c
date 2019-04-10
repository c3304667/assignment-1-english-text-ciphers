#include <stdio.h>

int main() {

char key; 
int x;
char message [];
int i;

printf ("Please input a number to pick from the following options to be performed\n");
printf ("1 = Encryption with a rotation cipher given plain text and key\n");
printf ("2 = Decryption with a rotation cipher given cipher text and key\n");
printf ("3 = Encryption with a substitution cipher given plain text and key\n");
printf ("4 = Decryption with a substitution cipher given cipher text and key\n");

scanf("%d", &x);

switch (x=1) {
    case 1: printf ("enter key used to encrypt");
    scanf ("%c", &key);
    printf ("enter message to be encrypted");
    scanf ("%c", &message);
    if(message[]>=65 && message<=90) {
        message[]-65=message[];
        ((message[]+key)%26) = message[];
        message[] = message[] +65;
    }
}

return x;
}


//try doing various string types, pulling them from what was in the message