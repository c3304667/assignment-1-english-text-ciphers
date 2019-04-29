#include<stdio.h>
                            //write: "cd (name of folder-without master)" <tab> ls <enter> "gcc main.c && ./a.out" <enter> (all without quotation marks) into terminal to interact. Then follow the prompts. Once done, simply re type gcc main.c && ./a.out to run the program again
void cipher(void);          //all text is hardcoded in. Change it in respective strings of code if one wants to change
void decipher(void);
void subcipher(void);           //these are each the prototypes for each case (like initiating them)
void subdecipher(void);

 
int main(){
    int x;
    printf("Please input a number to pick from the following options to be performed\n");
    printf("1 = Encryption with a rotation cipher given plain text and key\n");              //this is all the menu to begin with to select what is being tested
    printf("2 = Decryption with a rotation cipher given cipher text and key\n");
    printf("3 = Encryption with a substitution cipher given plain text and key\n");
    printf("4 = Decryption with a substitution cipher given cipher text and key\n");
    scanf("%d", &x);            //this check's which number is selected for which option to use
    switch (x){
        case (1):               //each case runs a different solution for whichever number option is selected
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
 
void cipher(void){              //this states what the function does
    char message[1000] = {"hello world"}, ascii_version;
    int i, key;
        printf("Message to encrypt is hard coded as: hello world\n");
        printf("\nEnter the key: ");
        scanf("%d", &key);
            for(i = 0; message[i] != 0; ++i){              //this assigns i to the message letting it incrememnt by 1 until it is NULL'd
                ascii_version = message[i];                 //this ensures the message of i is in ASCII characters for the initial message array
                if(ascii_version >= 'a' && ascii_version <= 'z'){     //for the newly assigned ascii_version of the text (to work with a variable), if it is above the ascii character "a", and below ascii version of "z":
                    ascii_version = ascii_version - 'a';        //allows alphabet to be between 0-25
                    ascii_version = ascii_version + key;        //lets the key number add to these ascii characters                         
                    ascii_version = ascii_version % 26;         //by finding the remainder of 26, it allows the numbers to cycle back around from 'z' to 'a'
                    ascii_version = ascii_version + 'a';        //brings it back up to the real numbers representing each letter (without this it might be punctuation or something)              
               
                    message[i] = ascii_version;                       //this simply states then that the final message of i is the characterised version of what the ascii turned out to be
                }
                else if(ascii_version >= 'A' && ascii_version <= 'Z'){
                    ascii_version = ascii_version - 'A';               //this else if statement does everything as above but for upper case letters
                    ascii_version = ascii_version + key;
                    ascii_version = ascii_version % 26;
                    ascii_version = ascii_version + 'A';
                 
                    message[i] = ascii_version;
                }
            }
            printf("Encrypted message: %s\n", message);                 //then it prints off the new encrypted message
            return;         //gets called back to main to be used (every time the return is used this simply puts it back into main)
};

void decipher(void){
    char message[1000] = {"vszzc kcfzr"}, ascii_version;        //this with the key 14 makes hello world
    int i, key;
      printf("Message is hardcoded in as: vszzc kcfzr\n");
            printf("Enter the key (for this message, 14 will translate to hello world): ");
            scanf("%d", &key);
            for(i = 0; message[i] != '\0'; ++i){                          //this all runs on the same basis of encryption, only taking the key and doing it backwards
                ascii_version = message[i];
                if(ascii_version >= 'a' && ascii_version <= 'z'){
                    ascii_version = ascii_version - 'a';
                    ascii_version = ascii_version + 26 - key;
                    ascii_version = ascii_version % 26;
                    ascii_version = ascii_version + 'a';        //after finding ascii versions of the text, it takes away the key making the cipher go backwards
                 
                    message[i] = ascii_version;
                }
                else if(ascii_version >= 'A' && ascii_version <= 'Z'){
                    ascii_version = ascii_version - 'A';
                    ascii_version = ascii_version + 26 -key;           //and again capital letter version
                    ascii_version = ascii_version %26;
                    ascii_version = ascii_version + 'A';
                   
                    message[i] = ascii_version;
                }
            }
            printf("Decrypted message: %s\n", message);
            return;
};
void subcipher(void){
    char alphabet[52] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"; //this ensures the correct order (for lower and upper case letters-the computer does not know the alphabet)
    char ascii_version;
    char key[52] = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM"; //change key here to whatever you want, just ensure it happens in lower case first, then the exact same for upper case after (so both upper and lowercase can be used)
    char message[1000] = "THIS SHOULD BE ENCODED";      //what's to be coded - can be changed to whatever you wish
    int i, j;
        printf("Message has been hardcoded in as: this should be encoded\n");
            for(i = 0; message[i] != '\0'; i++){    //allows the message of "i" to continually increment to read every value
                ascii_version = message[i];         //assigns all the values of the message to a variable which will be used as an ascii_version of it
                if((ascii_version >= 'a' && ascii_version <= 'z') || (ascii_version >= 'A' && ascii_version <= 'Z')){       //keeps the limit between two ascii values of each upper and lower case letter
                    for(j = 0; j < 52; j++){        //allows j to represents each letter of the alphabet to go up in correct ascending order
                        if(ascii_version == alphabet[j]){       //this says the letters ascii number is apart of the assigned alphabetical order version:
                            printf("%c", key[j]);               //then the key is applied here to all the letter
                        }
                    };
                
                }
                else{
                    printf("%c", message[i]);                   //compared to coming down here, and things like spaces and punctuation are left as whatever they are (no encryption being done)
                        };
            };
            printf("\n");
  
};
      
void subdecipher(void){
    char alphabet[52] = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM"; 
    char ascii_version;
    char key[52] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";          //this is all set out the exact same as the substitution encryption, though the alphabet and key are opposite so it can be changed back
    char message[1000] = "ziol ligxsr wt rtegrtr";                                  //the alphabet and key must be the same as the encryption (in their respective positions), in order to correctly encrypt/decrypt the messages
    int i, j;                                                                       // (all as in, if the key for encryption, is the original alphabet here, it will work, and vice versa)
        printf("Message has been hardcoded in as: ziol ligxsr wt tfegrtr\n");
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
        printf("\n");
};
