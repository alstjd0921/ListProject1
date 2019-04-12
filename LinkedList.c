#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

void Init(List *list) {
    list->size = 0;
    list->head = NULL;
}

int getSize(List *list) {
    return list->size;
}

int isEmpty(List *list) {
    return !(getSize(list)) ? 1 : 0;
}

void Insert(List *list, int pos, ITEM item) {
    if (pos < 1 || pos > getSize(list) + 1) {
        printf("Out of range\n");
    } else {
        Node *new_node = (Node *) malloc(sizeof(Node));
        new_node->data = item;
        if (pos == 1) {
            new_node->next = list->head;
            list->head = new_node;
        } else {
            Node *pre_node = list->head;
            for (int i = 1; i < pos - 1; i++) {
                pre_node = pre_node->next;
            }
            new_node->next = pre_node->next;
            pre_node->next = new_node;
        }
    }
    list->size++;
}

void Display(List *list) {
    if (isEmpty(list)) {
        printf("Empty\n");
    } else {
        Node *ptr = list->head;
        for (int i = 1; i <= getSize(list); i++) {
            printf("List[%d] : %c\n", i, ptr->data);
            ptr = ptr->next;
        }
    }
}

void Delete(List *list, int pos) {
    if (isEmpty(list)) {
        printf("Empty\n");
    } else if (pos < 1 || pos > getSize(list)) {
        printf("Out of range\n");
    } else {
        Node *del_node;
        if (pos == 1) {
            del_node = list->head;
            list->head = del_node->next;
        } else {
            Node *pre_node = list->head;
            for (int i = 1; i < pos - 1; i++) {
                pre_node = pre_node->next;
            }
            del_node = pre_node->next;
            pre_node->next = del_node->next;
        }
        free(del_node);
        list->size--;
    }
}

void Insert_front(List *list, ITEM item) {
    Insert(list, 1, item);
}

void Insert_rear(List *list, ITEM item) {
    Insert(list, getSize(list) + 1, item);
}

void Delete_front(List *list) {
    Delete(list, 1);
}

void Delete_rear(List *list) {
    Delete(list, getSize(list));
}

void Delete_item(List *list, ITEM item) {
    Node *ptr = list->head;
    int cnt = 0, tmp;
    for (int i = 1; i <= getSize(list); i++) {
        tmp = ptr->data;
        ptr = ptr->next;
        if (tmp == item) {
            Delete(list, i - cnt++);
        }
    }
}

void Delete_all(List *list) {
    for (int i = 1; getSize(list) > 0; i++) {
        Delete_front(list);
        printf("List[%d] deleted\n", i);
    }
}

ITEM Retrieve(List *list, int pos) {
    if (isEmpty(list)) {
        printf("Empty\n");
    } else if (pos < 1 || pos > getSize(list)) {
        printf("Out of range\n");
    } else {
        Node *ptr = list->head;
        for (int i = 0; i < pos - 1; i++) {
            ptr = ptr->next;
        }
        return ptr->data;
    }
    return fprintf(stderr, "error");
}

void Insert_order(List *list, ITEM item) {
    if (isEmpty(list)) {
        Insert_front(list, item);
    } else {
        for (int i = 1; i <= getSize(list); i++) {
            if (Retrieve(list, i) >= item) {
                Insert(list, i, item);
                break;
            } else if (i == getSize(list)) {
                Insert_rear(list, item);
                break;
            }
        }
    }
}
