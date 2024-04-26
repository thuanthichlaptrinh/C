#include <bits/stdc++.h>
typedef int value;
typedef value *ArrPtr;

void initArrayPointer(ArrPtr *&a, int &n){
    a = new ArrPtr[n * sizeof(value)];
    for(int i = 0; i < n; i++){
        a[i] = new value[n * sizeof(value)];
    }
}
void deleteArrayPointer(ArrPtr *&a, int n){
    for(int i = 0; i < n; i++){
        delete[] a[i];
    }
    delete[] a;
}
void TaoMaTranVuong(ArrPtr *&a, int &n){
    printf("Nhap cap NxN: "); scanf("%d", &n);
    initArrayPointer(a, n);
    srand((unsigned)time(NULL));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int temp;
            temp = rand() % 199 - 99;
            a[i][j] = temp;
        }
    }
}
void XuatMaTranVuong(ArrPtr *a, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%4d", a[i][j]);
        }
        printf("\n\n");
    }
}
void TongPtuDuongCheoChinh(ArrPtr *a, int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j){
                sum += a[i][j];
            }
        }
    }
    printf("\nTONG CAC PHAN TU TREN DUONG CHEO CHINH LA: %d", sum);
} 
void TongPtuNamTrenDuongCheoChinh(ArrPtr *a, int n){
    int sum = 0;
    for(int i = 0; i < n - 1; i++){
        sum += a[i][i + 1];
    }
    printf("\nTONG CAC PHAN TU NAM TREN DUONG CHEO CHINH LA: %d", sum);
}
void TongPtuNamDuoiDuongCheoChinh(ArrPtr *a, int n){
    int sum = 0;
    for(int j = 0; j < n - 1; j++){
        sum += a[j + 1][j];
    }
    printf("\nTONG CAC PHAN TU NAM DUOI DUONG CHEO CHINH LA: %d", sum);
}
void TongPtuDuongCheoPhu(ArrPtr *a, int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += a[i][n - i - 1];
    }
    printf("\nTONG CAC PHAN TU DUONG CHEO PHU LA: %d", sum);
}
void TongPtuNamTrenDuongCheoPhu(ArrPtr *a, int n){
    int sum = 0;
    for(int i = 0; i < n - 1; i++){
        sum += a[i][n - i - 2];
    }
    printf("\nTONG CAC PHAN TU DUONG CHEO PHU LA: %d", sum);
}
void TongPtuNamDuoiDuongCheoPhu(ArrPtr *a, int n){
    int sum = 0;
    for(int i = 0; i < n - 1; i++){
        sum += a[i + 1][n - i - 1];
    }
    printf("\nTONG CAC PHAN TU DUOI CHEO PHU LA: %d", sum);
}

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
void SortPtuChanTangODongLe(ArrPtr *a, int n){
    for(int j = 0; j < n; j++){
        for (int i = 0; i < n - 1; i++){
            for (int k = 0; k < n - i - 1; k++){
                if(a[k][j] > a[k + 1][j]){
                    swap(a[k][j], a[k + 1][j]);
                }
            }
        }
    }
    printf("\nMA TRAN SAU KHI SAP XEP:\n");
    XuatMaTranVuong(a, n);
}

bool KiemTraChan(int n){
    if(n % 2 == 0)
        return true;
    return false;
}
int TongCacSoChan(ArrPtr *a, int n){
    int tong = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(KiemTraChan(a[i][j])){
                tong += a[i][j];
            }
        }
    }
    return tong;
}

int main(){
    ArrPtr *a = NULL;
    int n = 0;
    TaoMaTranVuong(a, n);
    printf("\nMA TRAN VUONG VUA NHAP:\n");
    XuatMaTranVuong(a, n);
    
    SortPtuChanTangODongLe(a, n);

    deleteArrayPointer(a, n);
    return 0;
}