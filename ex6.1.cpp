#include <iostream>
#include <vector>

using namespace std;

class ArrayMatcher {
private:
    vector<int> pattern;   // mảng A
    vector<int> text;      // mảng B    
    vector<int> lps;       // Mảng LPS: Prefix dài nhất cũng là suffix (tiền tố dài nhất cũng là hậu tố)
    vector<int> occurrences; // Các chỉ số bắt đầu của các lần xuất hiện của A trong B

    // Tiền xử lý mảng A để tạo mảng LPS
    void computeLPSArray() {
        int M = pattern.size();
        lps.resize(M); // Đặt kích thước cho mảng LPS
        int length = 0;
        lps[0] = 0; // lps[0] luôn luôn bằng 0

        int i = 1;
        while (i < M) {
            if (pattern[i] == pattern[length]) {
                length++;
                lps[i] = length; // Gán giá trị cho lps[i] là độ dài của tiền tố/hậu tố khớp
                i++;
            }
            else {
                if (length != 0) {
                    length = lps[length - 1];
                    // Không tăng i ở đây vì vẫn cần so sánh lại với length mới
                }
                else {
                    lps[i] = 0; // Nếu không có sự trùng khớp thì gán lps[i] là 0
                    i++;
                }
            }
        }
    }

public:
    // Constructor: khởi tạo với mảng A và B
    ArrayMatcher(const vector<int>& A, const vector<int>& B) : pattern(A), text(B) {}

    // Hàm thực hiện thuật toán KMP
    void KMPSearch() {
        computeLPSArray(); // Gọi hàm tính toán mảng LPS

        int N = text.size(); // Độ dài mảng B
        int M = pattern.size(); // Độ dài mảng A
        int i = 0; // Chỉ số của mảng B (text[])
        int j = 0; // Chỉ số của mảng A (pattern[])

        while (i < N) {
            if (pattern[j] == text[i]) {
                i++;
                j++;
            }

            if (j == M) {
                // Tìm thấy mảng A trong mảng B, lưu chỉ số bắt đầu
                occurrences.push_back(i - j);
                j = lps[j - 1]; // Tiếp tục so sánh phần còn lại của mảng A
            }
            else if (i < N && pattern[j] != text[i]) {
                if (j != 0)
                    j = lps[j - 1]; // Quay lại vị trí lps để kiểm tra lại phần khác
                else
                    i++; // Nếu không có sự khớp, chỉ tăng i
            }
        }
    }

    // Hàm trả về số lần xuất hiện của A trong B
    int getOccurrenceCount() const {
        return occurrences.size();
    }

    // Hàm trả về danh sách các chỉ số bắt đầu của các lần xuất hiện
    vector<int> getOccurrences() const {
        return occurrences;
    }
};

int main() {
    int sizeA, sizeB;
    cout << "Nhap so phan tu cua mang A va B: ";
    cin >> sizeA >> sizeB;

    vector<int> A(sizeA);
    vector<int> B(sizeB);

    cout << "Nhap cac phan tu cua mang A:\n";
    for (int i = 0; i < sizeA; ++i) {
        cin >> A[i];
    }

    cout << "Nhap cac phan tu cua mang B:\n";
    for (int i = 0; i < sizeB; ++i) {
        cin >> B[i];
    }

    ArrayMatcher matcher(A, B);
    matcher.KMPSearch(); // Thực hiện tìm kiếm KMP

    int count = matcher.getOccurrenceCount(); // Số lần xuất hiện của A trong B
    vector<int> occurrences = matcher.getOccurrences(); // Các chỉ số bắt đầu của các lần xuất hiện

    cout << "\nSo lan mang A xuat hien trong mang B: " << count << endl;
    if (count > 0) {
        cout << "Cac chi so bat dau cua cac lan xuat hien:\n";
        for (int idx : occurrences) {
            cout << idx << " ";
        }
        cout << endl;
    }

    return 0;
}
