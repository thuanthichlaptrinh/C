#include <stdio.h>
#include <conio.h>

const int MAX_DONG = 100;
const int MAX_COT = 100;

void NhapSoDong(int &n){
    do{
        printf("Nhap chi so dong: "); scanf("%d", &n);
        if(n < 0 || n > MAX_DONG){
            printf("Chi so dong phai nam trong doan [0;%d]", MAX_DONG);
        }
    }while(n < 0 || n > MAX_DONG);
}
void NhapSoCot(int &m){
    do{
        printf("Nhap chi so dong: "); scanf("%d", &m);
        if(m < 0 || m > MAX_COT){
            printf("Chi so dong phai nam trong doan [0;%d]", MAX_COT);
        }
    }while(m < 0 || m > MAX_COT);
}
void NhapMang2Chieu(int a[][MAX_COT], int &n, int &m){
    NhapSoDong(n);
    NhapSoCot(m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("Nhap a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}
void XuatMang2Chieu(int a[][MAX_COT], int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int a[MAX_DONG][MAX_COT];
    int n = 0, m = 0;
    NhapMang2Chieu(a, n, m);
    XuatMang2Chieu(a, n, m);

    getch();
    return 0;
}