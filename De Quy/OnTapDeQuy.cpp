#include <bits/stdc++.h>

//==============================================================
int TinhTongMang(int a[], int n){
	if (n == 1)
		return a[0];
	return a[n - 1] + TinhTongMang(a, n - 1);
}
//==============================================================
int TinhTichMang(int *a, int n){
	if (n == 1){
		return a[0];
	}
	return a[n - 1] * TinhTichMang(a, n - 1);
}
//==============================================================
int TimPhanTuNhoNhat(int *a, int n){
	if (n == 1){
		return a[0];
	}
	else{
		int min = TimPhanTuNhoNhat(a, n - 1);
		if (a[n - 1] < min){
			return a[n - 1];
		}
		else{
			return min;
		}
	}
}
//==============================================================
int DemSoDuongTrongMang(int *a, int n){
	if (n == 0){
		return 0;
	}
	else{
		if (a[n - 1] > 0)
			return 1 + DemSoDuongTrongMang(a, n - 1);
		else
			return DemSoDuongTrongMang(a, n - 1);
	}
}
//==============================================================
int TinhTongSoLe(int *a, int n){
	if (n == 1){
		return a[0];
	}
	else{
		int x = TinhTongSoLe(a, n - 1);
		if (a[n - 1] % 2 != 0){
			return x + a[n - 1];
		}
		else{
			return x;
		}
	}
}
//==============================================================
int TimPhanTuLonNhat(int *a, int n){
	if (n == 1){
		return a[0];
	}
	else{
		int max = TimPhanTuLonNhat(a, n - 1);
		if (a[n - 1] > max){
			return a[n - 1];
		}
		else{
			return max;
		}
	}
}
//==============================================================
int bai7(int n){
	if (n == 0 || n == 1){
		return 2;
	}
	return 2 * bai7(n - 1) * bai7(n - 2);
}
//==============================================================
int bai8(int n){
	if (n == 0)
		return 1;
	else if (n == 1)
		return 2;
	else
		return 2 * bai8(n - 1) + 4 * bai8(n - 2);
}
//==============================================================
int bai9(int n){
	if (n == 0)
		return 4;
	else if (n == 1)
		return 2;
	else
		return bai9(n - 1) + 3 * bai9(n - 2);
}
//==============================================================
int bai10(int n){
	if (n == 0)
		return 1;
	else
		return 2 * bai10(n / 2) + n;
}
//==============================================================
int bai11(int n){
	if (n == 0)
		return 1;
	else if (n == 1)
		return 1;
	else
		return bai11(n - 1) + bai11(n - 2);
}
//==============================================================
int bai12(int n){
	if (n == 0)
		return 4;
	else
		return 2 * n * bai12(n - 1);
}
//==============================================================
int GiaiThua(int n){
	if (n == 1)
		return 1;
	return n * GiaiThua(n - 1);
}
//==============================================================
float bai13(int n){
	if (n <= 0)
		return 0;
	return (n * GiaiThua(n + 1) / ((float)(n + 1) + sqrt(n + 2))) + bai13(n - 1);
}
//==============================================================
float bai14(int n){
	if (n <= 0)
		return 0;
	return ((n + sqrt(n + n + 1)) / ((float)(n + 1) + sqrt(GiaiThua(n + 2)))) + bai14(n - 1);
}
//==============================================================

void NhapSoDuong(int &n){
    try{
        printf("Nhap so duong n: ");
        scanf("%d", &n);
        if(n <= 0){
            throw 101;
        }
    }
    catch(int errCode){
        if(errCode == 101){
            printf("\nVui long nhap n > 0\n");
        }
        NhapSoDuong(n);
    }
}
// ======================= BÀI TẬP FILE THẦY THỌ ======================= 
// 8. Nhập n > 0. Tính S(n) = 1^2-2^2+3^2-4^2 + … +(-1)^n-1n^2.
int Bai8(int n){
    if(n <= 0){
        return 0;
    }
    return (pow(-1, n - 1) * pow(n, 2)) + Bai8(n - 1);
}
int Bai8_Khu(int n){
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += pow(-1, n - i) * pow(i, 2);
    }
    return sum;
}
// 16. Nhập n > 0. Tính S(n) = 1+1 2+1 2 3+ … +1 2 3 … n
int tichN(int n){
    if(n <= 0){
        return 1;
    }
    return n * tichN(n - 1);
}
int bai16(int n){
    if(n <= 0){
        return 0;
    }
    return tichN(n) + bai16(n - 1);
}
int tichN_Khu(int n){
    int sum = 1;
    for(int i = 1; i <= n; i++){
        sum *= i;
    }
    return sum;
}
int bai16_Khu(int n){
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += tichN_Khu(i);
    }
    return sum;
}
// 20. Nhập x, n ≥ 0. Tính S(x, n) = x+x^3+x^5+ … +x^2n+1
int bai20(int x, int n){
    if(n < 0){
        return 0;
    }
    return pow(x, 2 * n + 1) + bai20(x, n - 1);
}
int bai20_Khu(int x, int n){
    int sum = 0;
    for(int i = 0; i <= n; i++){
        sum += pow(x, 2 * i + 1);
    }
    return sum;
}

