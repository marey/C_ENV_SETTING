#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
struct House{
    int door_number;
    int people_number;
    int square_number;
};

struct House * create_house(int door_number,int people_number, int square_number){
    struct House * new_house = malloc(sizeof(struct House));
    new_house->door_number = door_number;
    new_house->people_number = people_number;
    new_house->square_number = square_number;
    return new_house;
}

void show_house(struct House * house){
    printf("house:door_number is %d,people_number is %d,square_number is %d\n",
           house->door_number,house->people_number,house->square_number
    );

}

int main(){
    struct House * house1 = create_house(10000,3,500);
    struct House * house2 = create_house(10001,5,400);

    show_house(house1);
    show_house(house2);

    free(house1);
    free(house2);
}


