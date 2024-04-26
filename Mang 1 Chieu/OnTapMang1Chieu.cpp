#include <bits/stdc++.h>

void NhapSoNguyen(int n){
    try{
       printf("Nhap so nguyen duong: ");
       scanf("%d", &n);
       if(n <= 0){
            throw 101;
       } 
    }
    catch(int errCode){
        if(errCode == 101){
            printf("Vui long nhap so duong lon hon 0 !");
        }
        NhapSoNguyen(n);
    }
}
void NhapMang(int *&a, int &n){
    printf("Nhap so luong phan tu: "); scanf("%d", &n);
	a = new int[n];
	for (int i = 0; i < n; i++) {
		int temp;
        printf("Nhap a[%d] = ", i); scanf("%d", &temp);
		a[i] = temp;
	}
}
void TaoMang(int *&a, int &n){
    printf("Nhap so luong phan tu: "); scanf("%d", &n);
	a = new int[n];
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++) {
		int temp;
		temp = rand() % 101 - 50;
		a[i] = temp;
	}
}
void XuatMang(int *a, int n){
    for(int i = 0; i < n; i++){
        printf("%4d", a[i]);
    }
}

bool KiemTraChuSoDau(int n){
    n = abs(n);
    while(n >= 10){
        n /= 10;
    }
    if(n % 2 == 0){
        return true;
    }
    return false;
}
void LietKeChuSoDauLaChan(int *a, int n){
    bool check = false;
    for(int i = 0; i < n; i++){
        if(KiemTraChuSoDau(a[i]) == true){
            printf("%4d", a[i]);
            check = true;
        }
    }   
    if(check == false){
        printf("Mang khong co chu so dau tien la chu so chan !\n");
    }
}

bool KiemTraChuSoHangChuc(int n){ 
    n = abs(n);
    if(n >= 10){
        n /= 10;
        int x = n % 10;
        if(x % 2 == 0)
            return true;
    }
    return false;
}
void LietKeChuSoHangChucLaChan(int *a, int n){
    int tong = 0;
    for(int i = 0; i < n; i++){
        if(KiemTraChuSoHangChuc(a[i]) == true){
            //printf("%4d", a[i]);
            tong += a[i];
        }
    }         
   printf("\nTong cac chu so hang chuc = %d\n", tong);
}

bool KiemTraSoDoiXung(int n){
   // n = abs(n);
    int sum = 0, temp = n;
    while(n != 0){
        sum = sum * 10 + (n % 10);
        n /= 10;
    }
    if(sum == temp){
        return true;
    }
    return false;
}
void DemSoDoiXung(int *a, int n){
    int dem = 0;
    for(int i = 0; i < n; i++){
        if(KiemTraSoDoiXung(a[i]) == true){
            dem++;
        }
    }
    printf("\nSO LUONG SO DOI XUNG LA: %d\n", dem);
}

bool KiemTraSoTanCungLa5(int n){
    n = abs(n);
    int x = n % 10;
    if(x == 5){
        return true;
    }
    return false;
}
void DemSoTanCungLa5(int *a, int n){
    int dem = 0;
    for(int i =0; i < n; i++){
        if(KiemTraSoTanCungLa5(a[i]) == true){
            dem++;
        }
    }
    printf("\nSO LUONG SO CO CHU SO TAN CUNG LA 5: %d\n", dem);
}

int TimGiaTriChanDauTien(int *a, int n){
    for(int i = 0; i < n; i++){
        if(a[i] % 2 == 0){
            return a[i];
        }
    }
    return -1; // ko tim thay
}
int TimGiaTriLeCuoiCung(int *a, int n){
    for(int i = n - 1; i >= 0; i--){
        if(a[i] % 2 != 0){
            return a[i];
        }
    }
    return -1;
}

