// TIEN XU LY
// KHAI BAO CAC THU VIEN
#include <stdio.h>
#include <conio.h>
// DINH NGHIA SO PHAN TU TOI DA CUA MANG
#define MaxLength 100
// DINH NGHIA KIEU PHAN TU MOI CO TEN LA ELEMENTTYPE , KIEU SO NGUYEN
typedef int ElementType;
// KHAI BAO CAU TRUC STACK
struct Stack {
	ElementType Elements[MaxLength]; // KIEU PHAN TU
	int Top; // VI TRI DAU NGAN XEP
};

// DANH SACH CAC CHUONG TRINH CON

// HAM KHOI TAO NGAN XEP RONG
void MakeNull_Stack(Stack *S) {
	S->Top=0;
}

// HAM KIEM TRA NGAN XEP RONG
int Empty_Stack(Stack S) {
	return (S.Top==0);
}

// HAM KIEM TRA NGAN XEP DAY
int Full_Stack(Stack S) {
	return (S.Top==MaxLength);
}

// HAM THEM PHAN TU VAO TRONG NGAN XEP TAI VI TRI TOP
void Push(ElementType X, Stack *S) {
	if (Full_Stack(*S))
		printf("Loi! Ngan xep day!");
	else {
		S->Top=S->Top+1;
		S->Elements[S->Top]=X;
	}
}

// HAM NHAP SO PHAN TU
void Nhap_Stack(Stack *S) {
	int n;
	ElementType X;
	do {
		printf("Nhap so phan tu cua stack: (<%d)",MaxLength);
		scanf("%d",&n);
	} while(n>MaxLength||n<1);
	for(int i=0; i<n; i++) {
		printf("Nhap  phan tu %d: ",i+1);
		scanf("%d",&X);
		Push(X,S);
	}
}

// HAM XUAT PHAN TU NGAN XEP
void Xuat_Stack(Stack S) {
	for(int i=S.Top; i>0; i--) {
		printf("%d",S.Elements[i]);
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


// CHUUONG TRINH CHINH
int main() {
	// KHAI BAO BIEN STACK
	Stack S;
	// KHAI BAO BIEN X
	ElementType X;
	// KHAI BAO HAM KHOI TAO NGAN XEP RONG
	MakeNull_Stack(&S);
	// NHAP, XUAT PHAN TU 
	printf("\n Nhap  phan tu Stack: ");
	Nhap_Stack(&S);// KHAI BAO HAM NHAP PHAN TU
	Xuat_Stack(S);// KHAI BAO HAM XUAT PHAN TU
	// NHAP THEM PHAN TU VAO TRONG  NGAN XEP VA IN RA MAN HINH
	printf("\n Nhap them phan tu vao Stack: ");
	scanf("%d",&X);
	Push(X,&S);// KHAI BAO HAM THEM
	Xuat_Stack(S);// KHAI BAO HAM XUAT
	// XOA PHAN TU DAU RA KHOI NGAN XEP
	printf("Stack sau khi xoa 1 phan tu dau: \n");
	Pop(&S,X);// KHAI BAO HAM XOA PHAN TU
	Xuat_Stack(S);// KHAI BAO HAM XUAT
	// KET THUC CT
	getch();
	return 0;
}

