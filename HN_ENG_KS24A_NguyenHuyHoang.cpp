#include <stdio.h>

void nhapMang(int arr[], int *n) {
    printf("Nhap so phan tu: ");
    scanf("%d", n);
    for (int i = 0; i < *n; i++) {
        printf("Nhap gia tri cho phan tu arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
}
void inMang(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = %d, ", i, arr[i]);
    }
    printf("\n");
}

int laSoHoanHao(int n) {
    if (n <= 1) return 0;
    int tongUoc = 0;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) tongUoc += i;
    }
    return tongUoc == n;
}

int demSoHoanHao(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (laSoHoanHao(arr[i])) {
            count++;
        }
    }
    return count;
}

int timGiaTriNhoThu2(int arr[], int n) {
    if (n < 2) return -1;

    int min1 = 2147483647, min2 = 2147483647;
    for (int i = 0; i < n; i++) {
        if (arr[i] < min1) {
            min2 = min1;
            min1 = arr[i];
        } else if (arr[i] > min1 && arr[i] < min2) {
            min2 = arr[i];
        }
    }
    return (min2 == 2147483647) ? -1 : min2;
}

void themPhanTuDauTien(int arr[], int *n, int kichThuocToiDa) {
    if (*n >= kichThuocToiDa) {
        printf("Mang da day, khong the them phan tu!\n");
        return;
    }
    int value;
    printf("Nhap gia tri cua phan tu moi: ");
    scanf("%d", &value);

    for (int i = *n; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = value;
    (*n)++;
    printf("Da them phan tu %d vao vi tri dau tien cua mang.\n", value);
}

void menu() {
    int kichThuocToiDa;
    printf("Nhap kich thuoc toi da cua mang: ");
    scanf("%d", &kichThuocToiDa);

    int arr[kichThuocToiDa], n = 0, choice;
    do {
        printf("\nMENU:\n");
        printf("1. Nhap so phan tu va gia tri\n");
        printf("2. In ra gia tri cac phan tu\n");
        printf("3. So hoan hao trong mang\n");
        printf("4. Tim gia tri nho thu 2 trong mang\n");
        printf("5. Them mot phan tu vao vi tri dau tien trong mang\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang (0-5): ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            nhapMang(arr, &n);
            break;
        case 2:
            if (n > 0) {
                inMang(arr, n);
            } else {
                printf("Mang chua co phan tu nao.\n");
            }
            break;
        case 3:
            if (n > 0) {
                printf("So luong so hoan hao trong mang: %d\n", demSoHoanHao(arr, n));
            } else {
                printf("Mang chua co phan tu nao. Hay nhap mang truoc.\n");
            }
            break;
        case 4:
            if (n > 0) {
                int result = timGiaTriNhoThu2(arr, n);
                if (result != -1) {
                    printf("Gia tri nho thu 2 trong mang la: %d\n", result);
                } else {
                    printf("Khong co gia tri nho thu 2.\n");
                }
            } else {
                printf("Mang chua co phan tu nao. Hay nhap mang truoc!\n");
            }
            break;
        case 5:
            themPhanTuDauTien(arr, &n, kichThuocToiDa);
            break;
        case 0:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le!\n");
        }
    } while (choice != 0);
}

int main() {
    menu();
    return 0;
}


