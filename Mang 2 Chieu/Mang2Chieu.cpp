#include <bits/stdc++.h>
typedef int value;
typedef value *ArrPtr;

void initArrayPointer(ArrPtr *&a, int &m, int &n){
    a = new ArrPtr[m * sizeof(value)];
    for(int i = 0; i < m; i++){
        a[i] = new value[n * sizeof(value)];
    }
}
void deleteArrayPointer(ArrPtr *&a, int m, int n){
    for(int i = 0; i < m; i++){
        delete[] a[i];
    }
    delete[] a;
}
void TaoMang2Chieu(ArrPtr *&a, int &m, int &n){
    printf("Nhap chi so dong: "); scanf("%d", &m);
    printf("Nhap chi so cot: "); scanf("%d", &n);
    initArrayPointer(a, m, n);
    srand((unsigned)time(NULL));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            int temp;
            temp = rand() % 199 - 99;
            a[i][j] = temp;
        }
    }
}
void XuatMang2Chieu(ArrPtr *a, int m, int n){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("%4d", a[i][j]);
        }
        printf("\n\n");
    }
}

// Tính tổng các phần tử có chữ số đầu là chữ số lẻ
bool KiemTraChuSoDau(int n){
    int temp = 0;
    while(n != 0){
        temp = n % 10;
        n /= 10;
    }
    if(temp % 2 != 0)
        return true;
    return false;
}
int TongPhanTuCoChuSoDauLe(int **a, int m, int n){
    int sum = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(KiemTraChuSoDau(a[i][j]) == true){
                sum += a[i][j];
            }
        }
    }
    return sum;
}
// Liệt kê các số hoàn thiện trong ma trận
bool KiemTraSoHoanThien(int n){
    if(n <= 0)
        return false;
    int sum = 0;
    for(int i = 1; i < n; i++){
        if(n % i == 0){
            sum += i;
        }
    }
    if(n == sum) return true;
    else return false;
}
void LietKeSoHoanThien(ArrPtr *a, int m, int n){
    bool check = true;
    printf("\nCAC SO HOAN THIEN LA: ");
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(KiemTraSoHoanThien(a[i][j]) == true){
                printf("%4d", a[i][j]);
                check = false;
            }
        }
    }
    if(check == true){
        printf("khong co so hoan thien trong ma tran !");
    }
}

int TongCacPhanTuLonNhonTriTruyetDoiSauNo(ArrPtr *a, int m, int n){
    int tong = 0;
    for(int i = 0; i < m; i++){ 
        for(int j = 0; j < n - 1; j++){
            if(a[i][j] > abs(a[i][j + 1])){
                printf("%4d", a[i][j]);
                tong += a[i][j];
            }
        }
    }
    return tong;
}

void TinhTongTrenDong(ArrPtr *a, int m, int n){
    for(int i = 0; i < m; i++){
        int sum = 0;
        for(int j = 0; j < n; j++){
            sum += a[i][j];
        }
        printf("\nTONG TREN DONG %d LA: %d", i, sum);
    }
}

void TinhTongTrenDuongBien(ArrPtr *a, int m, int n){
    int sum = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(i == 0 || j == 0 || i == m - 1 || j == n - 1){
                sum += a[i][j];
            }
        }
    }        
    printf("\nTONG CAC PHAN TU TREN DUONG BIEN LA: %d", sum);
}

void DemTanSuatXuatHien(ArrPtr *a, int m, int n){
    int *temp = new int[m * n], k = 0;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            temp[k++] = a[i][j];
        }
    }

    for(int i = 0; i < k; i++){
        bool check = true;
        for(int j = i - 1; j >= 0; j--){
            if(temp[i] == temp[j]){
                check = false;
                break;
            }
        }
        if(check == true){
            int dem = 0;
            for(int l = 0; l < k; l++){
                if(temp[i] == temp[l]){
                    dem++;
                }
            }
            printf("\nPHAN TU %d XUAT HIEN %d LAN", temp[i], dem);
        }
    }
    delete[] temp;
}

void DemTanSuatXuatHienX(int **a, int m, int n, int x){
    int dem = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(a[i][j] == x){
                dem++;
            }
        }
    }
    printf("\nPHAN TU x = %d XUAT HIEN %d LAN", x, dem);
}

