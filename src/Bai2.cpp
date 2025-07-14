#include <iostream> 
#include <vector>  
#include <string>   


using namespace std; 


class Bai2 {
public:
    char kthCharacter(int k, string& formed_string) {
        vector<int> word;
        word.push_back(0); // Bắt đầu với 'a' (0 là đại diện cho 'a')

        // Mở rộng dãy số cho đến khi nó đủ lớn để chứa phần tử thứ k

        while (word.size() < k) {
            int m = word.size(); 
            // Duyệt qua các phần tử hiện có và thêm các phần tử mới vào cuối
            for (int i = 0; i < m; ++i) {
                word.push_back((word[i] + 1) % 26);
            }
        }
        
        // Tạo chuỗi ký tự từ toàn bộ vector 'word' sau khi nó đã đủ lớn
        for (int val : word) { 
            formed_string += (char)('a' + val);
        }
        
        
        return 'a' + word[k - 1];
    }
};


int main() {

    Bai2 sol; 

    int k_input;
    string generated_string; // lưu trữ chuỗi đã hình thành
    
    // Nhập k
    cout << "Nhập số nguyên k (vị trí ký tự bạn muốn tìm): ";
    cin >> k_input;

    // Kiểm tra  số k nhập vào
    if (k_input <= 0) {
        cout << "Vị trí k phải là một số nguyên dương." << endl;
        return 1; 
    }


    
    char result_char = sol.kthCharacter(k_input, generated_string);

    // In ra toàn bộ chuỗi đã tạo
    cout << "Chuỗi đã hình thành là: " << generated_string << endl;
    
    // In ra màn hình ký tự thứ k trong chuỗi ký tự hình thành
    cout << "Ký tự thứ " << k_input << " trong chuỗi là: " << result_char << endl;

    return 0; 
}