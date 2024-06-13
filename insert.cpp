#include <stdio.h>
#define MAX_SIZE 100 
void insertNumber(int list[], int *size, int number, int position) {
    if (position < 0 || position > *size) {
        printf("Invalid position!\n");
        return;
    }
    if (*size >= MAX_SIZE) {
        printf("List is full!\n");
        return;
    }
    for (int i = *size; i > position; i--) {
        list[i] = list[i - 1];
    }
    list[position] = number;
    (*size)++; 
}
void printList(int list[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}

int main() {
    int list[MAX_SIZE];
    int size, number, position;
    printf("Enter the initial size of the list: ");
    scanf("%d", &size);
    printf("Enter %d elements: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &list[i]);
    }
    printf("Enter the number to be inserted: ");
    scanf("%d", &number);
    printf("Enter the position to insert the number: ");
    scanf("%d", &position);
    insertNumber(list, &size, number, position);
    printf("Updated list: ");
    printList(list, size);

    return 0;
}
