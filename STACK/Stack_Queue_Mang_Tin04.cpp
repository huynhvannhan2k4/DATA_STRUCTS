// TIEN XU LY
// CAC THU VIEN
#include <stdio.h>
#include <conio.h>
// THU VIEN CHUOI
#include <string.h>

//Khai bao cau truc stack bang mang
#define MaxLength 30 //do dài toi da cua mang

typedef unsigned char ElementType;   // kieu phan tu cua ngan xep

typedef struct {
	ElementType Elements [MaxLength];  //Mang luu các phan tu
	int Top_idx; // giu vi trí dinh cua ngan xep
} Stack;

//Khai bao cau truc hang doi bang mang
typedef struct {
	ElementType   Elements[MaxLength]; // M?ng luu tr? n?i dung các ph?n t?
	int Front, Rear; //ch? s? d?u và duôi hàng
} Queue;

//DS cac chuong trinh con
//Ham khoi tao Stack rong
void Makenull_Stack (Stack *S);
//Ham kiem tra stack day
int Full_Stack (Stack S);
//Ham them phan tu X vao dinh Stack S
void Push (ElementType X, Stack *S);
//Ham kiem tra Stack rong
int Empty_Stack (Stack S);
//Ham lay phan tu dau Stack S
ElementType Top(Stack S);
//Ham xoa phan tu dau Stack S
void Pop(Stack *S);
//Ham doi so nguyen duong n sang dang nhi phan
void DoiNP(unsigned int n);
//Ham doi so nguyen duong n sang dang co so b
void DoiCoSo(unsigned int n, unsigned int b);
// Ham khoi tao hang rong
void Makenull_Queue(Queue *Q);
//Ham kiem tra hang rong
int Empty_Queue(Queue Q);
//Ham kiem tra hang day
int Full_Queue(Queue Q);
// Ham xen mot phan tu vao cuoi hang doi
void EnQueue(ElementType X,Queue *Q);
//Ham xoa phan tu dau hang doi
void DeQueue(Queue *Q);
//Ham lay phan tu dau hang
ElementType Front(Queue Q);
//Ham kiem tra tinh doi xung cua chuoi st
int KTDXung (char st[]);

//CT chinh
int main() {
	unsigned int n, b;
	char st[MaxLength];

	//Cau 1
	printf("\n Nhap so nguyen duong can doi sang nhi phan n = ");
	scanf("%d",&n);
	//Doi n sang dang nhi phan
	printf("\n Dang nhi phan cua %d la: ",n);
	DoiNP(n);

	//Cau 2
	printf("\n Nhap co so can doi b = ");
	scanf("%d",&b);
	//Doi n sang dang co so b
	printf("\n Dang co so %d cua %d la: ",b, n);
	DoiCoSo(n, b);

	//Cau 3
	printf("\n Nhap chuoi can kiem tra tinh doi xung st =");
	//Xoa vung dem ban phim
	fflush(stdin);
	gets(st);
	int kq = KTDXung(st);
	if(kq==1)
		printf("\n Chuoi %s la chuoi doi xung",st);
	else
		printf("\n Chuoi %s la chuoi KHONG doi xung",st);

	//Ket thuc chuong trinh
	getch();
	return 0;
}

