#include <iostream>
using namespace std;

int nguyen_to(int n) {
    if (n < 2)
        return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}
int max_nguyen_to(int a[][100], int m, int n) {
    int max_nt = -1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (nguyen_to(a[i][j]) && a[i][j] > max_nt) {
                max_nt = a[i][j];
            }
        }
    }
    return max_nt;
}

void dong_co_nt(int a[][100], int m, int n) {
    cout << "Dong co so nguyen to: ";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (nguyen_to(a[i][j])) {
                cout << i << " ";
                break;
            }
        }
    }
    cout << endl;
}

void dong_toan_nt(int a[][100], int m, int n) {
    cout << "Dong chi chua so nguyen to: ";
    for (int i = 0; i < m; i++) {
        bool toan_nt = true;
        for (int j = 0; j < n; j++) {
            if (!nguyen_to(a[i][j])) {
                toan_nt = false;
                break;
            }
        }
        if (toan_nt) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    int m, n;
    int a[100][100];

    cout << "Nhap m, n: ";
    cin >> m >> n;

    cout << "Nhap ma tran:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    int max_nt = max_nguyen_to(a, m, n);
    if (max_nt == -1) {
        cout << "Khong co so nguyen to.\n";
    }
    else {
        cout << "So nguyen to lon nhat: " << max_nt << endl;
    }
    dong_co_nt(a, m, n);
    dong_toan_nt(a, m, n);

    return 0;
}