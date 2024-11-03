#include <stdio.h>
#include <conio.h>
#include <malloc.h>

//Khai bao cau truc cay nhi phan bang con tro
typedef unsigned char TData; //Kieu nhan cua nút
typedef struct TNode {
	TData Data; //Chua nhan cua nút
	TNode *left, *right; //Con tro chi den vi tri cua 2 cây con trái và phai
};
typedef TNode *TTree;  //Kieu cay nhi phan

//DS cac chuong trinh con
//Khoi tao cay rong
void MakeNullTree(TTree *T);
//Ham tao cay moi tu 2 cay con
TTree Create2(TData v,TTree l,TTree r);
//Ham tao cay theo yeu cau de bai
TTree NhapCay();
//Ham lay nhan cua nut
TData Label_Node (TTree n);
//Ham xac dinh con trai
TTree LeftChild(TTree n);
//Ham xac dinh con phai
TTree RightChild(TTree n);
//Ham duyet tien tu cay T
void PreOrder(TTree T);
//Ham duyet trung tu cay T
void InOrder(TTree T);
//Ham duyet hau tu cay T
void PostOrder(TTree T);
//Tao mot nut moi co nhan la x
TNode* NewNode(TData x);
//Them mot nut co nhan la x vao cay TKNP Root
TNode* InsertNode(TTree Root, TData x);
//Ham tim kiem nut co nhan X tren cay
TNode* Search(TTree Root, TData x);
//Ham kiem tra cay rong
int EmptyTree(TTree T);
//Ham tim kiem nut co gia tri be nhat tren cay
TNode* SearchMin(TTree Root);
//Ham xoa mot nut tren cay
TNode* DeleteNode(TTree Root, TData x);

//chuong trinh chinh
int main() {
	TTree T, Root;
	int n;
	TData X, X1, X2;

	//Cau 1
	//Khoi tao cay rong
	MakeNullTree (&T);
	// Nhap cay
	T = NhapCay();
	//Duyet tien tu cay nhi phan
	printf("\n Danh sach duyet tien tu cay T la: ");
	PreOrder(T);
	printf("\n");
	printf("\n Danh sach duyet trung tu cay T la: ");
	InOrder(T);
	printf("\n");
	printf("\n Danh sach duyet hau tu cay T la: ");
	PostOrder(T);
	printf("\n");

	//Cau 2
	//Khoi tao cay TKNP rong
	MakeNullTree (&Root);
	printf("\n Nhap so phan tu can xen vao cay n =");
	scanf("%d",&n);
	for(int i=0; i<n; i++) {
		printf("\n Nhap phan tu thu %d can xen vao cay: ",i+1);
		fflush(stdin);  //Xoa ky tu trong vung dem ban phim
		scanf("%c",&X);
		Root = InsertNode(Root,X);
	}
	printf("\n Sap xep nhan cua cay TKNP theo thu tu tang dan: ");
	InOrder(Root);
	fflush(stdin);
	printf("\n Nhap phan tu can tim kiem tren cay X = ");
	scanf("%c",&X);
	TNode *N = Search(Root, X);
	if (N!=NULL)
		printf("\n Nut co nhan X = %c co tren cay!!!",X);
	else
		printf("\n Nut co nhan X = %c KHONG co tren cay!!!",X);
	fflush(stdin);
	printf("\n Nhap phan tu can xen vao cay X = ");
	scanf("%c",&X1);
	fflush(stdin);  //Xoa ky tu trong vung dem ban phim
	Root = InsertNode(Root,X1);
	printf("\n Sau khi xen danh sach cac nut tren cay la:");
	InOrder(Root);
	printf("\n");
	//Xoa mot phan tu trong cay tim kiem nhi phan
	fflush(stdin);
	printf("\n Nhap phan tu can xoa X = ");
	scanf("%c",&X2);
	Root = DeleteNode(Root, X2);
	printf("\n Danh sach duyet trung tu cay tim kiem nhi phan la: ");
	InOrder(Root);

	//Ket thuc chuong trinh
	getch();
	return 0;
}

