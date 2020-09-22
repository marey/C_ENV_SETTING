//
// Created by Rui Mu on 22/9/20.
//
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
typedef struct houseObject* House;

struct houseObject {
    int houseCode;
    int peopleNumber;
    // 下一家是谁
    House next;
};

typedef struct streetObject* Street;

struct streetObject {
    House first;
    int total;
};

House createHouse(int houseCode,int peopleNumber) {
    // 森林里面盖房子 == 内存上分配空间
    House newHouse = malloc(sizeof(struct houseObject));
    newHouse->houseCode = houseCode;
    newHouse->peopleNumber = peopleNumber;
    newHouse->next = NULL;
    return newHouse;
}

Street createStreet() {
    Street street = malloc(sizeof(struct streetObject));
    street->first = NULL;
    street->total = 0;

    return street;
}

void insertHouseToStreet(Street street, int houseCode,int peopleNumber){
    assert(street!=NULL);
    House newHouse = createHouse(houseCode, peopleNumber);
    if (street->total == 0) {
        street->first = newHouse;
        street->total ++;
    } else {
        House lastHouse = street->first;
        while(lastHouse->next!=NULL) {
            lastHouse = lastHouse->next;
        }
        lastHouse->next = newHouse;
        street->total++;
    }
}

void printHouseInfo(House house){
    assert(house!=NULL);
    printf("house code:%d, people number %d\n", house->houseCode,house->peopleNumber);
}

void freeHouse(House house) {
    assert(house!=NULL);
    free(house);
}

void freeStreet(Street street) {
    assert(street!=NULL);
    House tempHouse = street->first;
    while (tempHouse!=NULL) {
        House nextHouse = tempHouse->next;
        freeHouse(tempHouse);
        tempHouse = nextHouse;
    }
    free(street);
}

void printStreet(Street street) {
    assert(street!=NULL);
    House first = street->first;
    while (first!=NULL) {
        printHouseInfo(first);
        first = first->next;
    }
}

int main() {
    Street street = createStreet();
    insertHouseToStreet(street,1,2);
    insertHouseToStreet(street,2,100);
    printStreet(street);
    freeStreet(street);
}

