#include <stdio.h>
#define MAX_SIZE 30

int main() {
    int passengers[MAX_SIZE] = {32, 18, 45, 27, 50};
    int n = 5;
    int choice, pos, value, target;
    int i, count;

    do {
        printf("====================\n");
        printf("CHUONG TRINH QUAN LY HANH KHACH CITYBUS\n");
        printf("====================\n");
        printf("1. Them so hanh khach\n");
        printf("2. Sua so hanh khach\n");
        printf("3. Xoa so hanh khach\n");
        printf("4. Tim kiem so hanh khach\n");
        printf("0. Thoat chuong trinh\n");
        printf("====================\n");
        printf("Vui long nhap lua chon cua ban (0-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (n == MAX_SIZE) {
                    printf("Mang da day, khong the them!\n");
                    break;
                }
                printf("Nhap value: ");
                scanf("%d", &value);
                printf("Nhap pos (1-%d): ", n + 1);
                scanf("%d", &pos);
                if (pos < 1 || pos > n + 1) {
                    printf("Vi tri chen khong hop le!\n");
                    break;
                }
                for (i = n; i >= pos; i--) {
                    passengers[i] = passengers[i - 1];
                }
                passengers[pos - 1] = value;
                n++;
                printf("Mang: ");
                for (i = 0; i < n; i++) {
                    printf("%d ", passengers[i]);
                }
                printf("\n");
                break;

            case 2:
                printf("Nhap pos: ");
                scanf("%d", &pos);
                printf("Nhap gia tri moi: ");
                scanf("%d", &value);
                if (pos < 1 || pos > n) {
                    printf("Vi tri sua khong hop le!\n");
                    break;
                }
                if (value < 0) {
                    printf("So hanh khach khong hop le!\n");
                    break;
                }
                passengers[pos - 1] = value;
                printf("Mang: ");
                for (i = 0; i < n; i++) {
                    printf("%d ", passengers[i]);
                }
                printf("\n");
                break;

            case 3:
                if (n == 0) {
                    printf("Mang rong!\n");
                    break;
                }
                printf("Nhap pos: ");
                scanf("%d", &pos);
                if (pos < 1 || pos > n) {
                    printf("Vi tri xoa khong hop le!\n");
                    break;
                }
                for (i = pos - 1; i < n - 1; i++) {
                    passengers[i] = passengers[i + 1];
                }
                n--;
                printf("Mang: ");
                for (i = 0; i < n; i++) {
                    printf("%d ", passengers[i]);
                }
                printf("\n");
                break;

            case 4:
                printf("Nhap gia tri can tim: ");
                scanf("%d", &target);
                count = 0;
                for (i = 0; i < n; i++) {
                    if (passengers[i] == target) {
                        printf("Vi tri: %d\n", i + 1);
                        count++;
                    }
                }
                if (count == 0) {
                    printf("Khong tim thay gia tri trong mang!\n");
                } else {
                    printf("So lan xuat hien la: %d\n", count);
                }
                break;

            case 0:
                printf("Ban da thoat chuong trinh thanh cong!\n");
                break;

            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choice != 0);

    return 0;
}
