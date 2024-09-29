#include <bits/stdc++.h>
using namespace std;

// Hàm kiểm tra chuỗi không chứa ký tự đặc biệt
bool hasSpecialChar(const string &str) {
    for (char c : str) {
        if (!isalnum(c))
            return true;
    }
    return false;
}

// Hàm kiểm tra chuỗi chỉ chứa chữ cái và khoảng trắng (họ tên)
bool isAlphabetic(const string &str) {
    for (char c : str) {
        if (!isalpha(c) && c != ' ')
            return false;
    }
    return true;
}

// Hàm kiểm tra CMND hợp lệ (9 hoặc 12 chữ số)
bool isValidID(const string &id) {
    if (id.length() != 9 && id.length() != 12)
        return false;
    for (char c : id) {
        if (!isdigit(c))
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

// Lớp SavingsAccount (Sổ tiết kiệm)
class SavingsAccount {
private:
    string accountCode;      // Mã sổ
    string savingsType;      // Loại tiết kiệm
    string customerName;     // Họ tên khách hàng
    string idNumber;         // Chứng minh nhân dân
    int day, month, year;    // Ngày mở sổ
    double depositAmount;    // Số tiền gửi
    double interestRate;     // Lãi suất (%/năm)
    double interestAmount;   // Tiền lãi
    bool isWithdrawn;        // Trạng thái đã rút tiền hay chưa

public:
    SavingsAccount() {
        interestRate = 0.0;
        interestAmount = 0.0;
        isWithdrawn = false;
    }

    // Hàm nhập dữ liệu
    void input() {
        cin.ignore();

        // Nhập mã sổ
        do {
            cout << "Nhap ma so (toi da 5 ky tu, khong chua khoang trang hoac ky tu dac biet): ";
            getline(cin, accountCode);
            if (accountCode.empty() || accountCode.length() > 5 || hasSpecialChar(accountCode) || accountCode.find(' ') != string::npos) {
                cout << "Ma so khong hop le. Vui long nhap lai.\n";
            } else {
                break;
            }
        } while (true);

        // Nhập loại tiết kiệm
        do {
            cout << "Nhap loai tiet kiem (toi da 10 ky tu): ";
            getline(cin, savingsType);
            if (savingsType.empty() || savingsType.length() > 10) {
                cout << "Loai tiet kiem khong hop le. Vui long nhap lai.\n";
            } else {
                break;
            }
        } while (true);

        // Nhập họ tên khách hàng
        do {
            cout << "Nhap ho ten khach hang (toi da 30 ky tu, khong chua so hoac ky tu dac biet): ";
            getline(cin, customerName);
            if (customerName.empty() || customerName.length() > 30 || !isAlphabetic(customerName)) {
                cout << "Ho ten khong hop le. Vui long nhap lai.\n";
            } else {
                break;
            }
        } while (true);

        // Nhập CMND
        do {
            cout << "Nhap so CMND (9 hoac 12 chu so): ";
            getline(cin, idNumber);
            if (!isValidID(idNumber)) {
                cout << "So CMND khong hop le. Vui long nhap lai.\n";
            } else {
                break;
            }
        } while (true);

        // Nhập ngày mở sổ
        do {
            cout << "Nhap ngay mo so (dd mm yyyy): ";
            cin >> day >> month >> year;
            if (!isValidDate(day, month, year)) {
                cout << "Ngay mo so khong hop le. Vui long nhap lai.\n";
            } else {
                break;
            }
        } while (true);

        // Nhập số tiền gửi
        do {
            cout << "Nhap so tien gui (so duong): ";
            cin >> depositAmount;
            if (depositAmount <= 0) {
                cout << "So tien gui phai la so duong. Vui long nhap lai.\n";
            } else {
                break;
            }
        } while (true);

        isWithdrawn = false; // Khi mới mở sổ thì chưa rút tiền
    }

    // Hàm xuất dữ liệu
    void display() const {
        cout << "Ma so: " << accountCode << endl;
        cout << "Loai tiet kiem: " << savingsType << endl;
        cout << "Ho ten khach hang: " << customerName << endl;
        cout << "So CMND: " << idNumber << endl;
        cout << "Ngay mo so: " << (day < 10 ? "0" : "") << day << "/"
             << (month < 10 ? "0" : "") << month << "/" << year << endl;
        cout << "So tien gui: " << depositAmount << endl;
        cout << "Lai suat: " << interestRate << "%/nam" << endl;
        cout << "Tien lai: " << interestAmount << endl;
        cout << "Trang thai rut tien: " << (isWithdrawn ? "Da rut tien" : "Chua rut tien") << endl;
    }

    // Cập nhật lãi suất
    void updateInterestRate(double rate) {
        interestRate = rate;
        calculateInterest();
    }

    // Tính toán tiền lãi dựa trên thời gian gửi
    void calculateInterest() {
        // Tính số ngày gửi
        time_t t = time(0);
        tm *now = localtime(&t);
        int currentYear = now->tm_year + 1900;
        int currentMonth = now->tm_mon + 1;
        int currentDay = now->tm_mday;

        // Chuyển đổi ngày mở sổ và ngày hiện tại thành số ngày
        struct tm startDate = {0};
        startDate.tm_year = year - 1900;
        startDate.tm_mon = month - 1;
        startDate.tm_mday = day;

        struct tm endDate = {0};
        endDate.tm_year = currentYear - 1900;
        endDate.tm_mon = currentMonth - 1;
        endDate.tm_mday = currentDay;

        time_t start = mktime(&startDate);
        time_t end = mktime(&endDate);

        double seconds = difftime(end, start);
        double days = seconds / (60 * 60 * 24);

        // Chuyển đổi sang số tháng
        double months = days / 30;

        // Tính tiền lãi
        if (savingsType == "ngan han") {
            if (months <= 6) {
                interestAmount = depositAmount * (interestRate / 100) * (months / 12);
            } else {
                interestAmount = depositAmount * (interestRate / 100) * (6 / 12);
            }
        } else if (savingsType == "dai han") {
            if (months > 6) {
                interestAmount = depositAmount * (interestRate / 100) * (months / 12);
            } else {
                interestAmount = depositAmount * (interestRate / 100) * (6 / 12);
            }
        } else {
            // Không kỳ hạn hoặc loại khác
            interestAmount = depositAmount * (interestRate / 100) * (months / 12);
        }
    }

    // Chức năng rút tiền
    void withdraw(double amount) {
        if (isWithdrawn) {
            cout << "So tiet kiem da duoc rut tien truoc do.\n";
            return;
        }

        if (amount > depositAmount + interestAmount) {
            cout << "So tien rut vuot qua so du tai khoan.\n";
            return;
        }

        // Kiểm tra rút trước hạn
        time_t t = time(0);
        tm *now = localtime(&t);
        int currentYear = now->tm_year + 1900;
        int currentMonth = now->tm_mon + 1;
        int currentDay = now->tm_mday;

        struct tm startDate = {0};
        startDate.tm_year = year - 1900;
        startDate.tm_mon = month - 1;
        startDate.tm_mday = day;

        struct tm endDate = {0};
        endDate.tm_year = currentYear - 1900;
        endDate.tm_mon = currentMonth - 1;
        endDate.tm_mday = currentDay;

        time_t start = mktime(&startDate);
        time_t end = mktime(&endDate);

        double seconds = difftime(end, start);
        double days = seconds / (60 * 60 * 24);

        double months = days / 30;

        if (savingsType == "ngan han" && months < 6) {
            cout << "Ban dang rut truoc han. Lai suat se duoc tinh lai voi muc 0.5%/nam.\n";
            interestRate = 0.5;
            calculateInterest();
        } else if (savingsType == "dai han" && months < 6) {
            cout << "Ban dang rut truoc han. Lai suat se duoc tinh lai voi muc 0.5%/nam.\n";
            interestRate = 0.5;
            calculateInterest();
        }

        depositAmount = depositAmount + interestAmount - amount;
        interestAmount = 0; // Sau khi rút tiền, tiền lãi được tính lại từ đầu
        isWithdrawn = true;
        cout << "Rut tien thanh cong. So du hien tai: " << depositAmount << endl;
    }

    // Getter để lấy CMND và mã sổ
    string getIDNumber() const {
        return idNumber;
    }

    string getAccountCode() const {
        return accountCode;
    }

    // Getter để lấy ngày mở sổ
    int getOpenDay() const { return day; }
    int getOpenMonth() const { return month; }
    int getOpenYear() const { return year; }

    // Getter để lấy số tiền gửi
    double getDepositAmount() const {
        return depositAmount;
    }
};

class SavingsAccountManager {
private:
    vector<SavingsAccount> accountList;

public:
    // Thêm sổ tiết kiệm
    void addAccount() {
        SavingsAccount account;
        account.input();
        accountList.push_back(account);
    }

    // Cập nhật lãi suất cho tất cả các sổ
    void updateInterestRates() {
        double rate;
        cout << "Nhap lai suat (%/nam): ";
        cin >> rate;
        for (auto &account : accountList) {
            account.updateInterestRate(rate);
        }
        cout << "Da cap nhat lai suat cho tat ca cac so tiet kiem.\n";
    }

    // Chức năng rút tiền
    void withdrawMoney() {
        string code;
        cout << "Nhap ma so cua so tiet kiem can rut tien: ";
        cin.ignore();
        getline(cin, code);
        bool found = false;
        for (auto &account : accountList) {
            if (account.getAccountCode() == code) {
                found = true;
                double amount;
                cout << "Nhap so tien can rut: ";
                cin >> amount;
                account.withdraw(amount);
                break;
            }
        }
        if (!found) {
            cout << "Khong tim thay so tiet kiem voi ma so \"" << code << "\".\n";
        }
    }

    // Tìm kiếm sổ tiết kiệm theo CMND hoặc mã sổ
    void searchAccount() {
        int choice;
        cout << "Tim kiem so tiet kiem theo:\n";
        cout << "1. CMND\n";
        cout << "2. Ma so\n";
        cout << "Lua chon cua ban: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string id;
            cout << "Nhap so CMND: ";
            getline(cin, id);
            bool found = false;
            for (const auto &account : accountList) {
                if (account.getIDNumber() == id) {
                    account.display();
                    found = true;
                }
            }
            if (!found) {
                cout << "Khong tim thay so tiet kiem voi CMND \"" << id << "\".\n";
            }
        } else if (choice == 2) {
            string code;
            cout << "Nhap ma so: ";
            getline(cin, code);
            bool found = false;
            for (const auto &account : accountList) {
                if (account.getAccountCode() == code) {
                    account.display();
                    found = true;
                }
            }
            if (!found) {
                cout << "Khong tim thay so tiet kiem voi ma so \"" << code << "\".\n";
            }
        } else {
            cout << "Lua chon khong hop le.\n";
        }
    }

    // Liệt kê các sổ tiết kiệm mở trong một khoảng thời gian
    void listAccountsInPeriod() {
        int startDay, startMonth, startYear;
        int endDay, endMonth, endYear;

        cout << "Nhap ngay bat dau (dd mm yyyy): ";
        cin >> startDay >> startMonth >> startYear;
        cout << "Nhap ngay ket thuc (dd mm yyyy): ";
        cin >> endDay >> endMonth >> endYear;

        struct tm startDate = {0};
        startDate.tm_year = startYear - 1900;
        startDate.tm_mon = startMonth - 1;
        startDate.tm_mday = startDay;

        struct tm endDate = {0};
        endDate.tm_year = endYear - 1900;
        endDate.tm_mon = endMonth - 1;
        endDate.tm_mday = endDay;

        time_t start = mktime(&startDate);
        time_t end = mktime(&endDate);

        if (difftime(end, start) < 0) {
            cout << "Khoang thoi gian khong hop le.\n";
            return;
        }

        bool found = false;
        for (const auto &account : accountList) {
            struct tm openDate = {0};
            openDate.tm_year = account.getOpenYear() - 1900;
            openDate.tm_mon = account.getOpenMonth() - 1;
            openDate.tm_mday = account.getOpenDay();

            time_t open = mktime(&openDate);

            if (difftime(open, start) >= 0 && difftime(end, open) >= 0) {
                account.display();
                cout << "-------------------------\n";
                found = true;
            }
        }

        if (!found) {
            cout << "Khong co so tiet kiem nao mo trong khoang thoi gian nay.\n";
        }
    }

    // Sắp xếp danh sách theo số tiền gửi giảm dần
    void sortByDepositAmount() {
        sort(accountList.begin(), accountList.end(), [](const SavingsAccount &a, const SavingsAccount &b) {
            return a.getDepositAmount() > b.getDepositAmount();
        });
        cout << "Da sap xep danh sach theo so tien gui giam dan.\n";
    }

    // Sắp xếp danh sách theo ngày mở sổ tăng dần
    void sortByOpenDate() {
        sort(accountList.begin(), accountList.end(), [](const SavingsAccount &a, const SavingsAccount &b) {
            struct tm dateA = {0};
            dateA.tm_year = a.getOpenYear() - 1900;
            dateA.tm_mon = a.getOpenMonth() - 1;
            dateA.tm_mday = a.getOpenDay();

            struct tm dateB = {0};
            dateB.tm_year = b.getOpenYear() - 1900;
            dateB.tm_mon = b.getOpenMonth() - 1;
            dateB.tm_mday = b.getOpenDay();

            time_t timeA = mktime(&dateA);
            time_t timeB = mktime(&dateB);

            return difftime(timeA, timeB) < 0;
        });
        cout << "Da sap xep danh sach theo ngay mo so tang dan.\n";
    }

    // Hiển thị danh sách sổ tiết kiệm
    void displayAllAccounts() const {
        if (accountList.empty()) {
            cout << "Danh sach so tiet kiem rong.\n";
            return;
        }
        for (const auto &account : accountList) {
            account.display();
            cout << "-------------------------\n";
        }
    }
};

int main() {
    SavingsAccountManager manager;
    int choice;

    do {
        cout << "\n=== Quan ly So Tiet Kiem ===\n";
        cout << "1. Them so tiet kiem\n";
        cout << "2. Cap nhat lai suat\n";
        cout << "3. Rut tien\n";
        cout << "4. Tim kiem so tiet kiem\n";
        cout << "5. Liet ke so tiet kiem trong khoang thoi gian\n";
        cout << "6. Sap xep danh sach theo so tien gui giam dan\n";
        cout << "7. Sap xep danh sach theo ngay mo so tang dan\n";
        cout << "8. Hien thi tat ca so tiet kiem\n";
        cout << "0. Thoat\n";
        cout << "Lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
            case 1:
                manager.addAccount();
                break;
            case 2:
                manager.updateInterestRates();
                break;
            case 3:
                manager.withdrawMoney();
                break;
            case 4:
                manager.searchAccount();
                break;
            case 5:
                manager.listAccountsInPeriod();
                break;
            case 6:
                manager.sortByDepositAmount();
                break;
            case 7:
                manager.sortByOpenDate();
                break;
            case 8:
                manager.displayAllAccounts();
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
