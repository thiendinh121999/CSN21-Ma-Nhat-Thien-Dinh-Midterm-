#include <iostream>
#include <vector>
#include <algorithm>
#include <map>


using namespace std;

// Dùng map để lưu các kết quả đã tính toán
map<int, vector<vector<int>>> memo;

vector<vector<int>> findCombinations(const vector<int>& arr, int target) {
    // Nếu target đã có trong memo, trả về kết quả đã lưu
    if (memo.count(target)) {
        return memo[target];
    }

    vector<vector<int>> result;

    // Trường hợp cơ bản: nếu target bằng 0, ta có một tổ hợp rỗng
    if (target == 0) {
        result.push_back({});
        return memo[target] = result;
    }

    // Nếu target âm, không có tổ hợp nào hợp lệ
    if (target < 0) {
        return result; 
    }

    // Duyệt qua từng phần tử trong mảng
    for (int num : arr) {
        // Đệ quy để tìm các tổ hợp cho phần còn lại (target - num)
        vector<vector<int>> sub_combinations = findCombinations(arr, target - num);

        // Nếu có các tổ hợp con, thêm 'num' vào mỗi tổ hợp đó
        for (const auto& sub_comb : sub_combinations) {
            vector<int> current_comb = sub_comb;
            current_comb.push_back(num);
            // Sắp xếp để tránh các tổ hợp trùng lặp với thứ tự khác nhau 
            sort(current_comb.begin(), current_comb.end());
            result.push_back(current_comb);
        }
    }

    // Lưu kết quả vào memo trước khi trả về
    return memo[target] = result;
}

int main() {
    vector<int> a = {1, 2, 6, 8, 35, 9};
    int k = 10;
    cout << "k=" << k;

    //Xếp lại mảng
    sort(a.begin(), a.end());

    vector<vector<int>> combinations = findCombinations(a, k);

    // Loại bỏ các tổ hợp trùng lặp
    vector<vector<int>> unique_combinations;
    map<vector<int>, bool> seen; 

    for (const auto& comb : combinations) {
        if (seen.find(comb) == seen.end()) {
            unique_combinations.push_back(comb);
            seen[comb] = true;
        }
    }

    cout << "\nCác tổ hợp có tổng bằng " << k << " là:" << endl;
    if (unique_combinations.empty()) {
        cout << "Không có tổ hợp có tổng bằng 10" << endl;
    } else {
        for (const auto& comb : unique_combinations) {
            cout << "[";
            for (size_t i = 0; i < comb.size(); ++i) {
                cout << comb[i];
                if (i < comb.size() - 1) {
                    cout << ", ";
                }
            }
            cout << "]" << endl;
        }
    }

    return 0;
}