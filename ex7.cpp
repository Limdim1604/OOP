#include <bits/stdc++.h>
using namespace std;

// Hàm kiểm tra ký tự đặc biệt
bool hasSpecialChar(const string &str) {
    for (char c : str) {
        if (!isalnum(c))
            return true;
    }
    return false;
}

// Hàm kiểm tra chuỗi chỉ chứa chữ cái và khoảng trắng (không chứa số hoặc ký tự đặc biệt)
bool isAlphabetic(const string &str) {
    for (char c : str) {
        if (!isalpha(c) && !isspace(c))
            return false;
    }
    return true;
}

// Hàm kiểm tra ngày hợp lệ
bool isValidDate(int day, int month, int year) {
    // Kiểm tra năm
    if (year < 1)
        return false;

    // Kiểm tra tháng
    if (month < 1 || month > 12)
        return false;

    // Số ngày trong tháng
    int daysInMonth;

    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            daysInMonth = 31;
            break;
        case 4: case 6: case 9: case 11:
            daysInMonth = 30;
            break;
        case 2:
            // Kiểm tra năm nhuận
            if ((year % 400 == 0) || (year % 100 != 0 && year % 4 == 0))
                daysInMonth = 29;
            else
                daysInMonth = 28;
            break;
        default:
            return false;
    }

    if (day < 1 || day > daysInMonth)
        return false;

    return true;
}

// Hàm kiểm tra giờ hợp lệ
bool isValidTime(int hour, int minute) {
    if (hour < 0 || hour > 23)
        return false;
    if (minute < 0 || minute > 59)
        return false;
    return true;
}

class Flight {
private:
    string flightCode; // Mã chuyến bay
    int day, month, year; // Ngày bay
    int hour, minute; // Giờ bay
    string departure; // Nơi đi
    string destination; // Nơi đến

public:
    // Hàm nhập dữ liệu cho chuyến bay
    void input() {
        cin.ignore();
        // Nhập mã chuyến bay
        do {
            cout << "Nhap ma chuyen bay (toi da 5 ky tu, khong khoang trang hoac ky tu dac biet): ";
            getline(cin, flightCode);
            if (flightCode.length() > 5 || flightCode.empty() || hasSpecialChar(flightCode) || flightCode.find(' ') != string::npos) {
                cout << "Ma chuyen bay khong hop le. Vui long nhap lai.\n";
            } else {
                break;
            }
        } while (true);

        // Nhập ngày bay
        do {
            cout << "Nhap ngay bay (dd mm yyyy): ";
            cin >> day >> month >> year;
            if (!isValidDate(day, month, year)) {
                cout << "Ngay bay khong hop le. Vui long nhap lai.\n";
            } else {
                break;
            }
        } while (true);

        // Nhập giờ bay
        do {
            cout << "Nhap gio bay (hh mm): ";
            cin >> hour >> minute;
            if (!isValidTime(hour, minute)) {
                cout << "Gio bay khong hop le. Vui long nhap lai.\n";
            } else {
                break;
            }
        } while (true);

        cin.ignore();
        // Nhập nơi đi
        do {
            cout << "Nhap noi di (toi da 20 ky tu, khong chua so hoac ky tu dac biet): ";
            getline(cin, departure);
            if (departure.length() > 20 || departure.empty() || !isAlphabetic(departure)) {
                cout << "Noi di khong hop le. Vui long nhap lai.\n";
            } else {
                break;
            }
        } while (true);

        // Nhập nơi đến
        do {
            cout << "Nhap noi den (toi da 20 ky tu, khong chua so hoac ky tu dac biet): ";
            getline(cin, destination);
            if (destination.length() > 20 || destination.empty() || !isAlphabetic(destination)) {
                cout << "Noi den khong hop le. Vui long nhap lai.\n";
            } else {
                break;
            }
        } while (true);
    }

