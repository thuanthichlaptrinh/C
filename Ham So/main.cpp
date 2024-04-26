#include <bits/stdc++.h>

// Số nguyên tố
bool checkPrime(int n){
    if(n < 2){
        return false;
    }
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}
void LietKeNSoNguyenToDauTien(int n){
    int i = 2;
    int count = 0;
    while (count < n){
        if(checkPrime(i) == true){
            printf("%d ", i);
            count++;
        }
        i++;
    }   
}
bool KiemTraSNTCoAllChuSoLaSNT(int n){
    while(n != 0){
        int temp = n % 10;
        if(temp != 2 && temp != 3 && temp != 5 && temp != 7){
            return false;
        }
        n /= 10;
    }
    return true;
}

// cho số nguyên dương chẵn n > 2, liệt kê các cặp số nguyên số có tổng = n
void KiemTraCapSNTCoTongBangN(int n){ // VD: n = 6 -> 3 + 3 = 6
    for(int i = 2; i <= n / 2; i++){
        int x = n - i;
        if(checkPrime(i) && checkPrime(x)){
            printf("%d %d\n", i, x);
        }
    }
}

// Liệt kê Số T-Prime: VD = 100, ta có các ước 4, 9, 25, 49
// Số T-Prime là số có đúng 3 ước số nhỏ hơn bằng n (nghĩa là bình phương của 1 số nguyên tố)
void KiemTraSoTPrime(int n){
    for(int i = 1; i <= sqrt(n); i++){
        if(checkPrime(i)){
            printf("%d ", i * i);
        }
    }
}

// Phân tích thừa số nguyên tố
// VD: n = 84, 84 : 2 == 42, 42: 2 = 21
// 21 : 3 == 7 
void PhanTichThuaSNT(int n){
    for(int i = 2; i <= sqrt(n); i++){
        while(n % i == 0){
            printf("%d ", i);
            n /= i;
        }
    }
    if(n != 1){
        printf("%d ", n);
    }
}


bool KiemTraChuSoHangChuc(int n){ 
    n = abs(n);
    n /= 10;
    int hangChuc = n % 10;
    if(hangChuc % 2 == 0)
        return true;

    return false;
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
bool KiemTraSoTanCungLa5(int n){
    n = abs(n);
    int x = n % 10;
    if(x == 5){
        return true;
    }
    return false;
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
int main(){
   printf("%d", KiemTraChuSoDau(2285));
    system("pause");
    return 0;
}