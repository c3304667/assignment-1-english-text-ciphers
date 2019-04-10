#include <stdio.h>

int main() {

char key; 
int x;
char message[1000] = {";
int i;

printf("Please input a number to pick from the following options to be performed\n");
printf("1 = Encryption with a rotation cipher given plain text and key\n");    //this is all the menu to begin with to select what is being tested
printf("2 = Decryption with a rotation cipher given cipher text and key\n");
printf("3 = Encryption with a substitution cipher given plain text and key\n");
printf("4 = Decryption with a substitution cipher given cipher text and key\n");

scanf("%d", &x);

switch (x) {
    case 1: printf("enter key used to encrypt and press enter\n");
    scanf("%c", &key);
    printf("then enter message to be encrypted\n");                    
    scanf("%s", message);
    for (int i=0; i<1001; i++){
    if(message[i]>=65 && message[i]<=90) {
            message[i] = message[i]-65;
            message[i] = ((message[i]+key)%26);
            message[i] = message[i] +65;                            //entered into codeboard, so far it prints
         
        }
    }
       printf("the encrypted message is %s", message);

}

return x;
}


//try doing various string types, pulling them from what was in the message