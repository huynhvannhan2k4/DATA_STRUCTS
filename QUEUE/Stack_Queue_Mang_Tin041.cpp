#include <stdio.h>
#include <conio.h>

//Khai bao cau truc stack bang mang
#define MaxLength 30 //do dài toi da cua mang
	  
typedef unsigned int ElementType;   // kieu phan tu cua ngan xep   

typedef struct { 
  	ElementType Elements [MaxLength];  //Mang luu các phan tu
	int Top_idx; // giu vi trí dinh cua ngan xep 
} Stack;

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

//CT chinh
int main(){
	unsigned int n;
	//Cau 1
	printf("\n Nhap so nguyen duong can doi sang nhi phan n = "); scanf("%d",&n);
	//Doi n sang dang nhi phan
	printf("\n Dang nhi phan cua %d la: ",n);
	DoiNP(n);

	//Ket thuc chuong trinh
	getch();
	return 0;
} 

//Cai dat noi dung cac CT con
//Ham khoi tao Stack rong
void Makenull_Stack (Stack *S){
	S->Top_idx=MaxLength; 
}
//Ham kiem tra stack day
int Full_Stack (Stack S){
	return S.Top_idx==0; 
}
//Ham them phan tu X vao dinh Stack S
void Push (ElementType X, Stack *S){
	if (Full_Stack(*S)) 
		printf("Loi! Ngan xep day!"); 
	else{ 
		S->Top_idx = S->Top_idx-1; 
		S->Elements [S->Top_idx] = X; 
	} 
}
//Ham kiem tra Stack rong
int Empty_Stack (Stack S){
	return S.Top_idx==MaxLength;
}
//Ham lay phan tu dau Stack S
ElementType Top(Stack S){
	if (!Empty_Stack(S)) 
	     return (S.Elements[S.Top_idx]); 
	else 
	   printf("Loi! Ngan xep rong"); 
}
//Ham xoa phan tu dau Stack S
void Pop(Stack *S){
	if (!Empty_Stack(*S)) 
		S->Top_idx = S->Top_idx+1; 
	else 
	   printf ("Ngan xep rong!");
}
//Ham doi so nguyen duong n sang dang nhi phan
void DoiNP(unsigned int n){
	Stack S;
	ElementType Du, X;
	//Su dung Stack trung gian S
	Makenull_Stack(&S);
	//I. Doi co so
	while(n!=0){
		//1. Tinh so du cua n va 2
		Du = n%2;
		//2. Luu vao stack s
		Push(Du,&S);
		//3. Cap nhat gia tri n thanh thuong
		n = n/2;
   }
   //II. In day nhi phan
   while (!Empty_Stack(S)){
   	  //1. Lay phan tu dau stack ra
   	  X = Top(S);
   	  //2. In ra man hinh
   	  printf("%d",X);
   	  //3. Xoa phan tu tai dinh Stack
   	  Pop(&S);
   }
}
