#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>1

// Xây dựng hàm tính độ dài của chuỗi strlen()
int STRLEN(char *s){
    int i = 0;
    while(true){ // lặp vô tận đến khi gặp kí tự '\0' thì dừng
        if(s[i] == '\0'){ 
            return i;
        }
        i++;
    }
}

// Xây dựng hàm sao chép chuỗi 
// strcpy()
void STRCPY(char *s2, char *s1){
    for(int i = 0; i < strlen(s1); i++){
        s2[i] = s1[i]; // bỏ từng kí tự của chuỗi s1 sang cho chuỗi s2
    }
    s2[strlen(s1)] = '\0'; // vị trí cuối cùng của s2 là độ dài của chuỗi s1
}
/* char *s = strdup() 
- Hàm strdup() sẽ yêu cầu bộ nhớ máy tính cấp phát ra vùng nhớ 
và con trỏ s sẽ trỏ đến vùng nhớ đó để quản lí
*/
char *STRDUP(char *s1){
    char *s2 = (char*)malloc(strlen(s1 + 1));  // cấp phát vùng nhớ cho con trỏ s
    for(int i = 0; i < strlen(s1); i++){ // duyệt từ đầu đến cuối chuỗi s1
        s2[i] = s1[i]; // đổ tất cả các phần tử của chuỗi s1 vào chuỗi s2
    }
    s2[strlen(s1)] = '\0'; // cập nhật kí tự cuối cùng là kí tự '\0'
    return s2; // trả về chuỗi s2
    free(s2); // giải phóng vùng nhớ
}

// chuyển tất cả các kí tự in hoa thành kí tự in thường 
// a - z: 65 - 90
// A - Z: 97 - 122
void STRLWR(char *s){
    for(int i = 0; i < strlen(s); i++){
        if(s[i] >= 65 && s[i] <= 90){
            s[i] += 32; // chuyển kí tự hoa thành kí tự thường
        }
    }
}
// chuyển tất cả các kí tự in thường thành kí tự Hoa 
void STRUPR(char *s){
    for(int i = 0; i < strlen(s); i++){
        if(s[i] >= 97 && s[i] <= 122){
            s[i] -= 32; // chuyển kí tự hoa thành kí tự thường
        }
    }
}

// Xây dựng hàm đảo ngược chuỗi
void STRREV(char *s){
    int len = strlen(s);
    for(int i = 0; i < len / 2; i++){
        int temp = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = temp;
    }
}

// Xây dựng hàm so sánh 2 chuỗi 
void STRCMP(char *s){
    
}

// Tách từ trong xâu
void TachTuTrongXau(char s[]){
    char *token = strtok(s, " "); // s: là xâu muốn tách và tách theo dấu cách
    while(token != NULL){
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }
}

// Xóa 1 kí tự tại vị trí bất kỳ
void XoaKiTuBatKy(char *s, int vt){
    for(int i = vt; i < strlen(s); i++){
        s[i] = s[i + 1];
    }
    s[strlen(s)] = '\0';
    // c2:
    //  for(int i = vt + 1; i < strlen(s); i++){
    //     s[i - 1] = s[i];
    // }
    // s[strlen(s) - 1] = '\0';
}

// Xóa các kí tự trùng trong xâu
void XoaKiTuTrung(char s[]){
    for(int i = 0; i < strlen(s); i++){
        bool KT = false; // giả sử s[i] là ptu khong trùng
        for(int j = i + 1; j < strlen(s); j++){
            if(s[i] == s[j]){
                KT = true;
                XoaKiTuBatKy(s, j);
                j--; // tránh tình trạng bỏ sót phần tử trùng
            }
        }
        // if(KT == true){
        //     XoaKiTuBatKy(s, i);
        //     i--;
        // }
    }
}

// Thêm 1 kí tự vào vị trí bất ký
void ThemKiTuBatKy(char *s, int vt, char x){
    int len = strlen(s);
    for(int i = len; i > vt; i--){
        s[i] = s[i - 1];
    }
    s[vt] = x;
    s[++len] = '\0';

    // c2:
    // for(int i = len - 1; i >= vt; i--){
    //     s[i + 1] = s[i];
    // }
    // s[vt] = x;
    // s[++len] = '\0';
}

