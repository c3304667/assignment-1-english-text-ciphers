#include<stdio.h>

void cipher(void);
void decipher(void);
void subcipher(void);
void subdecipher(void);

 
int main(){
             //this allows the message to be up to 1000 ascii characters long
    int x;
    printf("Please input a number to pick from the following options to be performed\n");
    printf("1 = Encryption with a rotation cipher given plain text and key\n");              //this is all the menu to begin with to select what is being tested
    printf("2 = Decryption with a rotation cipher given cipher text and key\n");
    printf("3 = Encryption with a substitution cipher given plain text and key\n");
    printf("4 = Decryption with a substitution cipher given cipher text and key\n");
    scanf("%d", &x);            //this check's which number is selected for which option to use
    switch (x){
        case (1):                   //each case runs a different solution for whichever number option is selected
            cipher();
        break;
        case (2):
            decipher();
        break;
        case (3):
            subcipher();
        break;
       case (4):
            subdecipher();
        break;
}
}
 
void cipher(void){
    char message[1000] = {"hello world"}, ascii_version;
    int i, key;
        printf("Enter a message to encrypt: \n");
            // //reads message relaying to the string above
            printf("\nEnter the key: ");
            scanf("%d", &key);
            for(i = 0; message[i] != 0; ++i){              //this assigns i to the message letting it incrememnt by 1 until it is NULL'd
                ascii_version = message[i];                 //this ensures the message of i is in ASCII characters
                if(ascii_version >= 'a' && ascii_version <= 'z'){           //for the newly assigned ascii_version of the text, if it is above the ascii character "a", and below ascii version of "z":
                    ascii_version = ascii_version - 'a';
                    ascii_version = ascii_version + key;                        // for sub, make ascii_version=KEY[ASCII_VERSION] then jump to emssage[i]=ascii_version and print          //for decryption ADD 26 - KEY
                    ascii_version = ascii_version % 26;
                    ascii_version = ascii_version + 'a';                      //then the key can be added to it to rotate the ascii numbers provided encoded text. //to decode sub, add this in before jumping. but put upper/lower case in for loop (int i = 0; i<l, i++)
                    /*                                                         also need a for(lettercheck = 0; lettercheck,26; lettercheck). then go,
                    if(ascii_version > 'z'){
                        ascii_version = ascii_version - 122 + 97 - 1;          //once the new text has been rotated, if it goes past the numerical value of "z", then it takes the ascii value of "z" away,
                        //adds "a" value to bring it back up to the numbers that a-z lie on, and take away one to essentially assigne 0 to a to go from there (0-25)
                    }
                    */
                    message[i] = ascii_version;                       //this simply states then that the final message of i is the characterised version of what the ascii turned out to be
                }
                else if(ascii_version >= 'A' && ascii_version <= 'Z'){
                    ascii_version = ascii_version - 'A';
                    ascii_version = ascii_version + key;
                    ascii_version = ascii_version % 26;
                    ascii_version = ascii_version + 'A';
                    /*if(ascii_version > 'Z'){
                        ascii_version = ascii_version - 90 + 65 - 1;              //this whole else if, if, block does the same thing as above though simply for capital letters, to ensure lower and upper case both work
                    }
                    */
                    message[i] = ascii_version;
                }
            }
            printf("Encrypted message: %s", message);                         //then it prints off the new encrypted message
            return;
};

void decipher(void){
    char message[1000] = {"vszzc kcfzr"}, ascii_version;        //this with the key 14 makes hello world
    int i, key;
      printf("Enter a message to decrypt: \n");
           
            printf("Enter the key: ");
            scanf("%d", &key);
            for(i = 0; message[i] != '\0'; ++i){                          //this all runs on the same basis of encryption, only taking the key and doing it backwards
                ascii_version = message[i];
                if(ascii_version >= 'a' && ascii_version <= 'z'){
                    ascii_version = ascii_version - 'a';
                    ascii_version = ascii_version + 26 - key;
                    ascii_version = ascii_version % 26;
                    ascii_version = ascii_version + 'a';//after finding ascii versions of the text, it takes away the key making the cipher go backwards
                    /*if(ascii_version < 'a'){
                        ascii_version = ascii_version + 'z' - 'a' + 1;      //if the cipher goes past the ascii version of "a" it does the same as ^^ only backwards to loop it back around to "z"
                        //because the number will already be lower than "a", one adds "z", then takes away "a", bringing it back into the a-z loop, but adding 1 so a starts at 0
                    }
                    */
                    message[i] = ascii_version;
                }
                else if(ascii_version >= 'A' && ascii_version <= 'Z'){
                    ascii_version = ascii_version - 'A';
                    ascii_version = ascii_version + 26 -key;
                    ascii_version = ascii_version %26;
                    ascii_version = ascii_version + 'A';
                    /*if(ascii_version < 'A'){
                        //again then the same stuff is done for capitals
                        ascii_version = ascii_version + 'Z' - 'A' + 1;
                    }
                    */
                    message[i] = ascii_version;
                }
            }
            printf("Decrypted message: %s", message);
            return;
};
void subcipher(void){
    char alphabet[52] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"; 
    char ascii_version;
    char key[52] = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
    char message[1000] = "this should be encoded";
    int i, j;
        printf("Message has been hardcoded in as: this should be encoded\n");
            for(i = 0; message[i] != '\0'; i++){
                ascii_version = message[i];
                if((ascii_version >= 'a' && ascii_version <= 'z') || (ascii_version >= 'A' && ascii_version <= 'Z')){
                    for(j = 0; j < 52; j++){
                        if(ascii_version == alphabet[j]){
                            printf("%c", key[j]);
                        }
                    };
                
                }
                else{
                    printf("%c", message[i]);
                        };
            };
            
  
};
      
void subdecipher(void){
    char alphabet[52] = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM"; 
    char ascii_version;
    char key[52] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char message[1000] = "this should be decoded";
    int i, j;
        printf("Message has been hardcoded in as: this should be encoded\n");
            for(i = 0; message[i] != '\0'; i++){
                ascii_version = message[i];
                if((ascii_version >= 'a' && ascii_version <= 'z') || (ascii_version >= 'A' && ascii_version <= 'Z')){
                    for(j = 0; j < 52; j++){
                        if(ascii_version == alphabet[j]){
                            printf("%c", key[j]);
                        }
                    };
                
                }
                else{
                    printf("%c", message[i]);
                        };
            };

};
