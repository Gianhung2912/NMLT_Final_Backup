/*
Họ và tên: Bùi Thị Hồng Nhung
Mã số: 17110201
Công dụng: Chương trình mẫu, có thể chạy được
Ngày cập nhật cuối: Oct 21, 2020
*/

//Phần 1: Các thư viện cần thiết
#include <iostream>
#include <conio.h>
using namespace std;
//Phần 2: Khai thác toàn cục(kiểu ,hằng biến hàm
//Phần 3: Thân chương trình chính


void NhapMang(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nhap vao phan tu a[" << i << "] : ";
        cin >> a[i];
    }
}

void XuatMang(int a[], int n) {

    printf("Mang vua nhap la: \n");

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
}

int KiemTraNTo(int n)
{
    if (n <= 1)
        return false;

    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;

    return true;
}

void HoanVi(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void SapXepNTo(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (KiemTraNTo(a[i]) == 1)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (KiemTraNTo(a[j]) == 1 && a[i] > a[j])
                {
                    HoanVi(a[i], a[j]);
                }
            }
        }
    }
}

void TimSoNtoXuatHienNhieuLanNhat(int a[], int n)
{
    int nto[100];
    int count = 0;
    for (int i = 0; i < n; i++) 
    {
        if (KiemTraNTo(a[i]) == 1) 
        {
            nto[count++] = a[i];
        }
    }

    if (count == 0)
    {
        cout << 0 << "\n";
        return;
    }

    int max_count = 1, res = nto[0], curr_count = 1;
    for (int i = 1; i < count; i++) {
        if (nto[i] == nto[i - 1])
            curr_count++;
        else {
            if (curr_count > max_count) {
                max_count = curr_count;
                res = nto[i - 1];
            }
            curr_count = 1;
        }
    }

    if (curr_count > max_count)
    {
        max_count = curr_count;
        res = nto[n - 1];
    }

    cout << res << " " << max_count << "\n";
}


int main()
{
    //Khai báo biến cục bộ (dùng trong main)
    do {
        int a[100];
        int n;

        // Cau a
        cout << "Nhap n: ";
        cin >> n;
        NhapMang(a, n);
        XuatMang(a, n);

        // Cau b
        SapXepNTo(a, n);
        XuatMang(a, n);
        
        // Cau c
        TimSoNtoXuatHienNhieuLanNhat(a, n);

        cout << "Nhan phim ESC de thoat...\n";
    } while (_getch() != 27);

}



//Phần 4: Thân của các hàm/chương trình con tự tạo