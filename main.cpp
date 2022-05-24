#include <cstdio>
#include <cstdlib>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define dataNum 5
int i = 0;
int dep = 0;
char data[dataNum] = {'A', 'B', 'C', 'D', 'E'};

typedef int Status;
typedef char TElemType;

typedef struct BiTNode {
    TElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

void InitBiTree(BiTree &T) {
    T = nullptr;
}

BiTree MakeBiTree(TElemType e, BiTree L, BiTree R) {
    BiTree t;
    t = (BiTree) malloc(sizeof(BiTNode));
    if (nullptr == t) return nullptr;
    t->data = e;
    t->lchild = L;
    t->rchild = R;
    return t;
}

Status visit(TElemType e) {
    printf("%c", e);
    return OK;
}

int Leaves(BiTree T) {
    int l = 0, r = 0;
    if (nullptr == T) return 0;
    if (nullptr == T->lchild && nullptr == T->rchild) return 1;

    l = Leaves(T->lchild);
    r = Leaves(T->rchild);
    return r + l;
}

int depTraverse(BiTree T) {
    if (nullptr == T) return ERROR;

    dep = (depTraverse(T->lchild) > depTraverse(T->rchild)) ? depTraverse(T->lchild) : depTraverse(T->rchild);

    return dep + 1;
}

void levTraverse(BiTree T, Status(*visit)(TElemType e), int lev) {
    if (nullptr == T) return;
    visit(T->data);
    printf("level: %d\n", lev);

    levTraverse(T->lchild, visit, ++lev);
    levTraverse(T->rchild, visit, lev);
}

void InOrderTraverse(BiTree T, Status(*visit)(TElemType e), int &num) {
    if (nullptr == T) return;
    visit(T->data);
    if (nullptr == T->lchild && nullptr == T->rchild) {
        printf("leaf node");
        num++;
    } else printf("not a leaf node");
    printf("\n");
    InOrderTraverse(T->lchild, visit, num);
    InOrderTraverse(T->rchild, visit, num);
}

Status BiTreeEmpty(BiTree T) {
    if (nullptr == T) return TRUE;
    return FALSE;
}

Status BreakBiTree(BiTree &T, BiTree &L, BiTree &R) {
    if (nullptr == T) return ERROR;
    L = T->lchild;
    R = T->rchild;
    T->lchild = nullptr;
    T->rchild = nullptr;
    return OK;
}

Status ReplaceLeft(BiTree &T, BiTree &LT) {
    BiTree temp;
    if (nullptr == T) return ERROR;
    temp = T->lchild;
    T->lchild = LT;
    LT = temp;
    return OK;
}

Status ReplaceRight(BiTree &T, BiTree &RT) {
    BiTree temp;
    if (nullptr == T) return ERROR;
    temp = T->rchild;
    T->rchild = RT;
    RT = temp;
    return OK;
}

void UnionBiTree(BiTree &Ttemp) {
    BiTree L = nullptr, R = nullptr;
    L = MakeBiTree(data[i++], nullptr, nullptr);
    R = MakeBiTree(data[i++], nullptr, nullptr);
    ReplaceLeft(Ttemp, L);
    ReplaceRight(Ttemp, R);
}

int main() {
    BiTree T = nullptr, Ttemp = nullptr;

    InitBiTree(T);
    if (TRUE == BiTreeEmpty(T)) printf("Initialize T to be empty\n");
    else printf("Initialize T not empty\n");

    T = MakeBiTree(data[i++], nullptr, nullptr);

    Ttemp = T;
    UnionBiTree(Ttemp);

    Ttemp = T->lchild;
    UnionBiTree(Ttemp);

    Status (*visit1)(TElemType);
    visit1 = visit;
    int num = 0;
    InOrderTraverse(T, visit1, num);
    printf("Leaf node: %d\n", num);

    printf("The leaf node is %d\n", Leaves(T));

    int lev = 1;
    levTraverse(T, visit1, lev);

    printf("Height is %d\n", depTraverse(T));

    getchar();
    return 0;
}