    // Hàm xuất dữ liệu của chuyến bay
    void display() const {
        cout << "Ma chuyen bay: " << flightCode << endl;
        cout << "Ngay bay: " << (day < 10 ? "0" : "") << day << "/"
             << (month < 10 ? "0" : "") << month << "/" << year << endl;
        cout << "Gio bay: " << (hour < 10 ? "0" : "") << hour << ":"
             << (minute < 10 ? "0" : "") << minute << endl;
        cout << "Noi di: " << departure << endl;
        cout << "Noi den: " << destination << endl;
    }

    // Các phương thức getter
    string getFlightCode() const { return flightCode; }
    string getDeparture() const { return departure; }
    string getDestination() const { return destination; }
    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }
    int getHour() const { return hour; }
    int getMinute() const { return minute; }

    // Hàm so sánh thời gian (ngày và giờ)
    bool isEarlierThan(const Flight &other) const {
        if (year != other.year)
            return year < other.year;
        if (month != other.month)
            return month < other.month;
        if (day != other.day)
            return day < other.day;
        if (hour != other.hour)
            return hour < other.hour;
        return minute < other.minute;
    }
};

class FlightManager {
private:
    vector<Flight> flightList;

public:
    // Hàm thêm chuyến bay
    void addFlight() {
        Flight f;
        f.input();
        flightList.push_back(f);
        cout << "Da them chuyen bay thanh cong.\n";
    }

    // Hàm nhập danh sách chuyến bay với số lượng cụ thể
    void inputFlights(int n) {
        for (int i = 0; i < n; ++i) {
            cout << "\nNhap thong tin cho chuyen bay thu " << i + 1 << ":\n";
            Flight f;
            f.input();
            flightList.push_back(f);
        }
    }

    // Hàm hiển thị danh sách chuyến bay
    void displayAllFlights() const {
        if (flightList.empty()) {
            cout << "Danh sach chuyen bay rong.\n";
            return;
        }
        for (const auto &f : flightList) {
            f.display();
            cout << "-------------------------\n";
        }
    }

    // Hàm kiểm tra mã chuyến bay tồn tại
    void checkFlightCode() const {
        cin.ignore();
        string code;
        cout << "Nhap ma chuyen bay can kiem tra: ";
        getline(cin, code);
        bool found = false;
        for (const auto& f : flightList) {
            if (f.getFlightCode() == code) {
                found = true;
                cout << "Ma chuyen bay \"" << code << "\" ton tai trong danh sach.\n";
                f.display();
                break;
            }
        }
        if (!found) {
            cout << "Ma chuyen bay \"" << code << "\" khong ton tai trong danh sach.\n";
        }
    }

    // Hàm tìm kiếm chuyến bay
    void searchFlights() const {
        int choice;
        cout << "Tim kiem chuyen bay theo:\n";
        cout << "1. Ma chuyen bay\n";
        cout << "2. Noi di\n";
        cout << "3. Noi den\n";
        cout << "Lua chon cua ban: ";
        cin >> choice;
        cin.ignore();

        vector<Flight> results;
        if (choice == 1) {
            string code;
            cout << "Nhap ma chuyen bay can tim: ";
            getline(cin, code);
            for (const auto &f : flightList) {
                if (f.getFlightCode() == code)
                    results.push_back(f);
            }
        } else if (choice == 2) {
            string dep;
            cout << "Nhap noi di can tim: ";
            getline(cin, dep);
            for (const auto &f : flightList) {
                if (f.getDeparture() == dep)
                    results.push_back(f);
            }
        } else if (choice == 3) {
            string dest;
            cout << "Nhap noi den can tim: ";
            getline(cin, dest);
            for (const auto &f : flightList) {
                if (f.getDestination() == dest)
                    results.push_back(f);
            }
        } else {
            cout << "Lua chon khong hop le.\n";
            return;
        }

        if (results.empty()) {
            cout << "Khong tim thay chuyen bay nao.\n";
        } else {
            cout << "Ket qua tim kiem:\n";
            for (const auto &f : results) {
                f.display();
                cout << "-------------------------\n";
            }
        }
    }

    // Hàm sắp xếp danh sách chuyến bay theo ngày và giờ
    void sortFlights() {
        if (flightList.empty()) {
            cout << "Danh sach chuyen bay rong. Khong the sap xep.\n";
            return;
        }
        sort(flightList.begin(), flightList.end(), [](const Flight &a, const Flight &b) {
            return a.isEarlierThan(b);
        });
        cout << "Da sap xep danh sach chuyen bay theo ngay va gio khoi hanh.\n";
    }

