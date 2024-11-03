// DINH NGHIA SO PHAN TU TOI DA CUA MANG
#include <stdio.h>
#include <conio.h>
// DINH NGHIA SO PHAN TU TOI DA CUA MANG
#define MaxLength 100
// DINH NGHIA KIEU PHAN TU MOI CO TEN LA ELEMENTTYPE , KIEU SO NGUYEN
typedef int ElementType;
// KHAI BAO CAU TRUC STACK
typedef struct {
	ElementType Elements[MaxLength];// KIEU PHAN TU
	int Top;
} Stack;// VI TRI DAU NGAN XEP

// CAC CHUONG TRINH CON

// HAM KHOI TAO NGAN XEP RONG
void MakeNull_Stack(Stack *S) {
	S->Top=0;
}

// HAM KIEM TRA NGAN XEP RONG
int Empty_Stack(Stack S) {
	return (S.Top==0);
}

// HAM KIEM TRA NGAN XEP DAY
int Full_Stack(Stack *S) {
	return (S->Top==MaxLength);
}

// HAM THEM PHAN TU VAO TRONG NGAN XEP TAI VI TRI TOP
void Push(ElementType X, Stack *S) {
	if (Full_Stack(S))
		printf("Loi! Ngan xep day!");
	else {
		S->Top=S->Top+1;
		S->Elements[S->Top]=X;
	}
}
// HAM XUAT PHAN TU NGAN XEP
void Xuat_Stack(Stack S){
	for (int i = S.Top; i>0; i--) {
		printf("\n %d", S.Elements[i]);
		printf("\n");
	}
}

// HAM XOA PHAN TU RA KHOI NGAN XEP TAI DINH
void Pop(Stack *S, ElementType X) {
	if (!Empty_Stack(*S)) {
		X=S->Elements[S->Top];
		S->Top--;
	} else {
		printf ("Ngan xep rong!");
	}
}

// Ham them phan tu vao vi tri k va in ra man hinh
void Push_K(Stack *S, ElementType X, int position) {
	if (Full_Stack(S)) {
		printf("Ngan xep day, khong the them phan tu.\n");
		return;
	}
	if (position < 0 || position > S->Top + 1) {
		printf("Vi tri khong hop le.\n");
		return;
	}
	// D?ch chuy?n m?ng sang ph?i d? làm ch? cho ph?n t? m?i
	for (int i = S->Top; i >= position; i--) {
		S->Elements[i + 1] = S->Elements[i];
	}
	S->Elements[position] = X;
	S->Top++;
}

// Ham xoa phan tu vao vi tri k va in ra man hinh
void Pop_K(Stack *S, int position) {
	if (Empty_Stack(*S)) {
		printf("Ngan xep rong, khong the lay phan tu.\n");
		return;
	}
	if (position < 0 || position > S->Top) {
		printf("Vi tri khong hop le.\n");
		return;
	}
	// D?ch chuy?n m?ng sang trái d? xoá ph?n t? t?i v? trí
	for (int i = position; i < S->Top; i++) {
		S->Elements[i] = S->Elements[i + 1];
	}
	S->Top--;
}

// Ham dem so phan tu cua ngan xep con lai
int dem(Stack S){
	int D=0;
	for (int i = 0; i<=S.Top; i++) {
		D=D+1;
	}
}
//// Ham xoa phan tu cuoi cung cua ngan xep
//void popBack(Stack *S) {
//	if (Empty_Stack(*S)) {// tao sao phai them dau * truoc no ****
//		printf("Ngan xep rong, khong the lay phan tu.\n");
//		return;
//	}
//	S->Top--;
//}
// CHUONG TRINH CHINH
int main() {
// Khoi tao ngan xep
	int n;
	Stack S;
	ElementType X;
	MakeNull_Stack(&S);
// Nhap so phan tu
	printf("***Nhap so phan tu can them vao ngan xep ( <%d): ",MaxLength);
	scanf("%d",&n);

	for(int i=0; i<n; i++) {
		printf("\n Nhap vao phan tu thu %d:",i+1);
		scanf("%d",&X);
		Push(X,&S);
	}
// Them va in cac phan tu cua ngan xep

	printf("***Ngan xep cua ban la: ");
	Xuat_Stack(S);

// Xoa phan tu va in lai ngan xep
	Pop(&S,X);

	printf("***Ngan xep sau khi xoa phan tu dau: ");
	Xuat_Stack(S);

// Them phan tu dau va in lai ngan xep
	printf("***Nhap phan tu muon them: ");
	scanf("%d",&X);
	Push(X,&S);
//
	printf("Ngan xep sau khi them phan tu vao dau: ");
	Xuat_Stack(S);
	int Position;
	printf("***Nhap vi tri K can them: ");
	scanf("%d",&Position);
	printf("Nhap gia tri K can them: ");
	scanf("%d",&X);;
	
// Ham them phan tu vao vi tri k va in ra man hinh
	Push_K(&S, X,Position);
	printf("Ngan xep sau khi them phan tu K: ");
	Xuat_Stack(S);
	
// Ham xoa phan tu vao vi tri k va in ra man hinh
	printf("***Nhap vi tri K can xoa: ");
	scanf("%d",&Position);
	Pop_K(&S,Position);
	printf("Ngan xep sau khi xoa phan tu K: ");
	Xuat_Stack(S);
// Ham dem so phan tu cua ngan xep
	printf("\n So phan tu con lai cua ngan xep la: %d",dem(S));
//// Ham xoa phan tu cuoi cung cua ngan xep
//	printf("***Xoa phan tu cuoi cung cua ngan xep: ");
//	popBack(&S);
//	printf("\n Ngan xep sau khi xoa phan tu cuoi cung la: ");
//	Xuat_Stack(S);
// Ket thuc CT
	getch();
	return 0;
}

