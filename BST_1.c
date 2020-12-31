#include<stdio.h>
#include<malloc.h>

// Binary Search Tree -3 Ham co ban-------------------------------
// Khai Bao
typedef int KeyType; //Chon int lam kieu data cua cay
struct Node{ 
	KeyType Key;
	struct Node *Left, *Right;
};
typedef struct Node* Tree; // Tree = struct Node*

// Cac ham co ban
	// 1. Tim kiem Node chua gia tri x
	Tree searchNode(KeyType x, Tree Root){
		if (Root == NULL) return NULL; 
		else if (Root->Key == x) return Root;
		else if (Root->Key < x){ // Tim o cay con ben Trai
			return searchNode(x, Root->Right);
		}
		else{ // Tim o cay con ben Phai
			return searchNode(x, Root->Left);
		}
	}
	// 2. Them phan tu vao Tree
	void insertNode(int X, Tree *pT){
		if (*pT == NULL){
			(*pT) = (Tree)malloc(sizeof(struct Node));
			(*pT)->Key = X;
			(*pT)->Left = (*pT)->Right = NULL;
		}
		else { // *pT != NULL
			if (X == (*pT)->Key){
				// khong lam gi!
			}
			else if (X < (*pT)->Key){
				insertNode(X, &((*pT)->Left));
			}
			else{
				insertNode(X, &((*pT)->Right));
			}
		}
	}
	// 3. Xoa node mang gia tri x trong cay
	KeyType deleteMin(Tree *pT){
		if ((*pT)->Left == NULL){ // tim node trai nhat cua cay con phai
			KeyType k = (*pT)->Key;
			*pT = (*pT)->Right;
			return k;
		}
		else{
			return deleteMin(&((*pT)->Left));
		} 
	}
	
	void deleteNode(KeyType x, Tree *pT){
		if (*pT != NULL){
			if (x < (*pT)->Key){
				deleteNode(x, &(*pT)->Left); // Goi de quy xoa tree Left
			}
			else if (x > (*pT)->Key){
				deleteNode(x, &(*pT)->Right); //Goi de quy xoa tree Right
			}
			else{ // Tim thay phan tu mang gia tri x
				if ((*pT)->Left==NULL && (*pT)->Right==NULL){ //*pT la node la
					*pT = NULL; 
				}
				else if ((*pT)->Left==NULL && (*pT)->Right!=NULL){ // *pT co con Phai
					*pT = (*pT)->Right;
				}
				else if ((*pT)->Left!=NULL && (*pT)->Right==NULL){ // *pT co con trai
					*pT = (*pT)->Left;
				}
				else{ // *pT co ca con Trai va con Phai
					(*pT)->Key = deleteMin(&((*pT)->Right)); // Tim gia tri cua con Trai nhat ben Phai *pT
				}
			}
		}
		else {
			printf("Cay rong!");
		}
	}

int main(){
	
	return 0;
}


// Mot so doan code tren he thong else


// kiem tra tree rong
int isEmpty(Tree T){
    return (T == NULL);
}

//khoi tao Tree rong
Tree initTree(){
    Tree T = NULL;
    return T;
}

// duyet tien tu(NLR)
void preOrder(Tree T){
    if(!isEmpty(T)){
        printf("%d ", T->Key);
        preOrder(T->Left);
        preOrder(T->Right);
    }
}

// duyet Trung tu(LNR)
void inOrder(Tree T){
    if(!isEmpty(T)){
        inOrder(T->Left);
        printf("%d ", T->Key);
        inOrder(T->Right);
    }
}

//Duyet hau tu(LRN)
void posOrder(Tree T){
    if(!isEmpty(T)){
        posOrder(T->Left);
        posOrder(T->Right);
        printf("%d ", T->Key);
        
    }
}


// chieu cao cua 1 nut bat ki (chieu cao la doan duong tu node do den nut la)
int getHeight(Tree T){
    if (T == NULL) return -1;
    else {
        int leftHeight = getHeight(T->Left);
        int rightHeight = getHeight(T->Right);
        if (leftHeight > rightHeight) return leftHeight + 1;
        else return rightHeight + 1;
    }
}

// tim kiem 1 node mang gia tri x
Tree searchNode(int x, Tree T){
    if (T == NULL) return NULL;
    if (T->Key == x) return T;
    if (T->Key > x){
        return searchNode(x, T->Left);
    }
    return searchNode(x, T->Right);
}