bool KiemTraSNT(int n){
    if(n < 2){
        return false;
    }
    int x = sqrt(n);
    for(int i = 2; i <= x; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}
void XuatSoNguyenTo(int *a, int n){
    bool check = false;
    for(int i = 0; i < n; i++){
        if(KiemTraSNT(a[i]) == true){
            printf("%4d", a[i]);
            check = true;
        }
    }   
    if(check == false){
        printf("Mang khong co phan tu la so nguyen to !\n");
    }
}

bool KiemTraSoHoanThien(int x){
    if(x < 1){
        return false;
    }
    int sum = 0;
    for(int i = 1; i < x; i++){
        if(x % i == 0){
            sum += i;
        }
    }
    if(sum == x){
        return true;
    }
    return false;
}
void XuatSoHoanThien(int *a, int n){
    bool check = false;
    for(int i = 0; i < n; i++){
        if(KiemTraSoHoanThien(a[i]) == true){
            printf("%4d", a[i]);
            check = true;
        }
    }   
    if(check == false){
        printf("Mang khong co phan tu la so hoan thien !\n");
    }
}

void XuatPhanTuViTriChan(int *a, int n){
    printf("\nCAC PHAN TU O VI TRI CHAN: ");
    for(int i = 0; i < n; i++){
        if(i % 2 == 0){
            printf("%4d", a[i]);
        }
    }
}
void XuatPhanTuViTriLe(int *a, int n){
    printf("\nCAC PHAN TU O VI TRI LE: ");
    for(int i = 0; i < n; i++){
        if(i % 2 != 0){
            printf("%4d", a[i]);
        }
    }
}
void XuatGiaTriLonNhat(int *a, int n){
    int max = 0;
    for(int i = 1; i < n; i++){
        if(a[i] > a[max]){
            max = i;
        }
    }
    printf("\nGIA TRI LON NHAT LA %d TAI VI TRI %d\n", a[max], max);
}

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
void InterchangeSort(int *a, int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i] > a[j]){
                swap(a[i], a[j]);
            }
        }
    }
}
void InterchangeSort_2(int *a, int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i] < a[j]){
                swap(a[i], a[j]);
            }
        }
    }
}
void DoTatCaGiaTriVaoMangPhu(int *b, int m, int *c, int n){
    int *a = new int[m + n];
    int k = 0;
    for(int i = 0; i < m; i++){
        a[k++] = b[i];
    }
    for(int i = 0; i < n; i++){
        a[k++] = c[i];
    }
    InterchangeSort(a, k);
    XuatMang(a, k);
    delete[] a;
}

bool KiemTraChuSoLe(int n){
    n = abs(n);
    if(n == 0){
        return false;
    }
    while(n != 0){
        int temp = n % 10;
        if(temp % 2 == 0){
            return false;
        }
        n /= 10;
    }
    return true;
}

void XuatPhanTuCoAllChuSoLe(int *a, int n){
    printf("\nCAC PHAN TU CO CHU SO TOAN LE: ");
    bool check = false;
    for(int i = 0; i < n; i++){
        if(KiemTraChuSoLe(a[i]) == true){
            printf("%4d", a[i]);
            check = true;
        }
    }
    if(check == false){
        printf("khong co phan tu co chu so toan le !\n");
    }
}

bool KiemTraMangToanChan(int *a, int n){
    for(int i = 0; i < n; i++){
        if(a[i] % 2 != 0){
            return false;
        }
    }
    return true;
}

void KiemTraMangXenKe(int *a, int n){
    bool check = true;
    for(int i = 0; i < n - 1; i++){
        if((a[i] % 2 == 0 && a[i + 1] % 2 == 0) || (a[i] % 2 != 0 && a[i + 1] % 2 != 0)){
            check = false;
            break;
        }
    }
    if(check == true){
        printf("\nYES");
    }
    else{
        printf("\nNO");
    }
}
void LietKeCacSntNhoHonN(int *a, int n, int x){
    bool check = true;
    for(int i = 0; i < n; i++){
        if(KiemTraSNT(a[i]) == true && a[i] < x){
            printf("%4d", a[i]);
            check = false;
        }
    }
    if(check == true){
        printf("khong co snt be hon %d !\n", x);
    }
}

void LietKeSoLanXuatHien(int *a, int n){
    for(int i = 0; i < n; i++){
        bool check = true;
        for(int j = i - 1; j >= 0; j--){
            if(a[i] == a[j]){
                check = false;
                break;
            }
        }
        if(check == true){
            int count = 0;
            for(int k = 0; k < n; k++){
                if(a[i] == a[k]){
                    count++;
                }
            }
            printf("%d xuat hien %d lan\n", a[i], count);
        }
    }
}
void SapXepMangSoChanTangLeGiam(int *a, int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(i % 2 == 0){
                if(a[i] > a[j]){
                    swap(a[i], a[j]);
                }
            }
            else{
                if(a[i] < a[j]){
                    swap(a[i], a[j]);
                }
            }
        }
    }
    printf("\nMANG SAU KHI SAP XEP: ");
    XuatMang(a, n);
}
void SapXepChanDauLeCuoi(int *a, int n){
    int *b = new int[n];
    int *c = new int[n];
    int k = 0, l = 0;
    // đổ các phần tử vào mảng
    for(int i = 0; i < n; i++){
        if(a[i] % 2 == 0){ // nếu phần tử nào là chẵn thì đổ vào mảng b
            b[k++] = a[i]; 
        }
        else{ // nếu phần tử nào là lẻ thì đổ vào mảng c
            c[l++] = a[i];
        }
    }

    // sau đó đổ các phần tử ngược về lại mảng ban đầu
    n = 0;
    for(int i = 0; i < k; i++){
        a[n++] = b[i];
    }
    for(int i = 0; i < l; i++){
        a[n++] = c[i];
    }

    printf("\nMANG SAU KHI SAP XEP: ");
    XuatMang(a, n);
    delete[] b;
    delete[] c;
}

