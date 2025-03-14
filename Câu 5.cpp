#include <iostream>
using namespace std;

int dong_max_tong(int a[][100], int m, int n) {
    int max_tong = 0, dong_max = 0;
    for (int i = 0; i < m; i++) {
        int tong = 0;
        for (int j = 0; j < n; j++) {
            tong += a[i][j];
        }
        if (tong > max_tong) {
            max_tong = tong;
            dong_max = i;
        }
    }
    return dong_max;
}

void sap_xep_dong(int a[][100], int m, int n) {
    int tong[100];
    for (int i = 0; i < m; i++) {
        tong[i] = 0;
        for (int j = 0; j < n; j++) {
            tong[i] += a[i][j];
        }
    }

    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < m - i - 1; j++) {
            if (tong[j] < tong[j + 1]) {
                swap(tong[j], tong[j + 1]);
                for (int k = 0; k < n; k++) {
                    swap(a[j][k], a[j + 1][k]);
                }
            }
        }
    }
}

void in_ma_tran(int a[][100], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int m, n, a[100][100];

    cout << "Nhap m, n: ";
    cin >> m >> n;

    cout << "Nhap ma tran:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    int dong_max = dong_max_tong(a, m, n);
    cout << "Dong co tong lon nhat: " << dong_max << endl;

    sap_xep_dong(a, m, n);
    cout << "Ma tran sau khi sap xep:\n";
    in_ma_tran(a, m, n);

    return 0;
}
