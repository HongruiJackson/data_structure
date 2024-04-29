/**
 * Part1：串的顺序存储结构（静态）
 */
#include <stdio.h>
#include <stdlib.h>
#define STRING_MAX_LEN 255 //

typedef int Status;
#define OK 0
#define ERROR -1

typedef int Bool;
#define true 1
#define false 0

typedef struct {
    char ch[STRING_MAX_LEN + 1];//留一位给'\0'
    int length;
}SString;
// 打印串
void PrintInfo(SString S) {
    printf("StringInfo:");
    for (int i = 0; i < S.length; ++i) {
        printf("%c",S.ch[i]);
    }
    printf("\n");
}

// 初始化串
Status StrAssign (SString * S, const char chars[]) {
    int len = 0;
    // 计算chars的长度
    while (chars[len] != '\0' && len < STRING_MAX_LEN) {
        len++;
    }
    if (len < 0 || len > STRING_MAX_LEN) {
        return ERROR; // 超出字符串最大长度或者为空
    }
    // 将chars赋值给S的ch数组
    for (int i = 0; i < len; i++) {
        S->ch[i] = chars[i];
    }
    S->ch[len] = '\0';
    S->length = len;

    return OK;
}

// 复制串
Status StrCopy (SString * T, SString S) {
    int len = 0;
    while (S.ch[len] != '\0' && len < S.length) {
        len++;
    }
    for (int i = 0; i < len; ++i) {
        T->ch[i] = S.ch[i];
    }
    T->ch[len] = '\0';
    T->length = len;

    return OK;
}

// 判空
Bool StrEmpty(SString S) {
    return S.length==0;
}

// 字符串比较
int StrCompare(SString S, SString T) {
    int i = 0;
    while (i<S.length && i<T.length) {
        if(S.ch[i] == T.ch[i]) i++;
        else if (S.ch[i] > T.ch[i])  return 1;
        else return -1;
    }
    if (S.length == T.length) return 0;
    else if (S.length > T.length) return 1;
    else return -1;
}

// 字符串长度
int StrLength(SString S) {
    return S.length;
}

// 清空字符串
void ClearString(SString * S) {
    S->length = 0;
    S->ch[0] = '\0';
}

// 组成新串，截断的方式
Status Concat(SString *T,SString S1, SString S2) {
    int len = 0;
    while (len < S1.length) {
        T->ch[len] = S1.ch[len];
        len++;
    }
    int j = 0;
    while (len < STRING_MAX_LEN && j < S2.length) {
        T->ch[len] = S2.ch[j];
        len++;
        j++;
    }
    T->length = len;
    return OK;
}

// 用Sub返回串S的第pos个字符起长度为len的子串
Status SubString(SString *Sub, SString S, int pos, int len) {
    if (pos>= S.length || pos<1 || len <0 || len > S.length-pos + 1) return ERROR;
    for (int i = 0; i < len ; ++i) {
        Sub->ch[i] = S.ch[i+pos-1];
    }
    Sub->length = len;
    Sub->ch[len] = '\0';
    return OK;
}

// 索引值为0开始
//若主串S中存在和串T值相同的子串，则返回它在主串S中第pos个字符之后(包含)第一次出现的位置；否则函数值为0
// IndexBF
int IndexBF(SString S, SString T, int pos) {

    int i = pos-1;
    int j = 0;
    while (i< S.length && j < T.length) {
        if (S.ch[i] == T.ch[j]) {
            i++;
            j++;
        } else {
            i = i-j+1;
            j = 0;
        }
    }
    if (j == T.length) return i-T.length+1;
    else return 0;
}
// IndexKMP
int IndexKMP(SString S, SString T, int pos) {

    if (pos < 1 && pos >S.length) return 0;

    // 求next
    int * next = (int *) malloc(T.length * sizeof(int));
    int i = 0; // 首索引位置
    next[i] = -1; // 首索引的next值，是一个不存在的值
    int j = -1; // j初始值指的是首索引的next值
    while (i<T.length-1) { // 当前的next值可以求到下一个元素的next值，无须遍历完
        if (j == -1 || T.ch[i] == T.ch[j]) {
            i++;
            j++;
            next[i] = j;
        } else {
            j = next[j];
        }
    }

    i = pos-1;
    j = 0;
    while (i< S.length && j < T.length) {
        if (j == -1 || S.ch[i] == T.ch[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
    }
    if (j == T.length) {
        free(next);
        return i-T.length+1;
    }
    else {
        free(next);
        return 0;
    }


}

int main() {
    char a[] = "sleep  all day jack";
    char b[] = "kent sleep all day";
    char c[] = "";
    char d[] = "jack";
    SString A;
    SString B;
    SString C;
    SString D;
    StrAssign(&A,a);
    StrAssign(&B,b);
    StrAssign(&C,c);
    StrAssign(&D,d);

    // 空串测试
    int bool = StrEmpty(C);
    printf("bool:%d\n", bool);
    // 复制串测试
    StrCopy(&C,B);
    PrintInfo(C);

    // 字符串比较
    printf("compare:%d\n", StrCompare(A,B));

    // 组成新串
    Concat(&C, A,B);
    PrintInfo(C);

    // 返回子串
    SubString(&C,A,3,5);
    PrintInfo(C);

    //BF算法测试
    PrintInfo(A);
    printf("BF:%d\n", IndexBF(A,D,1));

    //KMP算法测试
    PrintInfo(A);
    printf("KMP:%d\n", IndexKMP(A,D,1));
}