for (int i = 0; i < n - 1; i++){
            for (int k = 0; k < n - i - 1; k++){
                if(a[k][j] > a[k + 1][j]){
                    swap(a[k][j], a[k + 1][j]);
                }
            }
        }