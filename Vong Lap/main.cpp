#include <bits/stdc++.h>

// Bài 38: Tính S(n) = 1^4 + s^4 + ... + n^4
int S38(int n){
    int s = 0;
    for(int i = 1; i <= n; i++){
        s += pow(i, 4);
    }
    return s;
}
// int S38(int n){
//     int s = 0;
//     int i = 1;
//     while(i <= n){
//         s += pow(i , 4);
//         i++;
//     }
//     return s;
// }

// Bài 39: S(n) = (1 + 1/1^2).(1 + 1/2^2).(1 + 1/n^2)
float S39(int n){
    float s = 1;
    for(int i = 1; i <= n; i++){
        s *= (1 + 1.0 / pow(i, 2));
    }
    return s;
} 

// Bài 41: S(n) = 1.2.3 + 2.3.4 + n(n+1)(n+2)
int S41(int n){
    int s = 0;
    for(int i = 1; i <= n; i++){
        s += i * (i + 1) * (i + 2);
    }
    return s;
}

// Bài 42: 1/1.2.3 + ... + 1/n(n+1)(n+1)
float S42(int n){
    float s = 0;
    for(int i = 1; i <= n; i++){
        s += 1.0 / (i * (i + 1) * (i + 2));
    }
    return s;
}

// Bài 20. Liệt kê tất cả ước số của số nguyên dương n
void LietKeUocSo(int n){
    for(int i = 1; i <= n; i++){
        if(n % i == 0){
            printf("%d ", i);
        }
    }
}

// 21. Tính tổng tất cả “ước số” của số nguyên dương n.
int TinhTongUocSo(int n){
    int tong = 0;
    for(int i = 1; i <= n; i++){
        if(n % i == 0){
            tong += i;
        }
    }
    return tong;
}
// 23. Đếm số lượng “ước số” của số nguyên dương n.
int DemSoLuongUocSo(int n){
    int count = 0;
    for(int i = 1; i <= n; i++){
        if(n % i == 0){
            count++;
        }
    }
    return count;
}
// 24. Liệt kê tất cả “ước số lẻ” của số nguyên dương n.
void LietKeUocSoLe(int n){
    for(int i = 1; i <= n; i++){
        if(n % i == 0 && i % 2 != 0){
            printf("%d ", i);
        }
    }
}
// 25. Tính tổng tất cả “ước số chẵn” của số nguyên dương n.
int TinhTongUocSoChan(int n){
    int tong = 0;
    for(int i = 1; i <= n; i++){
        if(n % i == 0 && i % 2 == 0){
            tong += i;
        }
    }
    return tong;
}

// 29. Tìm ước số lẻ lớn nhất của số nguyên dương n. Ví dụ n = 100 ước lẻ lớn nhất của 100 là 25.
int TimUocSoLeLonNhat(int n){
    int max = -1;
    for(int i = 1; i <= n; i++){
        if(n % i == 0 && i % 2 != 0){
            max = (i > max) ? i : max;
        }
    }
    return max;
}

// 30. Cho số nguyên dương n. Kiểm tra số dương n có phải là số hoàn thiện hay không?
bool KiemTraSoHoanThien(int n){
    int s = 0;
    for(int i = 1; i < n; i++){
        if(n % i == 0){
            s += i;
        }
    }
    if(s == n)
        return true;
    return false;
}

// 31. Cho số nguyên dương n. Kiểm tra số nguyên dương n có phải là số nguyên tố hay không? 
bool KiemTraSoNguyenTo(int n){
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

// 32. Cho số nguyên dương n. Kiểm tra số nguyên dương n có phải là số chính phương hay không?
bool KiemTraSoChinhPhuong(int n){
    if(n < 1){
        return false;
    }
    int i = 1;
    while(i * i <= n){
        if(i * i == n){
            return true;
        }
        i++;
    }
    return false;
}

// Bài 42: Hãy tìm ɡiá trị nɡuyên dươnɡ k lớn nhất sɑo cho S(k) < n. Tronɡ đó chuỗi k được định nɡhĩɑ như sɑu: S(k) = 1 + 2 + 3 + … + k
int S(int n){
    int i = 0, sum = 0;
    while(sum + 1 < n){
        i++;
        sum += i;
    }
    return sum;
}
// Bài 43: Hãy đếm số lượnɡ chữ số củɑ số nɡuyên dươnɡ n
void DemSoLuongChuSo(int n){
    int temp = n;
    int dem = 0;
    while(temp != 0){
        dem++;
        temp /= 10;
    }
    printf("So luong chu so cua %d la: %d\n", n, dem);
}

// Bài 44: Hãy tính tổnɡ các chữ số củɑ số nɡuyên dươnɡ n
// Bài 45: Hãy tính tích các chữ số củɑ số nɡuyên dươnɡ n
// Bài 46: Hãy đếm số lượnɡ chữ số lẻ củɑ số nɡuyên dươnɡ n
// Bài 47: Hãy tính tổnɡ các chữ số chẵn củɑ số nɡuyên dươnɡ n
// Bài 48: Hãy tính tích các chữ số lẻ củɑ số nɡuyên dươnɡ n
// Bài 49: Cho số nɡuyên dươnɡ n. Hãy tìm chữ số đầu tiên củɑ n
// Bài 50: Hãy tìm số đảo nɡược củɑ số nɡuyên dươnɡ n
// Bài 51: Tìm chữ số lớn nhất củɑ số nɡuyên dươnɡ n
// Bài 52: Tìm chữ số nhỏ nhất củɑ số nɡuyên dươnɡ n

int main(){
    DemSoLuongChuSo(-54321);
    //std::cout << DemSoLuongChuSo(0) << std::endl;

    system("pause");
    return 0;
}