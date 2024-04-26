#include <bits/stdc++.h>

//============================ KỸ THUẬT NHẬP XUẤT MẢNG ============================
void NhapSoDuong(int &n);
void NhapMang(int *&a, int &n);
void TaoMang(int *&a, int &n);
void XuatMang(int *a, int n);
//============================ KỸ THUẬT TÌM KIẾM ============================
//============================ KỸ THUẬT SẮP XẾP ============================
//============================ KỸ THUẬT LIỆT KÊ ============================
//============================ KỸ THUẬT ĐẾM ============================
// Bài 218: Đếm số đối xứnɡ tronɡ mảnɡ -------------
bool KiemTraSoDoiXung(int n);
int DemSoDoiXungTrongMang(int *a, int n);
//============================ KỸ THUẬT TÍNH TOÁN ============================
//============================ KỸ THUẬT ĐẶT CỜ HIỆU ============================
//============================ KỸ THUẬT ĐẶT LÍNH CANH ============================
//============================ KỸ THUẬT THÊM ============================
//============================ KỸ THUẬT XÓA ============================
//============================ KỸ THUẬT XỬ LÝ MẢNG CON ============================



int main(){
    int *a = NULL;
    int n = 0;
    TaoMang(a, n);
    printf("\nMANG VUA NHAP LA: ");
    XuatMang(a, n);


    delete[] a;
    return 0;
}
//==============================================================
void NhapSoDuong(int &n){
    try{
        printf("Nhap so duong: "); scanf("%d", &n);
        if(n <= 0){
            throw 101;
        }
    }
    catch(int errCode){
        if(errCode == 101){
            printf("\nVui long nhap so duong !\n");
        }
        NhapSoDuong(n);
    }
}
//==============================================================
void NhapMang(int *&a, int &n){
    printf("Nhap so luong phan tu mang: "); scanf("%d", &n);
    a = new int[n];
    for(int i = 0; i < n; i++){
        int temp;
        printf("Nhap a[%d] = ", i); scanf("%d", &temp);
        a[i] = temp;
    }
}
//==============================================================
void TaoMang(int *&a, int &n){
    printf("Nhap so luong phan tu mang: "); scanf("%d", &n);
    a = new int[n];
    srand((unsigned)time(NULL));
    for(int i = 0; i < n; i++){
        int temp;
        temp = rand() % 199 - 99;
        a[i] = temp;
    }
}
//==============================================================
void XuatMang(int *a, int n){
    for(int i = 0; i < n; i++){
        printf("%4d", a[i]);
    }
}
//==============================================================
bool KiemTraSoDoiXung(int n){
    int sum = 0;
    int temp = n;
    while (temp != 0){
        sum = sum * 10  + (temp % 10);
        temp /= 10;
    }
    if(sum == n){
        return true;
    }
    return false;
}
//==============================================================
int DemSoDoiXungTrongMang(int *a, int n){
    int dem = 0;
    for(int i = 0; i < n; i++){
        if(KiemTraSoDoiXung(a[i]) == true){
            dem++;
        }
    }
    return dem;
}
//==============================================================