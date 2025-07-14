#include <iostream> 
#include <cmath>   


using namespace std; 


long long tinhtoan(int n) {
    // Kiểm tra n không âm
    if (n < 0) {
        cerr << "Lỗi: n không được âm." << endl;
        return -1; // Trả về giá trị lỗi
    }
    // Trường hợp cơ sở: f(0)
    if (n == 0) {
        cout << "f(0) = 1" << endl; // In giá trị f(0)
        return 1;
    }

    long long current_f_value = 1; // Khởi tạo với f(0) = 1

   
    for (int i = 0; i < n; ++i) {

        current_f_value = current_f_value + (long long)3 * pow(2, i);
    
    }
    return current_f_value; // Trả về giá trị cuối cùng là f(n)
}

int main() {
    // --- Hiển thị công thức mối liên hệ ---
    cout << "--- Mối liên hệ của dãy số f(n) ---" << endl;
    cout << "Dãy số được cho là:" << endl;
    cout << "f(0) = 1" << endl;
    cout << "f(1) = 4" << endl;
    cout << "f(2) = 10" << endl;
    cout << "..." << endl;
    cout << "\nPhân tích sự khác biệt giữa các số hạng liên tiếp:" << endl;
    cout << "f(1) - f(0) = 4 - 1 = 3" << endl;
    cout << "f(2) - f(1) = 10 - 4 = 6" << endl;
    cout << "f(3) - f(2) = 22 - 10 = 12" << endl;
    cout << "..." << endl;
    cout << "Nhận thấy dãy hiệu (3, 6, 12, ...) là một cấp số nhân với số hạng đầu là 3 và công bội là 2." << endl;
    cout << "Do đó, ta có công thức đệ quy: f(n) = f(n-1) + 3 * 2^(n-1) (với f(0) = 1)." << endl;
     cout << "Có thể suy ra công thức tổng quát là" << endl;
    cout << "f(n) = 3 * 2^n - 2" << endl;
    cout << "------------------------------------" << endl;

    
    int n;
    cout << "\nNhập một số nguyên n để tính f(n) theo công thức" << endl;
    cout << "n = ";
    cin >> n;

    long long ketqua = tinhtoan(n);

    if (ketqua != -1) { // Kiểm tra xem lỗi
        cout << "\nGiá trị của f(" << n << ") là: " << ketqua << endl;
    }

    return 0;
}