    // Hàm hiển thị danh sách chuyến bay đã sắp xếp
    void displaySortedFlights() const {
        if (flightList.empty()) {
            cout << "Danh sach chuyen bay rong.\n";
            return;
        }
        cout << "\nDanh sach chuyen bay da sap xep:\n";
        for (const auto& f : flightList) {
            f.display();
            cout << "-------------------------\n";
        }
    }

    // Hiển thị danh sách chuyến bay khởi hành từ một nơi cụ thể trong một ngày
    void listFlightsFromPlaceOnDate() const {
        if (flightList.empty()) {
            cout << "Danh sach chuyen bay rong.\n";
            return;
        }
        cin.ignore();
        string dep;
        int day, month, year;
        cout << "Nhap noi di: ";
        getline(cin, dep);
        cout << "Nhap ngay khoi hanh (dd mm yyyy): ";
        cin >> day >> month >> year;

        vector<Flight> results;
        for (const auto& f : flightList) {
            if (f.getDeparture() == dep && f.getDay() == day && f.getMonth() == month && f.getYear() == year) {
                results.push_back(f);
            }
        }

        if (results.empty()) {
            cout << "Khong co chuyen bay nao khoi hanh tu " << dep << " vao ngay "
                 << (day < 10 ? "0" : "") << day << "/"
                 << (month < 10 ? "0" : "") << month << "/" << year << ".\n";
        } else {
            cout << "\nDanh sach chuyen bay khoi hanh tu " << dep << " vao ngay "
                 << (day < 10 ? "0" : "") << day << "/"
                 << (month < 10 ? "0" : "") << month << "/" << year << ":\n";
            for (const auto &f : results) {
                f.display();
                cout << "-------------------------\n";
            }
        }
    }

    // Đếm số lượng chuyến bay từ một nơi đi đến một nơi đến nhất định
    void countFlightsFromTo() const {
        if (flightList.empty()) {
            cout << "Danh sach chuyen bay rong.\n";
            return;
        }
        cin.ignore();
        string dep, dest;
        cout << "Nhap noi di: ";
        getline(cin, dep);
        cout << "Nhap noi den: ";
        getline(cin, dest);

        int count = 0;
        for (const auto &f : flightList) {
            if (f.getDeparture() == dep && f.getDestination() == dest) {
                count++;
            }
        }
        cout << "So luong chuyen bay tu " << dep << " den " << dest << " la: " << count << endl;
    }
};

int main() {
    FlightManager manager;
    int choice;

    do {
        cout << "\n=== Quan Ly Chuyen Bay ===\n";
        cout << "1. Them chuyen bay\n";
        cout << "2. Hien thi tat ca chuyen bay\n";
        cout << "3. Tim kiem chuyen bay\n";
        cout << "4. Kiem tra ma chuyen bay\n";
        cout << "5. Sap xep chuyen bay theo ngay va gio\n";
        cout << "6. Hien thi chuyen bay da sap xep\n";
        cout << "7. Liet ke chuyen bay khoi hanh tu noi di trong ngay\n";
        cout << "8. Dem so chuyen bay tu noi di den noi den\n";
        cout << "0. Thoat\n";
        cout << "Lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
            case 1:
                manager.addFlight();
                break;
            case 2:
                manager.displayAllFlights();
                break;
            case 3:
                manager.searchFlights();
                break;
            case 4:
                manager.checkFlightCode();
                break;
            case 5:
                manager.sortFlights();
                break;
            case 6:
                manager.displaySortedFlights();
                break;
            case 7:
                manager.listFlightsFromPlaceOnDate();
                break;
            case 8:
                manager.countFlightsFromTo();
                break;
            case 0:
                cout << "Tam biet!\n";
                break;
            default:
                cout << "Lua chon khong hop le. Vui long chon lai.\n";
                break;
        }
    } while (choice != 0);

    return 0;
}
