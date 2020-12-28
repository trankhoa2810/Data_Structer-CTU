#include <stdio.h>
#include <malloc.h>

struct Node
{
    int Key;
    struct Node *Left, *Right;
};

typedef struct Node* Tree;

int isEmpty(Tree T)
{
    return T == NULL;
}

void makeNullTree(Tree *pT)
{
    (*pT) = NULL; // (*pT) != pT
}

void insertNode(int x, Tree *pT)
{
    if (isEmpty(*pT))
    {
        // x la Root
        (*pT) = (Tree)malloc(sizeof(struct Node));
        (*pT)->Key = x;
        (*pT)->Left = (*pT)->Right = NULL;
        return;
    }
    if (x > (*pT)->Key)
        insertNode(x, &((*pT)->Right));
    else if (x < (*pT)->Key)
        insertNode(x, &((*pT)->Left));
}

// Left - Node - Right: Trung tự
void LNR(Tree T)
{
    if (!isEmpty(T))
    {
        LNR(T->Left);
        printf("%d ", T->Key);
        LNR(T->Right);
    }
}

// Node - Left - Right: Tiền tự
void NLR(Tree T)
{
    if (!isEmpty(T))
    {
        printf("%d ", T->Key);
        NLR(T->Left);
        NLR(T->Right);
    }
}

// Left - Right - Node: Hậu tự
void LRN(Tree T)
{
    if (!isEmpty(T))
    {
        LRN(T->Left);
        LRN(T->Right);
        printf("%d ", T->Key);
    }
}

// Trả về nút lá có độ sâu lớn nhất
// tính từ nút gốc Root
int getHeight(Tree T)
{
    if (isEmpty(T))
        return -1;
    int leftHeight = getHeight(T->Left) + 1;
    int rightHeight = getHeight(T->Right) + 1;
    if (leftHeight > rightHeight)
        return leftHeight;
    return rightHeight;
}

Tree searchNode(int x, Tree T, Tree *pa)
{
    if (isEmpty(T))
        return NULL;
    if (T->Key == x)
    {
        return T;
    }
    (*pa) = T;
    if (T->Key > x)
        return searchNode(x, T->Left, pa);
    return searchNode(x, T->Right, pa);
}

// Trả về nút lá có độ sâu lớn nhất
// tính từ nút có giá trị là x
int heightNode(int x, Tree T)
{
    Tree pa = NULL;
    Tree p = searchNode(x, T, &pa);
    if (p == NULL)
    {
        return -1;
    }
    return getHeight(p);
}

Tree fakeDeleteNode(int x, Tree T)
{
    // Nếu T rỗng thì trả về luôn
    if (isEmpty(T))
        return T;
    // Tìm vị trí nút x để xóa, cũng theo quy tắc, trái nhỏ phải lớn
    if (x < T->Key)
    {
        T->Left = fakeDeleteNode(x, T->Left);
    }
    else if (x > T->Key)
    {
        T->Right = fakeDeleteNode(x, T->Right);
    }
    else
    {
        // À.. tới đây là đã tìm thấy vị trí x rồi nè
        // x == T->Key

        // Trường hợp chỉ có 1 con hoặc trái hoặc phải || hoặc không có con nào
        if (T->Left == NULL)
        {
            Tree p = T->Right;
            free(T);
            return p;
        }
        else if (T->Right == NULL)
        {
            Tree p = T->Left;
            free(T);
            return p;
        }

        // Trường hợp có hai con

        // Tìm giá trị nhỏ nhất của con phải
        Tree p = T->Right;
        while (p && p->Left != NULL)
            p = p->Left;

        // Swap
        T->Key = p->Key;

        // Xóa nút chứa giá trị nhỏ nhất của con phải
        T->Right = fakeDeleteNode(T->Key, T->Right);
    }
    return T;
}

void deleteNode(int x, Tree *pT)
{
    (*pT) = fakeDeleteNode(x, *pT);
}

Tree rightSon(int x, Tree T)
{
    Tree pa = NULL;
    Tree p = searchNode(x, T, &pa);
    if (p == NULL)
        return NULL;
    if (pa->Right == NULL)
        return NULL;
    return pa->Right;
}

Tree leftSon(int x, Tree T)
{
    Tree pa = NULL;
    Tree p = searchNode(x, T, &pa);
    if (p == NULL)
        return NULL;
    if (pa->Left == NULL)
        return NULL;
    return pa->Left;
}

int main()
{
    Tree T;
    makeNullTree(&T);
    insertNode(5, &T);
    insertNode(7, &T);
    insertNode(8, &T);
    insertNode(3, &T);
    insertNode(1, &T);
    insertNode(4, &T);
    /**
     * 
     *             5
     *           /   \
     *          3     7
     *         / \     \
     *        1   4     8
     */
    NLR(T);
    puts("");
    printf("%d \n", getHeight(T));
    printf("%d \n", heightNode(0, T));

    // Tree rs = rightSon(1, T);
    // if(rs == NULL) {
    //     puts("Deo co anh em phai nao o day ca!");
    // } else {
    //     printf("%d \n", rs->Key);
    // }
    
    // Tree ls = leftSon(7, T);
    // if(ls == NULL) {
    //     puts("Deo co anh em trai nao o day ca!");
    // } else {
    //     printf("%d \n", ls->Key);
    // }
    
    NLR(T);
    puts("");
    LNR(T);
    puts("");

    deleteNode(3, &T);

    NLR(T);
    puts("");
    LNR(T);
    return 0;
}