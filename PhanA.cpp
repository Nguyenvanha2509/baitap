#include <bits/stdc++.h>
using namespace std;

class SinhVien {
private:
    string maSV;     
    string hoTen;    
    string ngaySinh; 
    string gioiTinh;
    string lop;     
public:
    SinhVien() {}
    SinhVien(string ma, string ten, string ngay, string gioi, string lopHoc)
        : maSV(ma), hoTen(ten), ngaySinh(ngay), gioiTinh(gioi), lop(lopHoc) {}
    string getMaSV() const { return maSV; }
    string getHoTen() const { return hoTen; }
    
    // Toan tu nhap xuat du lieu cho SinhVien
    friend istream& operator>>(istream& is, SinhVien& sv) {
        cout << "Nhap ma SV: "; is >> sv.maSV;
        cout << "Nhap ho ten: "; is.ignore(); getline(is, sv.hoTen);
        cout << "Nhap ngay sinh: "; is >> sv.ngaySinh;
        cout << "Nhap gioi tinh: "; is >> sv.gioiTinh;
        cout << "Nhap lop: "; is >> sv.lop;
        return is;
    }
    
    // Xuat thong tin cua sinh vien ra man hinh
    friend ostream& operator<<(ostream& os, const SinhVien& sv) {
        os << "Ma SV: " << sv.maSV << ", Ho ten: " << sv.hoTen 
           << ", Ngay sinh: " << sv.ngaySinh << ", Gioi tinh: " 
           << sv.gioiTinh << ", Lop: " << sv.lop << endl;
        return os;
    }
    
    // So sanh hai sinh vien theo ten
    bool operator<(const SinhVien& other) const {
        return hoTen < other.hoTen;
    }
};

class DanhSachSinhVien {
private:
    vector<SinhVien> danhSach;
public:
    void themSinhVien() {
        SinhVien sv;
        char a;
        do {
            cout << "Nhap thong tin sinh vien:\n";
            cin >> sv;
            danhSach.push_back(sv);
            cout << "Nhap them sinh vien nua khong (c/k)? ";
            cin >> a;
        } while (a == 'c');
    }
    void hienThiDanhSach() const {
        cout << "\nDanh sach sinh vien:\n";
        if (danhSach.empty()) {
            cout << "Danh sach hien tai trong.\n";
        } else {
            for (const auto& sv : danhSach) {
                cout << sv;
            }
        }
    }
    void xoaSinhVien(const string& maSV) {
        auto it = remove_if(danhSach.begin(), danhSach.end(),
		[&maSV](const SinhVien& sv) { return sv.getMaSV() == maSV; });        
        if (it != danhSach.end()) {
            danhSach.erase(it, danhSach.end()); 
            cout << "Da xoa sinh vien co ma: " << maSV << endl;
        } else {
            cout << "Khong tim thay sinh vien co ma: " << maSV << endl;
        }
    }
    void suaThongTinSinhVien(const string& maSV) {
        bool found = false;
        for (auto& sv : danhSach) {
            if (sv.getMaSV() == maSV) {
                cout << "Nhap thong tin moi cho sinh vien:\n";
                cin >> sv;
                cout << "Da sua thong tin sinh vien co ma: " << maSV << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Khong tim thay sinh vien co ma: " << maSV << endl;
        }
    }
     void sapXepTheoHoTen() {
        sort(danhSach.begin(), danhSach.end());
        cout << "Da sap xep danh sach sinh vien theo ho ten.\n";
    }
    void timKiemSinhVien(const string& hoTen) const {
        bool found = false;
        cout << "\nKet qua tim kiem sinh vien co ten \"" << hoTen << "\":\n";
        for (const auto& sv : danhSach) {
            if (sv.getHoTen() == hoTen) {
                cout << sv;
                found = true;
            }
        }
        if (!found) {
            cout << "Khong tim thay sinh vien co ten \"" << hoTen << "\" trong danh sach.\n";
        }
    }
};

class App {
private:
    DanhSachSinhVien danhSach; 
public:
    void run() {
        int a;
        do {
            cout << "\nQuan Ly Sinh Vien\n";
            cout << "1. Them sinh vien\n";
            cout << "2. Hien thi danh sach sinh vien\n";
            cout << "3. Xoa sinh vien\n";
            cout << "4. Sua thong tin sinh vien\n";
            cout << "5. Sap xep danh sach theo ho ten\n";
            cout << "6. Tim kiem sinh vien theo ho ten\n";
            cout << "0. Thoat\n";
            cout << "Lua chon cua ban: ";
            cin >> a;

            // Xu ly cac lua chon menu
            switch (a) {
                case 1: {
                    danhSach.themSinhVien();
                    break;
                }
                case 2: {
                    danhSach.hienThiDanhSach();
                    break;
                }
                case 3: {
                    string maSV;
                    cout << "Nhap ma sinh vien can xoa: ";
                    cin >> maSV;
                    danhSach.xoaSinhVien(maSV);
                    break;
                }
                case 4: {
                    string maSV;
                    cout << "Nhap ma sinh vien can sua: ";
                    cin >> maSV;
                    danhSach.suaThongTinSinhVien(maSV);
                    break;
                }
                case 5: {
                    danhSach.sapXepTheoHoTen();
                    break;
                }
                case 6: {
                    string hoTen;
                    cout << "Nhap ho ten sinh vien can tim: ";
                    cin.ignore();
                    getline(cin, hoTen);
                    danhSach.timKiemSinhVien(hoTen);
                    break;
                }
                case 0: {
                    cout << "Thoat chuong trinh.\n";
                    break;
                }
                default:
                    cout << "Lua chon khong hop le! Vui long chon lai.\n";
            }
        } while (a != 0);  // Tiep tuc cho den khi chon thoat
    }
};

int main() {
    App app;
    app.run();
    return 0;
}



