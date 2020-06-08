//
// Created by Rui Mu on 6/6/20.
//
#include "Car.h"
#include <stdlib.h>
// 自行车
struct car {
    int wheels;
    int cost;
    int people;
};

Car create_car(){
    Car car = malloc(sizeof(struct car));

    car->wheels = 2;
    car->people = 1;
    car->cost = 10;
    return car;
}

void drive_car(Car car);

void free_car();