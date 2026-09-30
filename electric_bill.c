#include <stdio.h>

// Hàm in bảng giá điện hiện hành
void inbanggia() {
    printf("\n--- BANG GIA DIEN SINH HOAT (CHUA VAT) ---\n");
    printf("Bac 1 (0 - 50 kWh)     : 1.984 đ/kWh\n");
    printf("Bac 2 (51 - 100 kWh)   : 2.050 đ/kWh\n");
    printf("Bac 3 (101 - 200 kWh)  : 2.380 đ/kWh\n");
    printf("Bac 4 (201 - 300 kWh)  : 2.998 đ/kWh\n");
    printf("Bac 5 (301 - 400 kWh)  : 3.350 đ/kWh\n");
    printf("Bac 6 (Tu 401 kWh)     : 3.460 đ/kWh\n");
    printf("------------------------------------------\n");
}

// Hàm tính tiền điện theo bậc lũy tiến 
double tinhtiendien(float kwh) {
    double tien = 0;

    if (kwh <= 50) {
        tien = kwh * 1984;
    } else if (kwh <= 100) {
        tien = 50 * 1984 + (kwh - 50) * 2050;
    } else if (kwh <= 200) {
        tien = 50 * 1984 + 50 * 2050 + (kwh - 100) * 2380;
    } else if (kwh <= 300) {
        tien = 50 * 1984 + 50 * 2050 + 100 * 2380 + (kwh - 200) * 2998;
    } else if (kwh <= 400) {
        tien = 50 * 1984 + 50 * 2050 + 100 * 2380 + 100 * 2998 + (kwh - 300) * 3350;
    } else {
        tien = 50 * 1984 + 50 * 2050 + 100 * 2380 + 100 * 2998 + 100 * 3350 + (kwh - 400) * 3460;
    }

    return tien;
}

//  Hàm in hóa đơn chi tiết
void inhoadon(float kwh) {
    double tiengoc = tinhtiendien(kwh);
    double thueVAT = tiengoc * 0.08; 
    double tongtien = tiengoc + thueVAT;

    printf("\n========= HOA DON TIEN DIEN =========\n");
    printf("So kWh tieu thu   : %.1f kWh\n", kwh);
    printf("Tien dien truoc thue: %.0f VNĐ\n", tiengoc);
    printf("Thue VAT (8%%)     : %.0f VNĐ\n", thueVAT);
    printf("-------------------------------------\n");
    printf("TONG TIEN THANH TOAN: %.0f VNĐ\n", tongtien);
    printf("=====================================\n");
}

int main() {
    int luachon;
    float kwh;

    do {
        // Menu chọn chức năng
        printf("\n===== CHUONG TRINH TINH TIEN DIEN =====\n");
        printf("1. Tinh tien dien gia dinh\n");
        printf("2. Xem bang gia dien hien hanh\n");
        printf("0. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luachon);

        switch (luachon) {
            case 1:
                printf("\nNhap so kWh tieu thu: ");
                scanf("%f", &kwh);
                if (kwh < 0) {
                    printf(">> Loi: So kWh khong the la so am!\n");
                } else {
                    inhoadon(kwh);
                }
                break;
            case 2:
                inbanggia();
                break;
            case 0:
                printf("Da thoat chuong trinh.\n");
                break;
            default:
                printf(">> Lua chon khong hop le, vui long chon lai!\n");
        }
    } while (luachon != 0); 

    return 0;
}
 