// Xóa khoảng trắng tại vị trí đầu chuỗi
// ý tưởng: dùng vòng lặp while lặp vô tận nếu kí tự đầu là kí tự khoảng trắng thì xóa, xóa đến khi ko gặp kí tự khoảng trắng nữa thì dừng
void XoaDau(char *s){
    while(true){
        if(s[0] == ' '){
            XoaKiTuBatKy(s, 0);
        }
        else {
            break;
        }
    }
}

// Xóa khoảng trắng tại vị trí cuối chuỗi
// ý tưởng: lặp vô tận nếu kí tự cuối chuỗi bằng khoảng trắng => xóa, xóa đến khi hết khoảng trắng thì dừng
void XoaCuoi(char *s){
    int len = strlen(s);
    while(true){ // lặp vô tận cho đến khi khác kí tự khoảng trắng thì dừng
        if(s[len - 1] == ' '){ // nếu kí tự cuối là khoảng trắng => xóa
            XoaKiTuBatKy(s, (len - 1));
        }
        else {
            break;
        }
    }
}

// Xóa tất cả khoảng trắng thừa trong xâu 
void XoakhoangTrang(char *s){
    for(int i = 0; i < strlen(s); i++){
		if(s[i] == ' ' && s[i + 1] == ' '){ // xóa giữa
			XoaKiTuBatKy(s, i);
			i--;
		}
    }
    if(s[0]== ' '){ // xóa đầu
		XoaKiTuBatKy(s, 0);
    }
    if(s[strlen(s) - 1] == ' '){ // xóa cuối
		XoaKiTuBatKy(s, strlen(s) - 1);
    }
}

// Xóa tất cả khoảng trắng trong xâu
void XoaTatCaKhoangTrang(char s[]){
    for(int i = 0; i < strlen(s); i++){
        if(s[i] == 32){
            XoaKiTuBatKy(s, i);
            i--;
        }
    }
}

void ChuanHoaChuoi(char *s){
    XoaDau(s);
    XoaCuoi(s);
}
// đếm số từ trong chuỗi
int DemTu(char s[]){
    int count = 0;
    int n = strlen(s);
    if(s[0] != ' '){
        count++;
    }
    for(int i = 0; i < n - 1; i++){
        if(s[i] == ' ' && s[i + 1] != ' '){
            count++;
        }
    }
    return count;
}

// Thuật toán tìm xâu con của chuỗi - Brute force


// Kiểm tra xâu pangram
int DemSoKiTu(char s[]){
    int count[26] = {0}; // tạo mảng count và gán tất cả phần tử trong mảng = 0
    for(int i = 0; i < strlen(s); i++){
        count[s[i] - 'a'] = 1;
    }
    
    for(int i = 0; i < 26; i++){
        if(count[i] == 0){
            return 0;
        }
    }
    return 1; // tất cả kí tự từ a -> z xuất hiện
}

// Sắp xếp từ trong xâu theo thứ tự từ điển

// In họ, đệm, tên từ chuỗi họ tên
// void CatChuoi(char *s) {
//     char *Ho = strtok(s, " ");
//     char *TenDem = strtok(NULL, " ");
//     char *Ten = strtok(NULL, " ");

//     printf("Ho: %s\n", Ho);
//     printf("Ten dem: %s\n", TenDem);
//     printf("Ten: %s\n", Ten);
// }
void CatChuoi(char *s, char *ten){
    int i;
    for(i = strlen(s) - 1; i >= 0; i--){
        if(s[i] == ' ' && s[i + 1] != ' '){
            break;
        }
    }
    ten = s + i + 1; // s + i + 1: là con trỏ trỏ đến vị trí sau dấu cách cuối cùng trong chuỗi s
    s[i] = '\0';
    printf("Ho lot: %s\n", s);
    printf("Ten: %s\n", ten);
}
void CatChuoi(char *s) {
    char ten[10]; // Đặt kích thước tối đa cho phần tên
    char *space = strrchr(s, ' '); // Tìm vị trí của phần tên bằng hàm strrchr
  
    if (space != NULL) {
        strcpy(ten, space + 1); // Sao chép phần tên vào mảng firstName
        printf("Ten: %s\n", ten);
    }
}

int main(){
    char s[] = "Nguyen Van Teo";
    CatChuoi(s);

    getch();
    return 0;
}   