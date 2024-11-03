#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

//Khai bao cau truc stack bang con tro
typedef unsigned int ElementType; //kieu cua phan tu cua stack
struct Node {
	ElementType Elements; //Chua noi dung phan tu
	Node* Next; //con tro chi den phan tu ke tiep
};
typedef    Node* Position; //Kieu vi trí
typedef    Position Stack;

//Khai bao cau truc Queue bang con tro
typedef struct {
	Position Front, Rear; //2 con tro
} Queue;

//DS cac chuong trinh con
//Ham khoi tao Stack rong
void Makenull_Stack (Stack *S);
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
// Ham xen mot phan tu vao cuoi hang doi
void EnQueue(ElementType X,Queue *Q);
//Ham xoa phan tu dau hang doi
void DeQueue(Queue *Q);
//Ham lay phan tu dau hang
ElementType Front(Queue Q);
//Ham kiem tra tinh doi xung cua chuoi st
int KTDXung (char st[]);
//Ham nhap k so nguyen duong vao hang Q
void Nhap_Hang(unsigned int k, Queue *Q);
//Ham kiem tra so nguyen to
int KTNTo(unsigned int X);
//Ham in cac so nguyen to co trong hang doi Q
void InNTo(Queue Q);

//CT chinh
int main() {
	unsigned int n, b, k;
	char st[30];
	Queue Q;

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

	//Cau 4
	printf("\n Nhap so phan tu cua day so k =");
	scanf("%d",&k);
	printf("\n Nhap cac phan tu cho hang doi: ");
	Nhap_Hang(k,&Q);
	printf("\n Cac so nguyen to thuoc hang doi la: ");
	InNTo(Q);

	//Ket thuc chuong trinh
	getch();
	return 0;
}

//Cai dat noi dung cac CT con
//Ham khoi tao Stack rong
void Makenull_Stack (Stack *S) {
	(*S)=(Node*)malloc(sizeof (Node));
	(*S)->Next= NULL;
}
//Ham them phan tu X vao dinh Stack S
void Push (ElementType X, Stack *S) {
	Position T;
	T=(Node*)malloc(sizeof (Node));
	T->Elements = X;
	T->Next = (*S)->Next;
	(*S) ->Next= T;
}
//Ham kiem tra Stack rong
int Empty_Stack (Stack S) {
	return (S->Next == NULL);
}
//Ham lay phan tu dau Stack S
ElementType Top(Stack S) {
	if (Empty_Stack(S))
		printf("Loi! Ngan xep rong!");
	else
		return (S->Next-> Elements);
}
//Ham xoa phan tu dau Stack S
void Pop(Stack *S) {
	if (!Empty_Stack(*S)) {
		Position T = (*S)->Next;
		(*S)->Next = T->Next;
		free(T);
	} else printf ("stack rong!!! ");
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
// Ham khoi tao hang rong
void Makenull_Queue(Queue *Q) {
	Position Header;
	Header = (Node*) malloc(sizeof(Node));
	Header->Next=NULL;
	Q->Front=Header;
	Q->Rear=Header;
}
//Ham kiem tra hang rong
int Empty_Queue(Queue Q) {
	return (Q.Front == Q.Rear);
}
// Ham xen mot phan tu vao cuoi hang doi
void EnQueue(ElementType X,Queue *Q) {
	Q->Rear->Next  = (Node*) malloc(sizeof(Node));
	Q->Rear=Q->Rear->Next;
	Q->Rear->Elements=X;
	Q->Rear->Next=NULL;
}
//Ham xoa phan tu dau hang doi
void DeQueue(Queue *Q) {
	if (!Empty_Queue(*Q)) {
		Position Tempt;
		Tempt=Q->Front;
		Q->Front=Q->Front->Next;
		free (Tempt);
	} else
		printf("Loi: Hang rong");
}

//Ham lay phan tu dau hang
ElementType Front(Queue Q) {
	if (!Empty_Queue(Q))
		return (Q.Front->Next->Elements);
	else
		printf("Loi: Hang rong");

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
//Ham nhap k so nguyen duong vao hang Q
void Nhap_Hang(unsigned int k, Queue *Q) {
	ElementType X;
	Makenull_Queue(Q);
	for (int i=0; i<k; i++) {
		printf("\n Nhap phan tu thu %d vao hang doi Q: ");
		scanf("%d",&X);
		EnQueue(X,Q);
	}
}
//Ham kiem tra so nguyen to
int KTNTo(unsigned int X) {
	if(X<2)
		return 0;
	else
		for(int i=2; i<=sqrt(X); i++)
			if(X%i==0)
				return 0;
	return 1;
}
//Ham in cac so nguyen to co trong hang doi Q
void InNTo(Queue Q) {
	ElementType X;
	while(!Empty_Queue(Q)) {
		X = Front(Q);
		if(KTNTo(X)==1)
			printf("%d ", X);
		DeQueue(&Q);
	}
}
