#include <stdio.h>
#include <conio.h>
#define MaxLength 1000

typedef int ElementType;

typedef struct {
    ElementType Elements[MaxLength];
    int Front, Rear;
} Queue;

void MakeNull_Queue(Queue *Q) {
    Q->Front = -1;
    Q->Rear = -1;
}

int Empty_Queue(Queue Q) {
    return (Q.Front == -1 && Q.Rear == -1);
}

int Full_Queue(Queue Q) {
    return (Q.Rear - Q.Front + 1) == MaxLength;
}

void EnQueue(ElementType X, Queue *Q) {
    if (!Full_Queue(*Q)) {
        if (Empty_Queue(*Q)) {
            Q->Front = 0;
        }
        if (Q->Rear == MaxLength - 1) {
            for (int i = Q->Front; i <= Q->Rear; i++) {
                Q->Elements[i - Q->Front] = Q->Elements[i];
            }
            Q->Rear = MaxLength - Q->Front - 1;
            Q->Front = 0;
        }
        Q->Rear = Q->Rear + 1;
        Q->Elements[Q->Rear] = X;
    } else {
        printf("Loi: Hang day!\n");
    }
}

void DeQueue(Queue *Q) {
    if (!Empty_Queue(*Q)) {
        Q->Front = Q->Front + 1;
        if (Q->Front > Q->Rear) {
            MakeNull_Queue(Q);
        }
    } else {
        printf("Hang rong!\n");
    }
}

ElementType Front(Queue Q) {
    if (!Empty_Queue(Q)) {
        return Q.Elements[Q.Front];
    } else {
        printf("Loi: Hang rong!\n");
        // You might want to return a default value or handle this case appropriately.
        return -1; // Default value (modify as needed)
    }
}

void PrintQueue(Queue Q) {
    if (!Empty_Queue(Q)) {
        for (int i = Q.Front; i <= Q.Rear; i++) {
            printf("%d ", Q.Elements[i]);
        }
        printf("\n");
    } else {
        printf("Hang rong!\n");
    }
}

int main() {
    Queue Q;
    ElementType X;
    MakeNull_Queue(&Q);
    int n;
    printf("So phan tu muon nhap vao: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("\n Nhap gia tri phan tu thu %d:",i+1);
        scanf("%d", &X);
        EnQueue(X, &Q);
    }

    printf("\n***Danh sach hang doi la: ");
    PrintQueue(Q);

    return 0;
}

