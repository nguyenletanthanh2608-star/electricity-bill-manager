#include <stdio.h>

// 1. Hàm in bảng giá điện hiện hành
void inBangGia() {
    printf("\n--- BANG GIA DIEN SINH HOAT (CHUA VAT) ---\n");
    printf("Bac 1 (0 - 50 kWh)     : 1.893 đ/kWh\n");
    printf("Bac 2 (51 - 100 kWh)   : 1.956 đ/kWh\n");
    printf("Bac 3 (101 - 200 kWh)  : 2.271 đ/kWh\n");
    printf("Bac 4 (201 - 300 kWh)  : 2.860 đ/kWh\n");
    printf("Bac 5 (301 - 400 kWh)  : 3.197 đ/kWh\n");
    printf("Bac 6 (Tu 401 kWh)     : 3.302 đ/kWh\n");
    printf("------------------------------------------\n");
}

// 2. Hàm tính tiền điện theo bậc lũy tiến (Trả về số tiền)
double tinhTienDien(float kwh) {
    double tien = 0;

    if (kwh <= 50) {
        tien = kwh * 1893;
    } else if (kwh <= 100) {
        tien = 50 * 1893 + (kwh - 50) * 1956;
    } else if (kwh <= 200) {
        tien = 50 * 1893 + 50 * 1956 + (kwh - 100) * 2271;
    } else if (kwh <= 300) {
        tien = 50 * 1893 + 50 * 1956 + 100 * 2271 + (kwh - 200) * 2860;
    } else if (kwh <= 400) {
        tien = 50 * 1893 + 50 * 1956 + 100 * 2271 + 100 * 2860 + (kwh - 300) * 3197;
    } else {
        tien = 50 * 1893 + 50 * 1956 + 100 * 2271 + 100 * 2860 + 100 * 3197 + (kwh - 400) * 3302;
    }

    return tien;
}

// 3. Hàm in hóa đơn chi tiết
void inHoaDon(float kwh) {
    double tienGốc = tinhTienDien(kwh);
    double thueVAT = tienGốc * 0.08; // Thuế VAT 8%
    double tongTien = tienGốc + thueVAT;

    printf("\n========= HOA DON TIEN DIEN =========\n");
    printf("So kWh tieu thu   : %.1f kWh\n", kwh);
    printf("Tien dien truoc thue: %.0f VNĐ\n", tienGốc);
    printf("Thue VAT (8%%)     : %.0f VNĐ\n", thueVAT);
    printf("-------------------------------------\n");
    printf("TONG TIEN THANH TOAN: %.0f VNĐ\n", tongTien);
    printf("=====================================\n");
}

int main() {
    int luaChon;
    float kwh;

    do {
        // Menu chọn chức năng
        printf("\n===== CHUONG TRINH TINH TIEN DIEN =====\n");
        printf("1. Tinh tien dien gia dinh\n");
        printf("2. Xem bang gia dien hien hanh\n");
        printf("0. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                printf("\nNhap so kWh tieu thu: ");
                scanf("%f", &kwh);
                if (kwh < 0) {
                    printf(">> Loi: So kWh khong the la so am!\n");
                } else {
                    inHoaDon(kwh);
                }
                break;
            case 2:
                inBangGia();
                break;
            case 0:
                printf("Da thoat chuong trinh.\n");
                break;
            default:
                printf(">> Lua chon khong hop le, vui long chon lai!\n");
        }
    } while (luaChon != 0); // Vòng lặp giữ chương trình chạy liên tục tới khi bấm 0

    return 0;
}
 

