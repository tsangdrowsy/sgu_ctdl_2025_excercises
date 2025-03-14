#include <iostream>
using namespace std;

int sap_xep_chan_le(int a[], int n) {
    int chan[100], le[100], c = 0, l = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] != 0) {
            if (a[i] % 2 == 0) chan[c++] = a[i];
            else le[l++] = a[i];
        }
    }

    for (int i = 0; i < c - 1; i++) {
        for (int j = i + 1; j < c; j++) {
            if (chan[i] > chan[j]) swap(chan[i], chan[j]);
        }
    }

    for (int i = 0; i < l - 1; i++) {
        for (int j = i + 1; j < l; j++) {
            if (le[i] < le[j]) swap(le[i], le[j]);
        }
    }

    c = 0, l = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != 0) {
            if (a[i] % 2 == 0) a[i] = chan[c++];
            else a[i] = le[l++];
        }
    }

    return 1;
}

int nhap_mang(int a[], int& n) {
    cout << "Nhap n: ";
    cin >> n;
    cout << "Nhap mang: ";
    for (int i = 0; i < n; i++) cin >> a[i];
    return 1;
}

int xuat_mang(int a[], int n) {
    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
    return 1;
}

int main() {
    int n, a[100];

    nhap_mang(a, n);
    sap_xep_chan_le(a, n);
    xuat_mang(a, n);

    return 0;
}

