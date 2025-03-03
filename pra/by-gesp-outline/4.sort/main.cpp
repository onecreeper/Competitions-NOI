#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void bubbleSort(vector<int>& target) {
    int s = target.size();
    if (s <= 1) return; // 空数组或单元素数组，直接返回

    int last_swap_index = s - 1; // 初始化最后交换位置为末尾
    while (last_swap_index > 0) {
        bool flag = false;
        int current_swap_index = 0; // 记录本轮最后交换位置
        for(int j = 0 ; j < last_swap_index; ++j){ // 内循环边界变为 last_swap_index
            if (target[j] > target[j + 1]) {
                swap(target[j], target[j + 1]);
                flag = true;
                current_swap_index = j; // 更新本轮最后交换位置
            }
        }
        last_swap_index = current_swap_index; // 更新下轮循环的最后交换位置
        if (flag == false) break; // 如果本轮没有交换，提前结束
    }
}

void selectionSort(vector<int>& target) {
    int n = target.size();
    if (n <= 1) {
        return; // 0 或 1 个元素的 vector 已经排序
    }

    for (int i = 0; i < n - 1; ++i) {
        // 1. 在未排序部分 [i, n-1) 中找到最小元素的索引
        int min_index = i; // 假设当前未排序部分的第一个元素是最小的
        for (int j = i + 1; j < n; ++j) {
            if (target[j] < target[min_index]) {
                min_index = j; // 找到更小的元素，更新最小索引
            }
        }

        // 2. 将找到的最小元素与未排序部分的第一个元素（target[i]）交换位置
        if (min_index != i) { // 如果最小元素不是当前未排序部分的第一个元素，则交换
            std::swap(target[i], target[min_index]);
        }

        // 每一轮循环结束后，target[0...i] 就是已排序的部分
    }
}

void selectionSortWithLibrary(vector<int>& target) {
    int n = target.size();
    if (n <= 1) {
        return; // 0 或 1 个元素的 vector 已经排序
    }

    for (int i = 0; i < n - 1; ++i) {
        // 1. 使用 std::min_element 查找未排序部分 [i, n-1) 中的最小元素的迭代器
        auto min_it = std::min_element(target.begin() + i, target.end());

        // 2. 获取未排序部分的起始迭代器
        auto current_it = target.begin() + i;

        // 3. 使用 std::iter_swap 交换最小元素和当前未排序部分的第一个元素
        if (min_it != current_it) { // 如果最小元素不在当前位置，才需要交换 (优化)
            std::iter_swap(current_it, min_it);
        }
    }
}

void insertSort(vector<int>& target) {
    int s = target.size();
    
    for (int i = 1; i < s; ++i) {
        int current = target[i];
        int j = i - 1;

        while (j >= 0 && target[j] > current) {
            target[j + 1] = target[j];
            --j;
        }
        
        target[j + 1] = current;
    }
}


int quickP(vector<int>& target, int left, int right) {
    int pivotValue = target[left];
    int i = left, j = right;
    
    while(i < j) {
        while(target[j] >= pivotValue && i < j) {
            --j;
        }
        while(target[i] <= pivotValue && i < j) {
            ++i;
        }
        if(i < j) {
            swap(target[i], target[j]);
        }
    }
    swap(target[i], target[left]);
    return i;
}

void quickS(vector<int>& target, int left, int right) {
    if (left >= right) return;
    int base = quickP(target, left, right);
    quickS(target, left, base - 1);
    quickS(target, base + 1, right);
}

void quickSort(vector<int>& target) {
    quickS(target, 0, target.size() - 1);
}

int main (){
    vector<int> myVector = {1,4,6,8,9,6,5,3,1};

    cout << "排序前: ";
    for (int i : myVector) cout << i;
    cout << endl;

    quickSort(myVector); // 调用冒泡排序函数，传入 vector 的引用

    cout << "排序后: ";
    for (int i : myVector) cout << i;
    cout << endl;

    return 0;
}