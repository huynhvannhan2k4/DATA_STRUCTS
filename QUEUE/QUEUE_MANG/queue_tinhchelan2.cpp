// TIEN XU LY
// CAC THU VIEN
#include <stdio.h>
#include <conio.h>
// DINH NGHIA SO PHAN TU TOI DA CUA MAXLENGTH = 1000
#define MaxLength 1000
// DINH NGHIA KIEU DU LIEU INTERGER MOI CO TEN LA ELEMENTTYPE
typedef int ElementType;
// DINH NGHIA MOT CAU TRUC CO TEN LA QUEUE
typedef struct {
    ElementType Elements[MaxLength]; // KIEU PHAN TU
    int Front, Rear; // GIU VI TRI DAU VA VI TRI CUOI CUA HANG DOI QUEUE
} Queue;
// HAM KHOI TAO HANG DOI RONG
void MakeNull_Queue(Queue *Q) {
    Q->Front = -1;
    Q->Rear = -1;
}
// HAM KIEM TRA HANG DOI RONG
int Empty_Queue(Queue Q) {
    return (Q.Front == -1 && Q.Rear == -1);
}
// HAM KIEM TRA HANG DOI DAY
int Full_Queue(Queue Q) {
    return (Q.Rear - Q.Front + 1) == MaxLength;
}
// HAM XEN PHAN TU VAO TRONG HANG DOI
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
// HAM XOA PHAN TU RA KHOI HANG DOI
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
//
ElementType Front(Queue Q) {
    if (!Empty_Queue(Q)) {
        return Q.Elements[Q.Front];
    } else {
        printf("Loi: Hang rong!\n");
        // You might want to return a default value or handle this case appropriately.
        return -1; // Default value (modify as needed)
    }
}
// HAM NHAP SO PHAN TU VAO TRONG
void ScanQueue(Queue *Q, int n){
	ElementType X;
	for (int i = 0; i < n; i++) {
        printf("\n Nhap gia tri phan tu thu %d:",i+1);
        scanf("%d", &X);
        EnQueue(X,Q);// TRUYEN GIA TRI XEN VAO TRONG HANG DOI
    }
}
// HAM XUAT DANH SACH HANG DOI QUEUE
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
// CHUONG TRINH CHINH
int main() {
// CAU 1:
	// KHAI BAO BIEN CAU TRUC
    Queue Q;
    // KHAI BAO BIEN KIEU PHAN TU
    ElementType X;
    // KHAI BAO HAM KHOI TAO HANG DOI RONG
    MakeNull_Queue(&Q);
    // KHAI BAO BIEN, SO PHAN TU CAN NHAP VAO
    int n;
    printf("So phan tu muon nhap vao: ");
    scanf("%d", &n);
    ScanQueue(&Q,n);
	// XUAT CAC PHAN TU TRONG HANG DOI RA MAN HINH
    printf("\n***Danh sach hang doi la: ");
    PrintQueue(Q);
    // XOA PHAN TU
    // KET THUC CT
	getch();
    return 0;
}