bool KiemTraSNT(int n){
    if(n < 2){
        return false;
    }
    int sl = sqrt(n);
    for(int i = 2; i <= sl; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}
bool KiemTraSoLe(int n){
    if(n % 2 != 0){
        return true;
    }
    return false;
}
bool KiemTraSoChan(int n){
    if(n % 2 == 0){
        return true;
    }
    return false;
}
void DemSoChanLeDuongAmSNT(int **a, int m, int n){
    int demLe = 0, demChan = 0,  demAm = 0, demDuong = 0, demSNT = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(KiemTraSoChan(a[i][j]) == true)
                demChan++;
            if(KiemTraSoLe(a[i][j]) == true)
                demLe++;
            if(a[i][j] > 0)
                demDuong++;
            if(a[i][j] < 0)
                demAm++;
            if(KiemTraSNT(a[i][j]) == true)
                demSNT++;
        }
    }
    printf("\nSO LUONG SO CHAN: %d", demChan);
    printf("\nSO LUONG SO LE: %d", demLe);
    printf("\nSO LUONG SO Duong: %d", demDuong);
    printf("\nSO LUONG SO Am: %d", demAm);
    printf("\nSO LUONG SO SNT: %d", demSNT);
}

int TinhTongCot(int **a, int m, int n, int cot){
    int tong = 0;
    for(int i = 0; i < m; i++){
        tong += a[i][cot];
    }
    return tong;
} 
int LietKeCotCoTongMin(int **a, int m, int n){
    int cot = 0;
    int min = TinhTongCot(a, m, n, cot);
    for(int j = 1; j < n; j++){
        int x = TinhTongCot(a, m, n, j);
        if(x <= min){
            min = x;
            cot = j;
        }
    }
    printf("\nCOT CO TONG NHO NHAT LA COT %d VOI TONG = %d", cot, min);
}

int DemSoHoanThien(ArrPtr *a, int m, int n, int dong){
    int dem = 0;
    for(int j = 0; j < n; j++){
        if(KiemTraSoHoanThien(a[dong][j]) == true){
            dem++;
        }
    }
    return dem;
}
void LietKeDongCoNhieuSoHoanThien(ArrPtr *a, int m, int n){
    int max = DemSoHoanThien(a, m, n, 0);
    int d = 0;
    for(int i = 1; i < m; i++){
        int dem = DemSoHoanThien(a, m, n, i);
        if(dem > max){
            max = dem;
            d = i;
        }
    }
    printf("\nDONG CO NHIEU SO HOAN THIEN NHAT LA: %d", d);
}

int DemX(int *temp, int k, int x){
    int dem = 0;
    for(int i = 0; i < k; i++){
        if(temp[i] == x){
            dem++;
        }
    }
    return dem;
}
int DemMax(int *temp, int k){
    int max = DemX(temp, k, temp[0]);
    for(int i = 1; i < k; i++){
        int dem = DemX(temp, k, temp[i]);
        if(dem > max){
            max = dem;
        }
    }
    return max;
}
void TimGiaTriXuatHienNhieuNhat(ArrPtr *a, int m, int n){
    int *temp = new int[m * n], k = 0; 
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            temp[k++] = a[i][j]; 
        }
    }
    int max = DemMax(temp, k);
    for(int i = 0; i < k; i++){
        bool check = true;
        for(int j = i - 1; j >= 0; j--){
            if(temp[i] == temp[j]){
                check = false;
                break;
            }
        }
        if(check == true){
            int dem = 0;
            for(int l = 0; l < k; l++){
                if(temp[i] == temp[l]){
                    dem++;
                }
            }
            if(dem == max){
                printf("\n%d VOI SO LAN XUAT HIEN %d lan", temp[i], dem);
            }
        }
    }
}

