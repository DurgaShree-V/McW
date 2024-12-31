/* An example of bitfield in C */
#include <stdio.h>
#include <stdlib.h>

struct Info{
    unsigned int favourite_number : 3;                             
    unsigned int male_status : 2;
};

int main(){
    struct Info person1;
    person1.favourite_number = 7;                       // Storing/limiting favourite number from 1 to 7
    person1.male_status = 0;                            // Person is not male

    printf("Favourite number : %d\n", person1.favourite_number);
    printf("Person is %s\n", (person1.male_status == 0? " not male " : " male"));

    int size_of_struct = sizeof(person1);
    printf("Size of the structure is %d",size_of_struct);
}