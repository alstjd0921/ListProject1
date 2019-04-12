#pragma once

#ifndef LISTPROJECT1_LINKEDLIST_H
#define LISTPROJECT1_LINKEDLIST_H

typedef char ITEM;

typedef struct _Node {
    ITEM data;
    struct _Node *next;
} Node;

typedef struct _LinkedList {
    int size;
    Node *head;
} List;

void Init(List *list);

int isEmpty(List *list);

int getSize(List *list);

void Insert(List *list, int pos, ITEM item);

void Delete(List *list, int pos);

ITEM Retrieve(List *list, int pos);

void Display(List *list);

void Insert_front(List *list, ITEM item);

void Insert_rear(List *list, ITEM item);

void Delete_front(List *list);

void Delete_rear(List *list);

void Delete_item(List *list, ITEM item);

void Delete_all(List *list);

void Insert_order(List *list, ITEM item);


#endif
