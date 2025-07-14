#include <iostream>
#include <vector>
#include <algorithm> 
#include <numeric>   

using namespace std; 


pair<int, vector<int>> catThanhSat(const vector<int>& gia, int n) {
    // lưu trữ giá trị lớn nhất có thể thu được từ một thanh sắt dài i
    vector<int> dp(n + 1, 0);
    //  lưu trữ độ dài của đoạn cắt đầu tiên khi đạt được dp[i]
    vector<int> first_cut(n + 1, 0); 

    //xây dựng bảng DP và ghi nhớ lựa chọn
    for (int i = 1; i <= n; ++i) { // 'i' là độ dài của thanh sắt hiện tại mà chúng ta đang xét
        int giaTriLonNhatHienTai = 0; 
        int bestFirstCut = 0; // Lưu trữ độ dài đoạn cắt đầu tiên tốt nhất cho độ dài 'i'

       
        for (int j = 1; j <= i; ++j) { 
            // Công thức: gia của đoạn cắt j + giá trị tối ưu của phần còn lại (i-j)
            int currentCalculation = gia[j - 1] + dp[i - j];
            
            if (currentCalculation > giaTriLonNhatHienTai) {
                giaTriLonNhatHienTai = currentCalculation;
                bestFirstCut = j; // Cập nhật đoạn cắt đầu tiên tốt nhất
            }
        }
        dp[i] = giaTriLonNhatHienTai;
        first_cut[i] = bestFirstCut; // Lưu lại đoạn cắt đầu tiên đã chọn

    }

    // Tạo chuỗi các đoạn cắt
    vector<int> cacDoanCanCat;
    int current_n = n;
    while (current_n > 0) {
        cacDoanCanCat.push_back(first_cut[current_n]);
        current_n -= first_cut[current_n];
    }

    return make_pair(dp[n], cacDoanCanCat); // Trả về cặp (giá trị lớn nhất, vector các đoạn cắt)
}

int main() {
    vector<int> gia = {1, 5, 8, 9, 10, 17, 17, 20}; // Giá cho độ dài 1 đến 8
    int n = 8; // Tổng chiều dài của thanh sắt

    pair<int, vector<int>> ketQua = catThanhSat(gia, n);

    int tongGiaTriLonNhat = ketQua.first;
    vector<int> cacDoanCat = ketQua.second;

    cout << "Giá trị lớn nhất có thể thu được là: " << tongGiaTriLonNhat << endl;
    cout << "Các đoạn cần cắt để đạt giá trị lớn nhất là " << tongGiaTriLonNhat << ": {";
    for (size_t i = 0; i < cacDoanCat.size(); ++i) {
        cout << cacDoanCat[i];
        if (i < cacDoanCat.size() - 1) {
            cout << ", ";
        }
    }
    cout << "}" << endl;

    return 0;
}