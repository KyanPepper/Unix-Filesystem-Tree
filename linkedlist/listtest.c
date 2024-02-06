#include "linkedList.h"

int main(){
   if(testInsert() == 1){
        printf("Insert Passed");
   }
}


int testInsert(){
    List list;
    for(int i = 1 i<=7){
        int *data = i;
        insertTail(&list, data);
    }
    if(list.size = 7){
        LinkedNode* pcur = list.head;
        for(int i = 1; i<=7){
            if(pcur->data != i){
                printf("Value error")
                return 0;
            }
        }
        return 1;
    }
    printf("size error");
    return 0;
}