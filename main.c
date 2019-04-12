#include <stdio.h>
#include "LinkedList.h"

int main(int argc, const char *argv[]) {
    List list1;

    Init(&list1);

    printf("[ 삽입연산 후 리스트 ]\n");
    Insert(&list1, 1, 'D');
    Insert(&list1, 2, 'A');
    Insert(&list1, 3, 'B');
    Insert(&list1, 4, 'C');
    Insert(&list1, 1, 'D');
    Insert(&list1, 6, 'E');
    Display(&list1);

    Delete(&list1, 3);
    printf("\n[ 3번째 데이터 삭제 후 리스트 ]\n");
    Display(&list1);

    printf("\n[ 2번째 위치의 데이터 찾기 ]\n");
    printf("%d번째항목 %c\n", 2, Retrieve(&list1, 2));

    printf("\n[ 리스트 끝에 'F' 추가 후 리스트 ]\n");
    Insert_rear(&list1, 'F');
    Display(&list1);

    printf("\n[ 리스트 제일 앞에 'G' 추가 후 리스트 ]\n");
    Insert_front(&list1, 'G');
    Display(&list1);

    printf("\n[ 리스트 끝의 데이터 삭제 후 리스트 ]\n");
    Delete_rear(&list1);
    Display(&list1);

    printf("\n[ 리스트 제일 앞 데이터 삭제 후 리스트 ]\n");
    Delete_front(&list1);
    Display(&list1);

    Delete_item(&list1, 'D');
    printf("\n[ 'D' 데이터 삭제 후 리스트 ]\n");
    Display(&list1);

    printf("\n[ 리스트 모든 데이터 삭제 과정 ]\n");
    Delete_all(&list1);

    printf("\n[ 리스트 모든 데이터 삭제 후 리스트 ]\n");
    Display(&list1);

    Insert_order(&list1, 'b');
    Insert_order(&list1, 'a');
    Insert_order(&list1, 'e');
    Insert_order(&list1, 'c');

    printf("\n[ 정렬하면서 삽입 후 리스트 ]\n");
    Display(&list1);

    printf("\n");
    Delete_all(&list1); // 항상 할당받았으면 마지막에 다 해제해줘야합니다.

    printf("\n\n");
    return 0;
}