int giaiThua(int n){
    if(n == 0){
        return 1;
    }
    return n * giaiThua(n - 1);
}
float bai21(int x, int n){
    if(n < 0){
        return 0;
    }
    return pow(1, n - 1) * (pow(x, n) / (float)giaiThua(n)) + bai21(x, n - 1);
}
int giaiThua_Khu(int n){
    int sum = 1;
    for(int i = 1; i <= n; i++){
        sum *= i;
    }
    return sum;
}
float bai21_Khu(int x, int n){
    float sum = 0;
    for(int i = 0; i <= n; i++){
        sum += pow(1, i - 1) * (pow(x, i) / (float)giaiThua_Khu(i));
    }
    return sum;
}

float bai28(int n){
    if(n < 0){
        return 0;
    }
    return sqrt(n + bai28(n - 1));
}
float bai28_Khu(int n){
    float sum = 0;
    for(int i = 0; i <= n; i++){
        sum = sqrt(i + sum);
    }
    return sum;
}

float bai29(int i, int n){
    if(i == n){
        return sqrt(n);
    }
    return sqrt(i + bai29(i + 1, n));
}
float bai29_Khu(int n){
    float sum = 0;
    for (int i = n; i >= 1; i--) {
        sum = sqrt(i + sum);
    }
    return sum;
}

int DemSoLuongChuSo(int n){
    if(n == 0){
        return 0;
    }
    return 1 + DemSoLuongChuSo(n / 10);
}
int DemSoLuongChuSo_Khu(int n){
    int dem = 0;
    while(n != 0){
        dem++;
        n /= 10;
    }
    return dem;
}

int TinhTongChuSo(int n){
    if(n == 0){
        return 0;
    }
    return (n % 10) + TinhTongChuSo(n / 10);
}
int TinhTongChuSo_Khu(int n){
    int tong = 0;
    while (n != 0){
        tong += n % 10;
        n /= 10;
    }
    return tong;
}

int DemChuSoLe(int n){
    if(n == 0){
        return 0;
    }
    int x = n % 10;
    if(x % 2 != 0)
        return 1 + DemChuSoLe(n / 10);
    else
        return DemChuSoLe(n / 10);
}
int DemChuSoLe_Khu(int n){
    int dem = 0;
    while(n != 0){
        int x = n % 10;
        if(x % 2 != 0){
            dem++;
        }
        n /= 10;
    }
    return dem;
}

/*
Bài 10. Viết hàm tính số hạng thứ n của 2 dãy sau :
x0 = 1, y0 = 0, 
xn = xn-1 + yn-1 với mọi n>0
yn = 3xn-1 + 2yn-1 với mọi n>n
*/
int x(int n);
int y(int n);
int x(int n){
    if(n == 0)
        return 1;
    return x(n - 1) + y(n - 1);  
}
int y(int n){
    if(n == 0)
        return 0;
    return 3 * x(n - 1) + 2 * y(n - 1);
}

/*
Bài 11.
a) Dãy An được cho như sau : A1=1 ; An = n(A1+A2+ … + An-1). Viết hàm tính An theo đệ quy.
b) Cho dãy số xn được định nghĩa như sau :
x0 = 1 ; x1 = 2 ; xn = nx0 + (n-1)x1 + …+xn-1
Viết hàm đệ quy tính xn với 𝑛 ≥ 0
*/
int TinhXna(int n){
    if(n == 1){
        return 1;
    }
    else{
        int sum = 0;
        for(int i = 1; i < n; i++){
            sum += TinhXna(i); 
        }
        return n * sum;
    }
}
int TinhXnb(int n){
    if(n == 0){
        return 1;
    }
    else if(n == 1){
        return 2;
    }
    else{
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += (n - i) * TinhXnb(i);
        }
        return sum;
    }
}
/*
Bài 12. Dãy An được cho như sau :
a) A1=1
 A2n = n + An + 2
A2n+1 = n2 + An. An+1 + 1
b) A1=A2=1
A2n+3 = A2n+2 + 2A2n+1
*/

int TinhAna(int n){
    if(n == 1){
        return 1;
    }
    else{

    }
}

int fibo(int  n){
    if(n <= 2){
        return 1;
    }
    return fibo(n - 1) + fibo(n - 2);
}
void XuatFiboThuN(int n){
    for(int i = 1; i <= n; i++){
        printf("%4d", fibo(i));
    }
}
void XuatFibonacciTrongKhoang(int m, int n) {
    int i = 0;
    int f;
    while (true){
        f = fibo(i);
        if(f >= m && f <= n){
            printf("%3d", f);
        }
        i++;
    }
}
void XuatFiboMaxBeHonM(int m){
    int i = 0;
    int f = fibo(i);
    int temp = 0;
    while (f < m){
        temp = f;
        i++;
        f = fibo(i);
    }
    printf("\nFibo max be hon m la: %d", temp);
}

long long Fibonacci(int n) {
    if (n <= 1) {
        return n;
    } 
    else {
        long long a = 0, b = 1, c;
        for (int i = 2; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
}

int toHop(int k, int n){
    if(k == 0 || k == n){
        return 1;
    }
    return toHop(k - 1, n -1) + toHop(k, n - 1);
}

int UCLN(int a, int b){
    if(a == b){
        return a;
    }
    if(a > b){
        return UCLN(a - b, b);
    }
    else{
        return UCLN(a, b - a);
    }
}

int main(){
  //  int n = 0;
    //printf("%d\n", TinhAna(3));
    //printf("%d\n", y(3));
    printf("%d", UCLN(10, 20));
    return 0;
}