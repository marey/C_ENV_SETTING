//
// Created by Rui Mu on 4/6/20.
//
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef  struct House * Node;

typedef struct Street * LinkedList;

struct House {
    // 定义一个房子
    int door_number;
    int people_number;
    int square_number;
    Node next;
};

struct Street {
    // 有多少个房子
    int total;
    // 第一个房子在哪
    Node first;
    // 每次都记录最后一个节点
    Node last;
};

Node create_node(int door_number, int people_number, int square_number) {

    Node new_house = malloc(sizeof(struct House));
    new_house->door_number = door_number;
    new_house->people_number = people_number;
    new_house->square_number = square_number;

    new_house->next = NULL;
    return new_house;
}

LinkedList create_list() {
    LinkedList new_street = malloc(sizeof(struct Street));
    new_street->total = 0;
    new_street->first = NULL;
    return new_street;
}


void show_node(Node house) {
    printf("house : door_number is %d,people_number is %d, square_number is %d\n",
           house->door_number, house->people_number, house->square_number);
}

void insert_list_last(LinkedList list, int door_number, int people_number, int square_number) {
    // 等价于java: House house = new House();
    Node new_house = create_node(door_number, people_number, square_number);

    if (list->first == NULL) {
        list->first = new_house;
        list->last = list->first;

        list->total++;
    } else {
        // 4
        // 1 -> 2 -> 3 -> 4
        list->last->next = new_house;
        list->last = new_house;
        list->total++;
    }
}

void insert_list_head(LinkedList list, int door_number, int people_number, int square_number) {
    // 等价于java: House house = new House();
    Node new_house = create_node(door_number, people_number, square_number);

    if (list->first == NULL) {
        list->first = new_house;
        list->last = list->first;
        list->total++;
    } else {
        // 1 3 6
        // 5
        // 5 -  1  3  6
        new_house->next = list->first;
        list->first = new_house;
        list->total++;
    }
}

bool exists(LinkedList list, int door_number) {
    bool result = false;

    if (list!=NULL) {
        Node temp = list->first;
        while(temp!=NULL) {
            if (temp->door_number == door_number) {
                result = true;
                break;
            }

            temp = temp->next;
        }
    }

    return result;
}

void insert_list_set_order(LinkedList list, int door_number, int people_number, int square_number) {
    // 等价于java: House house = new House();

    if (exists(list,door_number) == true) {
        return;
    }

    Node new_house = create_node(door_number, people_number, square_number);
    if (list->first == NULL) {
        list->first = new_house;
        list->last = list->first;
        list->total++;
    } else {
        // 1000
        ///1 2 3 4
        if(door_number < list->first->door_number) {
            // insert_list_head(street,door_number, people_number, square_number);
            new_house->next = list->first;
            list->first = new_house;
            list->total++;

        } else if (door_number > list->last->door_number) {
            // insert_list_last(street,door_number, people_number, square_number);
            list->last->next = new_house;
            list->last = new_house;
            list->total++;

        } else {
            Node first =  list->first;
            Node second = first->next;
            // 1 3 5 8
            //    4
            while (second!=NULL) {
                if (first->door_number < door_number && second->door_number > door_number) {
                    // Node new_house = create_node(door_number, people_number, square_number);
                    first->next = new_house;
                    new_house->next = second;
                    break;
                }
                first = first->next;
                second = second->next;
            }
        }
    }
}



void insert_list_order(LinkedList list, int door_number, int people_number, int square_number) {
    // 等价于java: House house = new House();
    Node new_house = create_node(door_number, people_number, square_number);
    if (list->first == NULL) {
        list->first = new_house;
        list->last = list->first;
        list->total++;
    } else {
        // 1000
        ///1 2 3 4
        if(door_number < list->first->door_number) {
            // insert_list_head(street,door_number, people_number, square_number);
            new_house->next = list->first;
            list->first = new_house;
            list->total++;

        } else if (door_number > list->last->door_number) {
            // insert_list_last(street,door_number, people_number, square_number);
            list->last->next = new_house;
            list->last = new_house;
            list->total++;

        } else {
            Node first =  list->first;
            Node second = first->next;
            // 1 3 5 8
            //    4
            while (second!=NULL) {
                if (first->door_number < door_number && second->door_number > door_number) {
                    // Node new_house = create_node(door_number, people_number, square_number);
                    first->next = new_house;
                    new_house->next = second;
                    break;
                }
                first = first->next;
                second = second->next;
            }
        }
    }
}

void show_list(LinkedList list) {
    if (list != NULL) {
        Node house = list->first;
        while (house != NULL) {
            printf("house : door_number is %d,people_number is %d, square_number is %d\n",
                   house->door_number, house->people_number, house->square_number);
            house = house->next;
        }
    }
}

void free_list(LinkedList street) {
    // 先清空房子，再清空街道
    if (street != NULL) {
        Node house = street->first;
        while (house != NULL) {
            Node next = house->next;

            free(house);

            house = next;
        }
        free(street);
    }
}


int main() {
    // 1000  house;


    LinkedList street = create_list();

    // 3 1 4 2
    insert_list_set_order(street, 3, 3, 500);
    insert_list_set_order(street, 1, 2, 50);
    insert_list_set_order(street, 4, 5, 400);
    insert_list_set_order(street, 2, 6, 1000);
    insert_list_set_order(street, 3, 6, 1000);


    show_list(street);

    free_list(street);

}

