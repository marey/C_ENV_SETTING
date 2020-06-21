//
// Created by Rui Mu on 20/6/20.
//
#include <stdio.h>
#include <stdbool.h>
#include "list.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

bool check_done(char *s,NodeT *list){
    for(int i=0;i<strlen(s);i++) {
        if (isnumber(s[i]) == false) {
            s[i] = '\0';
            if (strlen(s) > 0) {
                joinLL(list,atoi(s));
            }
            printf("Done.");
            return 0;
        }
    }

    return 1;
}

int main(int argc, char **argv) {


    NodeT *list = NULL;
    char s[100];
    bool end = false;
    while(true) {
        printf("Enter an integer: ");
        scanf("%s", s);

        for(int i=0;i<strlen(s);i++) {
            if (isnumber(s[i]) == false) {
                s[i] = '\0';
                end = true;
            }
        }

        if (end) {
            if (strlen(s) > 0) {
                list = joinLL(list,atoi(s));
            }
            printf("Done.");
            break;
        } else {
            list = joinLL(list,atoi(s));
        }
    }

    printf("List is ");
    showLL(list);


    // Q2
    if (list !=NULL) {


        // list
        //
        // 421          456732          321         4           86      89342       9      ->NULL
        // first
        //              second


        //                                         second
        //              first

        //                                                              second
        //                              first


        //                                                                                    second
        //                                          first


        // second = first->next;
        // first->next = NULL;
        //                                                  second




        NodeT *first = list, *second = first->next;

        while(second!=NULL && second->next!=NULL) {

            second = second->next->next;
            first = first->next;
        }

        second = first->next;
        first->next = NULL;

        printf("First part is ");
        showLL(list);
        printf("Second part is ");
        showLL(second);

    }



}