// In duong di tu goc cay den node mang gia tri x
void printPath(int x, Tree T){
    int check = 0;
    Tree p = T;
    while (p != NULL && !check){
        if (x < p->Key){
            printf("%d ", p->Key);
            p = p ->Left;
        }
        else if (x > p->Key){
            printf("%d ", p->Key);
            p = p ->Right;
        }
        else{ // tim thay ptu mang gia tri x
            printf("%d ", p->Key);
            check = 1;
        }
    }
    if (check) printf("-> Tim thay");
    else printf("-> Khong thay");
}

// Tra ve node cha cua tree
Tree getParent(int x, Tree T){
    if (T->Key == x) return NULL;
    else {
        Tree p = T;
        while (p != NULL){
            if (x < p->Left->Key){
                p = p ->Left;
            }
            else if (x > p->Right->Key){
                p = p ->Right;
            }
            else if (x == p->Right->Key || x == p->Left->Key){
                return p;
            }
        }    
    }
    return NULL;
}

// Mot ham khac
/*
Tree getParent(int x, Tree T){
    if (x == T->Key) return NULL;
    else{
        Tree p = T, temp = NULL;
        while (p != NULL){
            if (x < p->Key){
                temp = p;
                p = p->Left;
            } 
            else if (x > p->Key){
                temp = p;
                p = p->Right;
            }
            else{
                return temp;
            }
        }
    }
    return NULL;
}
*/

// insertNode khu de quy :)))

void insertNode(int X, Tree *pT){
    if (*pT != NULL){
        Tree p = *pT;
        while (p != NULL){
            if (X < p->Key && p->Left == NULL){ // th1: x nho hon va la nut la
                Tree temp = (Tree) malloc(sizeof(struct Node));
                temp->Key = X;
                temp->Left = temp->Right = NULL;
                p->Left = temp; // gan temp (mang X) cho p
                break;
            }
            else if (X < p->Key && p->Left != NULL){ // th1: x nho hon va khong la nut la
                p = p->Left; // tro den node Left cua p tim tiep
            }
            else if (X > p->Key && p->Right == NULL){ // th1: x lon hon va la nut la
                Tree temp = (Tree) malloc(sizeof(struct Node));
                temp->Key = X;
                temp->Left = temp->Right = NULL;
                p->Right = temp; // gan temp (mang X) cho p
                break;
            }
            else if (X > p->Key && p->Right != NULL){ // th1: x nho hon va khong la nut la
                p = p->Right; // tro den node Left cua p tim tiep
            }
            else if (X == p->Key){ // th da co node mang x
                break;
            }
        }
    }
    else{
        *pT = (Tree) malloc(sizeof(struct Node));
        (*pT)->Key = X;
        (*pT)->Left = (*pT)->Right = NULL;
    }
}

// Mot so ham hay ho khac
Tree minOfRight(Tree T){ // lay node nho nhat ben phai
    Tree p = T;
    while (p->Left != NULL){
        p = p->Left;
    }
    return p;
}

Tree minOfLeft(Tree T){ // lay node nho nhat ben phai
    Tree p = T;
    while (p->Left != NULL){
        p = p->Left;
    }
    return p;
}

Tree maxOfLeft(Tree T){
    Tree p = T;
    while (p->Right != NULL){
        p = p->Right;
    }
    return p; 
}
// tra ve nut sau node mamg gia tri x
Tree getNext(int x, Tree T){
    // ke tiep nut root la nut nho nhat ben phai
    if (T->Key == x) return minOfRight(T->Right);
    // ke tiep nut lon nhat ben trai la not Root
    else if (x == maxOfLeft(T->Left)->Key) return T;
    // nut lon nhat ben phai se khong co nut sau
    else if (x == maxOfRight(T->Right)->Key) return NULL; 
    // 
    if (x > T->Key) return getNext(x, T->Right);
    return getNext(x, T->Left);
}

// Mot cach khac
/*
Tree getNext(int x, Tree T){ 
    Tree temp = NULL;
    while (T != NULL){
        if (x < T->Key){
            temp = T;
            T = T->Left;
        }
        else if (x >= T->Key){
            T = T->Right;
        }
    }
    return temp;
}
*/
// tra ve nut truoc node mamg gia tri x
Tree getPrevious(int x, Tree T){ // code nay dung vi dieu!
    Tree temp = NULL;
    while (T != NULL){
        if (x > T->Key){
            temp = T; // Luu lai cha cua T
            T = T->Right; // re T sang Phai do x lon hon
        }
        else if (x <= T->Key){ 
            T = T->Left; // neu bang roi thi temp van luu node cha
        }
    }
    return temp;
}

Tree rightSibling(int x, Tree T){
    if (x < T->Key){
        if (x == T->Left->Key ) return T->Right;
        return rightSibling(x, T->Left);
    }
    return NULL;
}