int TimSoNguyenTo(ArrPtr *a, int m, int n){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(KiemTraSNT(a[i][j]) == true){
                return a[i][j];
            }
        }
    }
}
int TimSoNguyenSoNhoNhat(ArrPtr *a, int m, int n){
    int min = TimSoNguyenTo(a, m, n);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(KiemTraSNT(a[i][j]) == true && a[i][j] < min){
                min = a[i][j];
            }
        }
    }
    return min;
}
int MaxTrenDong(ArrPtr *a, int m, int n, int dong){
    int max = a[dong][0];
    for(int j = 1; j < n; j++){
        if(a[dong][j] > max){
            max = a[dong][j];
        }
    }
    return max;
}
void TimPhanTuLonNhatTrenDong(ArrPtr *a, int m, int n){
    for(int i = 0; i < m; i++){
        int max = MaxTrenDong(a, m, n, i);
        printf("\nMAX TREN DONG %d LA %d", i, max);
    }
}
int MinCot(ArrPtr *a, int m, int n, int k){
    int min = a[0][k];
    for(int i = 1; i < m; i++){
        if(a[i][k] < min){
            min = a[i][k];
        }
    }
    return min;
}
void TimPhanTuLonNhatTrenCot(ArrPtr *a, int m, int n){
    for(int j = 0; j < n; j++){
        int min = MinCot(a, m, n, j);
        printf("\nMIN TREN COT %d LA %d", j, min);
    }
}
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
void SapXepTang(int *a, int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i] > a[j]){
                swap(a[i], a[j]);
            }
        }
    }
}
void SapXepGiam(int *a, int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i] < a[j]){
                swap(a[i], a[j]);
            }
        }
    }
}
void SapXepDongChanTangDongLeGiam(ArrPtr *a, int m, int n){
    int *chan = new int[m * n / 2];
    int *le = new int[m * n / 2];
    int c = 0, l = 0;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(i % 2 == 0){
                chan[c++] = a[i][j];
            }
            else{
                le[l++] = a[i][j];
            }
        }
    }
    SapXepTang(chan, c);
    SapXepGiam(le, l);
    c = 0, l = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(i % 2 == 0){
                a[i][j] = chan[c++];
            }
            else{
                a[i][j] = le[l++];
            }
        }
    }
    printf("\nMANG SAU KHI SAP XEP:\n");
    XuatMang2Chieu(a, m, n);

    delete[] chan;
    delete[] le;
}
void SapXepDongChanTangDongLeGiam1(ArrPtr *a, int m, int n){
    for(int i = 0; i < m; i++){
        if(i % 2 == 0){
            for(int j = 0; j < n - 1; j++){
                for(int k = 0; k < n - i - 1; k++){
                    if(a[i][k] > a[i][k + 1]){
                        swap(a[i][k], a[i][k + 1]);
                    }
                }
            }
        }
        else{
            for(int j = 0; j < n - 1; j++){
                for(int k = 0; k < n - i - 1; k++){
                    if(a[i][k] < a[i][k + 1]){
                        swap(a[i][k], a[i][k + 1]);
                    }
                }
            }
        }
    }
    printf("\nMANG SAU KHI SAP XEP:\n");
    XuatMang2Chieu(a, m, n);
}

void SapXepCotChanTangCotLeGiam(ArrPtr *a, int m, int n){
    for(int j = 0; j < n; j++){
        if(j % 2 == 0){
            for(int i = 0; i < m - 1; i++){
                for(int k = 0; k < m - i - 1; k++){
                    if(a[k][j] > a[k + 1][j]){
                        swap(a[k][j], a[k + 1][j]);
                    }
                }
            }
        }
        else{
            for(int i = 0; i < m - 1; i++){
                for(int k = 0; k < m - i - 1; k++){
                    if(a[k][j] < a[k+1][j]){
                        swap(a[k][j], a[k+1][j]);
                    }
                }
            }
        }
    }
    printf("\nMANG SAU KHI SAP XEP:\n");
    XuatMang2Chieu(a, m, n);
}

bool KiemTraChan(int x){
    if(x % 2 == 0){
        return true;
    }
    return false;
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
}

int main(){
    ArrPtr *a = NULL;
    int m = 0, n= 0;
    initArrayPointer(a, m, n);
    TaoMang2Chieu(a, m, n);
    printf("\nMANG VUA TAO LA:\n");
    XuatMang2Chieu(a, m, n);

    //int kq = TongCacPhanTuLonNhonTriTruyetDoiSauNo(a, m, n);
    //printf("\nTONG = %d", kq);
    //printf("\nTONG CAC PHAN TU CO CHU SO DAU LA LE: %d\n", kq);
    //LietKeSoHoanThien(a, m, n);
    //DemTanSuatXuatHienX(a, m, n, 2);
    SapXepDongChanTangDongLeGiam1(a, m, n);

    deleteArrayPointer(a, m, n);
    return 0;
}