int Min(int *a, int n){
    int min = a[0];
    for(int i = 1; i < n; i++){
        if(a[i] < min){
            min = a[i];
        }
    }
    return min;
}
void Min2(int *a, int n){
    int min = Min(a, n);
    int x = a[0];
    for(int i = 1; i < n; i++){
        if(a[i] > min && a[i] <= x){
            x = a[i];
        }
    }
    printf("\nGIA TRI MIN THU 2 LA: %d\n", x);
}
void SapXepChanTang(int *a ,int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i] % 2 == 0){
                if(a[i] > a[j]){
                    swap(a[i], a[j]);
                }
            }
        }
    }
    printf("\nMANG SAU KHI SAP XEP CHAN TANG: ");
    XuatMang(a, n);
}

// đếm phần tử có số lần xuất hiện nhiều nhất
int DemSoLanXuatHienX(int *a, int n, int x){
    int dem = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == x){
            dem++;
        }
    }
    return dem;
}
int SoLanXuatHienMax(int *a, int n){
    int max = DemSoLanXuatHienX(a, n, a[0]);
    for(int i = 1; i < n; i++){
        int dem = DemSoLanXuatHienX(a, n, a[i]);
        if(dem > max){
            max = dem;
        }
    }
    return max;
}
void XuatPhanTuCoSoLanXuatHienMax(int *a, int n){
    int max = SoLanXuatHienMax(a, n);
    for(int i = 0; i < n; i++){
        bool check = true;
        for(int j = i - 1; j >= 0; j--){
            if(a[i] == a[j]){
                check = false; 
                break;
            }
        }
        if(check == true){
            int dem = DemSoLanXuatHienX(a, n, a[i]);
            if(dem == max){
                printf("\nSo lan xuat hien nhieu nhat la %d voi %d lan", a[i], dem);
            }
        }
    }
}

/*Bài 221: Cho biết sự tươnɡ quɑn ɡiữɑ số lượnɡ chẵn và lẻ tronɡ mảnɡ
    Hàm trả về 1 tronɡ 3 ɡiá trị -1, 0, 1
    Giá trị -1 là chẵn nhiều hơn lẻ
    Giá trị 0 là chẵn bằnɡ lẻ
    Giá trị 1 là chẵn ít hơn lẻ */
int KiemTraSuTuongQuan(int *a, int n){
    int demLe = 0, demChan = 0;

    for(int i = 0; i < n; i++){
        if(a[i] % 2 == 0){
            demChan++;
        }
        else{
            demLe++;
        }
    }

    if(demChan == demLe)
        return 0;
    else if(demChan < demLe)
        return 1;
    else
        return -1;
}
void KiemTraSuTuongQuan_Xuat(int *a, int n){
    int kq = KiemTraSuTuongQuan(a, n);
    if(kq == 0){
        printf("Chan bang le\n");
    }
    else if(kq == -1){
        printf("Chan nhieu hon le\n");
    }
    else{
        printf("Chan it hon le\n");
    }
}

//Bài 225: Đếm số lượnɡ ɡiá trị lớn nhất có tronɡ mảnɡ
int TimMax(int *a, int n){
    int max = a[0];
    for(int i = 1; i < n; i++){
        max = (a[i] > max) ? a[i] : max;
    }
    return max;
}
int DemGiaTriMax(int *a, int n, int x){
    int dem = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == x){
            dem++;
        }
    }
    return dem;
}
void DemSoLuongGiaTriLonNhat(int *a, int n){
    int max = TimMax(a, n);
    int dem = DemGiaTriMax(a, n, max);
    printf("Gia tri lon nhat la %d xuat hien %d lan\n", max, dem);
}

