#include <iostream>
using namespace std;

int main() {
    int array[10] = {19, 29, 2, 27, 3, 23, 5, 9, 8, 0};
    for(int i=1; i<10; i++) {
        int cur = array[i];  // 目前要插入的數字
        int j = i - 1;  // 從目前要插入的數字的前一個開始比較
        while(j>=0 && cur<array[j]) {  // 如果目前要插入的數字比前一個小
            array[j+1] = array[j];  // 把前一個往後移
            j--;  // 繼續往前比較
        }
        array[j+1] = cur;  // 把目前要插入的數字插入到正確的位置
    }
    for(int i=0; i<10; i++) {
        cout << array[i] << " ";
    }
}