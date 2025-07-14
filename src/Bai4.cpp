#include <iostream> 
#include <vector>  
#include <algorithm> 


using namespace std;

// Sử dụng Greedy Algorithm

struct HoatDong {
    int id;    // Số thứ tự của hoạt động
    int batDau; // Thời điểm bắt đầu 
    int ketThuc; // Thời điểm kết thúc
};

// So sánh để sắp xếp các hoạt động theo thời điểm kết thúc tăng dần

bool soSanhHoatDong(const HoatDong& a, const HoatDong& b) {
    return a.ketThuc < b.ketThuc;
}

int main() {
    // Ma trận các hoạt đã cho theo dạng {id,batDau,ketThuc}
    vector<HoatDong> cacHoatDong = {
        {1, 1, 3},
        {2, 2, 5},
        {3, 4, 7},
        {4, 1, 8},
        {5, 5, 9},
        {6, 8, 10}
    };

    // Sắp xếp các hoạt động theo thời điểm kết thúc tăng dần
    sort(cacHoatDong.begin(), cacHoatDong.end(), soSanhHoatDong);

    cout << "Các hoạt động đã được sắp xếp (theo thời gian kết thúc):" << endl;
    for (const auto& hd : cacHoatDong) {
        cout << "Hoạt động " << hd.id << ": [" << hd.batDau << ", " << hd.ketThuc << "]" << endl;
    }
    cout << endl;

    // Danh sách các hoạt động được chọn
    vector<HoatDong> cacHoatDongDuocChon;

    // Chọn hoạt động đầu tiên (hoạt động kết thúc sớm nhất)
    cacHoatDongDuocChon.push_back(cacHoatDong[0]);
    int thoiGianKetThucCuoiCung = cacHoatDong[0].ketThuc;

    // Duyệt qua các hoạt động còn lại để chọn
    for (size_t i = 1; i < cacHoatDong.size(); ++i) {
        // Nếu thời điểm bắt đầu của hoạt động hiện tại lớn hơn hoặc bằng thời điểm kết thúc của hoạt động cuối cùng đã chọn, thì chọn hoạt động này
        if (cacHoatDong[i].batDau >= thoiGianKetThucCuoiCung) {
            cacHoatDongDuocChon.push_back(cacHoatDong[i]);
            thoiGianKetThucCuoiCung = cacHoatDong[i].ketThuc; 
        }
    }

    // In ra hoạt động đã chọn
    cout << "Số lượng hoạt động không trùng lặp tối đa đã chọn:" << endl;
    for (const auto& hd : cacHoatDongDuocChon) {
        cout << "Hoạt động " << hd.id << ": [" << hd.batDau << ", " << hd.ketThuc << "]" << endl;
    }
    cout << "\nTổng số hoạt động đã chọn: " << cacHoatDongDuocChon.size() << endl;

    return 0;
}