//Cai dat cac huong trinh con
void MakeNullTree(TTree *T) {
	(*T)=NULL;
}
//Ham tao cay moi tu 2 cay con
TTree Create2(TData v,TTree l,TTree r) {
	TTree N;
	N=(TNode*)malloc(sizeof(TNode));
	N->Data=v;
	N->left=l;
	N->right=r;
	return N;
}
//Ham tao cay theo yeu cau de bai
TTree NhapCay() {
	TTree T121 = Create2('G',NULL,NULL);
	TTree T11 = Create2('D',NULL,NULL);
	TTree T12 = Create2('E',T121,NULL);
	TTree T1 = Create2('B',T11,T12);
	TTree T2222 = Create2('J',NULL,NULL);
	TTree T221 = Create2('H',NULL,NULL);
	TTree T222 = Create2('I',NULL,T2222);
	TTree T22 = Create2('F',T221,T222);
	TTree T2 = Create2('C',NULL,T22);
	TTree T = Create2('A',T1,T2);
	return (T);
}
//Ham lay nhan cua nut
TData Label_Node (TTree n) {
	if (n!=NULL)
		return n->Data;
	printf("\n Loi nut khong ton tai !");
}
//Ham xac dinh con trai
TTree LeftChild(TTree n) {
	if (n!=NULL) return n->left;
	else return NULL;
}
//Ham xac dinh con phai
TTree RightChild(TTree n) {
	if (n!=NULL) return n->right;
	else return NULL;
}
//Ham duyet tien tu cay T
void PreOrder(TTree T) {
	printf("%c ",Label_Node(T)); //T->Data
	if (LeftChild(T)!=NULL) PreOrder(LeftChild(T));
	if (RightChild(T)!=NULL)PreOrder(RightChild(T));
}
//Ham duyet trung tu cay T
void InOrder(TTree T) {
	if (LeftChild(T)!=NULL)InOrder(LeftChild(T));
	printf("%c ",Label_Node(T));
	if (RightChild(T)!=NULL) InOrder(RightChild(T));
}
//Ham duyet hau tu cay T
void PostOrder(TTree T) {
	if (LeftChild(T)!=NULL) PostOrder(LeftChild(T));
	if (RightChild(T)!=NULL)PostOrder(RightChild(T));
	printf("%c ",T->Data);
}
//Tao mot nut moi co nhan la x
TNode* NewNode(TData x) {
	TNode *Root =(TNode*)malloc(sizeof(TNode));
	Root->Data = x;
	Root->left = NULL;
	Root->right = NULL;
	return Root;
}
//Them mot nut co nhan la x vao cay TKNP Root
TNode* InsertNode(TTree Root, TData x) {
	if(Root!=NULL) {
		if(Root->Data == x) {
			printf("\n Nut da co tren cay!!!");
			return Root;
		} else if(Root->Data > x)
			Root->left = InsertNode(Root->left, x);
		else
			Root->right = InsertNode(Root->right, x);
	} else
		Root = NewNode(x);
	return Root;
}
//Ham tim kiem nut co nhan X tren cay
TNode* Search(TTree Root, TData x) {
	TNode *p=Root;
	while(p!= NULL) {
		if(p->Data == x)
			return p;
		else if(p->Data > x)
			p = p->left;
		else
			p = p->right;
	}
	return NULL;
}
//Ham kiem tra cay rong
int EmptyTree(TTree T) {
	return (T==NULL);
}
//Ham tim kiem nut co gia tri be nhat tren cay
TNode* SearchMin(TTree Root) {
	if (!EmptyTree(Root)) {
		TNode *Current = Root;
		while(Current->left != NULL)
			Current = Current->left;
		return Current;
	} else
		return (NULL);
}

//Ham xoa mot nut tren cay
TNode* DeleteNode(TTree Root, TData x) {
	if(Root == NULL) {
		printf("\n Nut khong co tren cay!!!");
		return Root;
	}
	if(Root->Data > x)
		Root->left = DeleteNode(Root->left, x);
	else if(Root->Data < x)
		Root->right = DeleteNode(Root->right, x);
	else {
		TNode *p = Root;
		if(Root->left == NULL) {
			Root = Root->right;
			free (p);
		} else if(Root->right== NULL) {
			Root=Root->left;
			free(p);
		} else {
			TNode *Temp = SearchMin(Root->right);
			Root->Data = Temp->Data;
			Root->right = DeleteNode(Root->right, Temp->Data);
		}
	}
	return Root;
}



