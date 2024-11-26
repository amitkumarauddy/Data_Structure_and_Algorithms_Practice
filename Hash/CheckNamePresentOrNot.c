#include<stdio.h>
#include<string.h>

char* hashSet[] = {NULL, "Jones", NULL, "Lisa", NULL, "Bob", NULL, "Siri", "Pete", NULL};

int hashFunction(const char* value){
    int sum = 0;
    for(size_t i = 0; i < strlen(value); i++){
        sum = sum + (int)value[i];
    }
    return sum % 10;
}


int contains(char* name){
    int index = hashFunction(name);
    if(hashSet[index] != NULL && strcmp(hashSet[index],name) == 0){
        return 1;
    }
    return 0;
}

int main(){
    printf("'Amit' is present in the Hash Set : %s", contains("Amit")?"true":"false");
    return 0;
}