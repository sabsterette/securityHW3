#include <stdio.h>

int main(void){
    char name[20];
    int sum = 0;
     //00401383  |> 8A06           /MOV AL,BYTE PTR DS:[ESI]
    fgets(name, 20, stdin);

    // the correct answer should change all of the char's to uppercase
    // but I was having so much trouble with the toupper method
    // it kept giving me different answers and adding weird char's into name
    // so it doesnt work without the input being all caps
    //00401399  |. 46             |INC ESI
    for (int i = 0; i < sizeof(name); i++) {
        //00401394  |> E8 39000000    |CALL CRACKME.004013D2
        //toupper(name[i]) does not work 
        //004013CC  |. 03FB           |ADD EDI,EBX
        sum += (int) name[i];
    }
    //004013A2  |. 81F7 78560000  XOR EDI,5678
    sum = sum ^ 0x5678;
    //004013F5  |> 81F7 34120000  XOR EDI,1234
    printf("%d", sum ^ 0x1234);
    return 0;
}