//Cai dat noi dung cac CT con
//Ham khoi tao Stack rong
void Makenull_Stack (Stack *S) {
	S->Top_idx=MaxLength;
}
//Ham kiem tra stack day
int Full_Stack (Stack S) {
	return S.Top_idx==0;
}
//Ham them phan tu X vao dinh Stack S
void Push (ElementType X, Stack *S) {
	if (Full_Stack(*S))
		printf("Loi! Ngan xep day!");
	else {
		S->Top_idx = S->Top_idx-1;
		S->Elements [S->Top_idx] = X;
	}
}
//Ham kiem tra Stack rong
int Empty_Stack (Stack S) {
	return S.Top_idx==MaxLength;
}
//Ham lay phan tu dau Stack S
ElementType Top(Stack S) {
	if (!Empty_Stack(S))
		return (S.Elements[S.Top_idx]);
	else
		printf("Loi! Ngan xep rong");
}
//Ham xoa phan tu dau Stack S
void Pop(Stack *S) {
	if (!Empty_Stack(*S))
		S->Top_idx = S->Top_idx+1;
	else
		printf ("Ngan xep rong!");
}
//Ham doi so nguyen duong n sang dang nhi phan
void DoiNP(unsigned int n) {
	Stack S;
	ElementType Du, X;
	//Su dung Stack trung gian S
	Makenull_Stack(&S);
	//I. Doi co so
	while(n!=0) {
		//1. Tinh so du cua n va 2
		Du = n%2;
		//2. Luu vao stack s
		Push(Du,&S);
		//3. Cap nhat gia tri n thanh thuong
		n = n/2;
	}
	//II. In day nhi phan
	while (!Empty_Stack(S)) {
		//1. Lay phan tu dau stack ra
		X = Top(S);
		//2. In ra man hinh
		printf("%d",X);
		//3. Xoa phan tu tai dinh Stack
		Pop(&S);
	}
}
//Ham doi so nguyen duong n sang dang co so b
void DoiCoSo(unsigned int n, unsigned int b) {
	Stack S;
	ElementType Du, X;
	//Su dung Stack trung gian S
	Makenull_Stack(&S);
	//I. Doi co so sang co so b
	while(n!=0) {
		//1. Tinh so du cua n va b
		Du = n%b;
		//2. Luu vao stack s
		if (Du<10)
			Push(Du,&S);
		else //Du>=10
			if (Du==10)
				Push('A',&S);
			else if (Du==11)
				Push('B',&S);
			else if (Du==12)
				Push('C',&S);
			else if (Du==13)
				Push('D',&S);
			else if (Du==14)
				Push('E',&S);
			else
				Push('F',&S);
		//3. Cap nhat gia tri n thanh thuong
		n = n/b;
	}
	//II. In day nhi phan
	while (!Empty_Stack(S)) {
		//1. Lay phan tu dau stack ra
		X = Top(S);
		//2. In ra man hinh
		if (X<10)
			printf("%d",X);
		else  //X>10
			printf("%c",X);
		//3. Xoa phan tu tai dinh Stack
		Pop(&S);
	}
}
//Cai dat hang bang phuong phap di chuyen tinh tien
// Ham khoi tao hang rong
void Makenull_Queue(Queue *Q) {
	Q->Front=-1;
	Q->Rear=-1;
}
//Ham kiem tra hang rong
int Empty_Queue(Queue Q) {
	return Q.Front==-1;
}
//Ham kiem tra hang day
int Full_Queue(Queue Q) {
	return ((Q.Rear-Q.Front+1)== MaxLength);
}
// Ham xen mot phan tu vao cuoi hang doi
void EnQueue(ElementType X,Queue *Q) {
	if (!Full_Queue(*Q)) {
		if (Empty_Queue(*Q))
			Q->Front=0;
		if (Q->Rear==MaxLength-1) {
			// Di chuy?n t?nh ti?n ra tru?c Front v? trí
			for (int i=Q->Front; i<=Q->Rear; i++)
				Q->Elements [i-Q->Front] = Q->Elements[i];
			// Xác d?nh v? trí Rear m?i
			Q->Rear=MaxLength - Q->Front-1;
			Q->Front=0;
		}
		// Tang Rear d? luu n?i dung m?i
		Q->Rear=Q->Rear+1;
		Q->Elements[Q->Rear]=X;
	} else
		printf ("Loi: Hang day!");
}
// Ham xoa phan tu dau Hang doi
void DeQueue(Queue *Q) {
	if (!Empty_Queue(*Q)) {
		Q->Front=Q->Front+1;
		if (Q->Front>Q->Rear)
			// Khoi tao lai Hang doi
			Makenull_Queue(Q);
	} else
		printf("Hang rong!");
}
//Ham lay phan tu dau hang doi
ElementType Front (Queue Q) {
	if(!Empty_Queue(Q))
		return(Q.Elements[Q.Front]);
	else
		printf("Loi hang rong");
}
//Ham kiem tra tinh doi xung cua chuoi st
int KTDXung (char st[]) {
	Stack S;
	Queue Q;
	int DX = 1;
	ElementType X1, X2;
	//1. su dung Stack S va Queue Q trung gian
	Makenull_Stack(&S);
	Makenull_Queue(&Q);
	//2. Lan luot dua cac ky tu cua chuoi st vao S va Q
	int l = strlen(st);  //Lay do dai chuoi
	for(int i=0; i<l; i++) {
		Push(st[i],&S);
		EnQueue(st[i],&Q);
	}
	//3. Kiem tra tinh doi xung
	while(!Empty_Stack(S)&& (!Empty_Queue(Q))&&(DX == 1)) {
		X1 = Top(S);
		X2 = Front(Q);
		if(X1==X2) {
			Pop(&S);
			DeQueue(&Q);
		} else
			DX = 0;
	}
	return (DX);
}

