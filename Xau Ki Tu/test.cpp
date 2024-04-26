#include <bits/stdc++.h>

void TaoMang(int *&a, int &n){
    printf("Nhap so luong phan tu: "); scanf("%d", &n);
	a = new int[n];
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++) {
		int temp;
		temp = rand() % 101 - 50;
        do{
		    temp = rand() % 101 - 50;
        }while(temp % 2 != 0);
		a[i] = temp;
	}
}
void XuatMang(int *a, int n){
    for(int i = 0; i < n; i++){
        printf("%4d", a[i]);
    }
}


int main(){
    int *a = NULL;
    int n = 0;
    TaoMang(a, n);
    XuatMang(a, n);

    delete[] a;
    return 0;
}