int TimSoHoanThienDau(int *a, int n){
    for(int i = 0; i < n; i++){
        if(KiemTraSoHoanThien(a[i]) == true){
            return i;
        }
    }
    return 0;
}
int HoanThienNhoNhat(int *a, int n){
    int min = TimSoHoanThienDau(a, n);
    for(int i = min + 1; i < n; i++){
        if(KiemTraSoHoanThien(a[i]) && a[i] < a[min]){
            min = i;
        }
    }
    return a[min];
}

int ViTriDuongDau(int *a, int n){
    for(int i = 0; i < n; i++){
        if(a[i] > 0){
            return i;
        }
    }
    return -1;
}
int ViTriDuongNhoNhat(int *a, int n){
    int min = ViTriDuongDau(a, n);
    if(min == -1){
        return -1; // khong co so duong 
    }
    for(int i = min + 1; i < n; i++){
        if(a[i] > 0 && a[i] < a[min]){
            min = i;
        }
    }
    return min;
}

int SoNguyenToDau(int *a, int n){
    for(int i = 0; i < n; i++){
        if(KiemTraSNT(a[i]) == true){
            return i;
        }
    }
    return -1;
}
int NguyenToNhoNhat(int *a, int n){
    int max = TimMax(a, n);
    max += 1;
    while(!KiemTraSNT(max)){
        ++max;
    }
    return max;
}

int ChanDauTien(int *a, int n){
    for(int i = 0; i < n; i++){
        if(a[i] % 2 == 0){
            return i;
        }
    }
    return -1;
}
void LietKeChanLonNhat(int *a, int n){
    int max = ChanDauTien(a, n);
    for(int i = max + 1; i < n; i++){
        if(a[i] % 2 == 0 && a[i] > a[max]){
            max = i;
        }
    }
    printf("\nVI TRI CHAN LON NHAT LA: ");
    for(int i = 0; i < n; i++){
        if(a[i] == a[max]){
            printf("%4d", i);
        }
    }
}

void DuaSoKhongVeDau(int a[], int na) {
    int j = 0;
    for(int i = 1; i < na; i++){
        if(a[i] == 0){
            swap(a[j], a[i]);
            j++;
        }
    }
}

// de quy
int DemSoDuongDeQuy(int *a, int n){
    if(n == 0){
        return 0;
    }
    if(a[n - 1] > 0){
        return 1 + DemSoDuongDeQuy(a, n - 1);
    }
    return DemSoDuongDeQuy(a, n - 1);
}

int ViTriLeDau(int *a, int n){
    for(int i = 0; i < n; i++){
        if(a[i] % 2 != 0){
            return i;
        }
    }
    return -1;
}
int ViTriLeLonNhat(int *a, int n){
    int max = ViTriLeDau(a, n);
    for(int i = max + 1; i < n; i++){
        if(a[i] % 2 != 0 && a[i] > a[max]){
            max = i;
        }
    }
    return max;
}

int ChiaHetCho3(int *a, int n){
    for(int i = 0; i < n; i++){
        if(a[i] % 3 == 0){
            return i;
        }
    }
    return 1;
}
int ViTriChiaHetCho3Min(int *a, int n){
    int min =ChiaHetCho3(a, n);
    for(int i = min + 1; i < n; i++){
        if(a[i] % 3 == 0 && a[i] < a[min]){
            min = i;
        }
    }
    return min;
}

void inDayConTangDanDaiNhat(int *a, int n){

}

int main(){
    int *a = NULL, n = 0;
    TaoMang(a, n);
    //NhapMang(a, n);
    printf("\nMANG VUA TAO: "); 
    XuatMang(a, n);
    // int *b = NULL, *c = NULL, m = 0, n = 0;
    // //NhapMang(a, n);
    // TaoMang(b, m);
    // printf("\nMANG VUA TAO: "); 
    // XuatMang(b, m);
    // TaoMang(c, n);
    // printf("\nMANG VUA TAO: "); 
    // XuatMang(c, n);
    
    //DemSoTanCungLa5(a, n);
    //printf("\nGia tri chan dau tien: %d\n", TimGiaTriChanDauTien(a, n));
    //printf("Gia tri le cuoi cung: %d\n", TimGiaTriLeCuoiCung(a, n));
    //XuatPhanTuViTriChan(a, n);
    //DoTatCaGiaTriVaoMangPhu(b, m, c, n);
    //LietKeCacSntNhoHonN(a, n, 59);
    //int kq = NguyenToNhoNhat(a, n);
    //printf("\nLA: %d", kq);
    //LietKeChanLonNhat(a, n);
    printf("\nMANG SAU KHI THUC HIEN: %d", ViTriChiaHetCho3Min(a, n));

    delete[] a;
    //delete[] b;
    //delete[] c;
    return 0;
}