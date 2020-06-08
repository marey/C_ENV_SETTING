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
    int square;
};

Car create_car(){
    Car car = malloc(sizeof(struct car));

    car->wheels = 4;
    car->people = 50;
    car->cost = 10000;
    car->square = 500;

    return car;
}

