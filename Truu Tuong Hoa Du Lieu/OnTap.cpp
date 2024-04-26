#include <bits/stdc++.h>

struct SanPham{
    char maSanPham[6], tenSanPham[21];
    int soLuong;
    float donGia;
    char nhaSanXuat[31], loaiSanPham[21];
};
typedef SanPham ItemType;

void NhapSanPham(ItemType &sp){
    printf("Nhap ma san pham: "); fflush(stdin); gets(sp.maSanPham);
    printf("Nhap ten san pham: "); gets(sp.tenSanPham);
    printf("Nhap so luong: "); scanf("%d", &sp.soLuong);
    printf("Nhap don gia: "); scanf("%f", &sp.donGia);
    printf("Nhap nha san xuat: "); fflush(stdin); gets(sp.nhaSanXuat);
    printf("Nhap loai san pham: "); gets(sp.loaiSanPham);
}
void NhapDanhSachSanPham(ItemType *&a, int &n){
    printf("Nhap so luong san pham: "); scanf("%d", &n); getchar();
    a = new ItemType[n];
    for(int i = 0; i < n; i++){
        printf("\n# NHAP SAN PHAM THU %d\n", i + 1);
        ItemType sp;
        NhapSanPham(sp);
        a[i] = sp;
    }
}
void XuatSanPham(ItemType sp){
    printf("%-5s%-20s%-5d%-7.2f%-30s%-20s", sp.maSanPham, sp.tenSanPham, sp.soLuong, sp.donGia, sp.nhaSanXuat, sp.loaiSanPham);
}
void XuatDanhSachSanPham(ItemType *a, int n){
    for(int i = 0; i < n; i++){
        printf("\n%-5d", i + 1);
        XuatSanPham(a[i]);
    }
}
void XuatSanPhamNsxLaneige(ItemType *a, int n){
    for(int i = 0; i < n; i++){
        if(strcmp(a[i].nhaSanXuat, "Laneige") == 0){
            printf("\n%-5d", i + 1);
            XuatSanPham(a[i]);
        }
    }
}
void TinhTongSoLuongSanPhamTenKem(ItemType *a, int n){
    int tong = 0;
    for(int i = 0; i < n; i++){
        if(strncmp(a[i].tenSanPham, "Kem", 3) == 0){
            tong += a[i].soLuong;
        }
    }
    printf("\nSO LUONG SAN PHAM CO TEN BAT DAU LA KEM: %d", tong);
}
int TimMax(ItemType *a, int n){
    int max = a[0].donGia;
    for(int i = 1; i < n; i++){
        if(a[i].donGia > max){
            max = a[i].donGia;
        }
    }
    return max;
}
void XuatDonGiaCaoNhat(ItemType *a, int n){
    int max = TimMax(a, n);
    for(int i = 0; i < n; i++){
        if(a[i].donGia == max){
            printf("\n%-5d", i + 1);
            XuatSanPham(a[i]);
        }
    }
}
void DemSanPhamCoNsxLaSenka(ItemType *a, int n){
    int dem = 0;
    for(int i = 0; i < n; i++){
        if(strcmp(a[i].nhaSanXuat, "Senka") == 0){
            dem++;
        }
    }
    printf("\nSO LUONG SAN PHAM CUA NHA SAN XUAT SENKA: %d", dem);
}
void swap(ItemType &a, ItemType &b){
    ItemType temp = a;
    a = b;
    b = temp;
}
void InterChangeSort(ItemType *a, int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i].maSanPham > a[j].maSanPham){
                swap(a[i], a[j]);
            }
        }
    }
    printf("\nDANH SACH SAU KHI SAP XEP THEO MA SAN PHAM\n");
    XuatDanhSachSanPham(a, n);
}

void Xoa(ItemType *a, int &n, int vt){
    for(int i = vt; i < n - 1; i++){
        a[i] = a[i + 1];
    }
    n--;
}
void XoaSanPhamCoSoLuong0(ItemType *a, int &n){
     for(int i = 0; i < n; i++){
        if(a[i].soLuong == 0){
           Xoa(a, n, i);
        }
    }
}

int main(){
    ItemType *a = NULL;
    int n = 0;
    NhapDanhSachSanPham(a, n);
    XuatDanhSachSanPham(a, n);

    XoaSanPhamCoSoLuong0(a, n);
    XuatDanhSachSanPham(a, n);

    delete[] a;
    return 0;
}