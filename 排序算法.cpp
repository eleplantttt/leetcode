//
// Created by admin on 2023/6/25.
//
#include <iostream>
#include <vector>

using namespace std;
// 冒泡排序
void BubbleSort(vector<int>& nums, int left, int right) {
    for(int i = left; i <= right - 1; i++) {
        for (int j = left; j <= right - 1 - i; ++j) {
            if (nums[j] > nums[j + 1]) {
                swap(nums[j], nums[j + 1]);
            }
        }
    }
}

// 插入排序（前2，3，4...有序，记住当前，while找合适的位置）
void InsertionSort1(vector<int>& nums, int left, int right) {
    for(int i = left + 1; i <= right; i++) {
        int temp = nums[i];
        int j = i;
        while (j > left && nums[j - 1] > temp) {
            nums[j] = nums[j - 1];
            j--;
        }
        nums[j] = temp;
    }
}
void InsertionSort2(vector<int>& nums, int left, int right) {
    for(int i = left + 1; i <= right; i++) {
        for (int j = i - 1; j >= left; --j) {
            if (nums[j] > nums[j + 1]) {
                swap(nums[j], nums[j + 1]);
            } else {
                break;
            }
        }
    }
}

// 选择排序
// 从最左边开始找最小数，从左边排起，内层循环找比当前小的数。
void SelectionSort(vector<int>& nums, int left, int right) {
    for (int i = left; i < right; ++i) {
        int min = i;
        for (int j = i + 1; j <= right; ++j) {
            if (nums[j] < nums[min]) {
                min = j;
            }
        }
        swap(nums[i], nums[min]);

    }
}

// 快排
void quickSort(vector<int>& nums, int left, int right) {
    if (right <= left) {
        return;
    }
    int x = rand() % (right - left + 1) + left;
    swap(nums[x], nums[left]);

    int pivot = nums[left];
    int lt = left;
    int gt = right + 1;

    int i = left + 1;

    while (i < gt) {
        if (nums[i] < pivot) {
            lt++;
            swap(nums[i], nums[lt]);
            i++;
        } else if (nums[i] == pivot) {
            i++;
        } else {
            gt--;
            swap(nums[i], nums[gt]);
        }
    }
    swap(nums[left], nums[lt]);
    quickSort(nums, left, lt - 1);
    quickSort(nums, gt, right);
}

// 归并排序
void MergeSort(vector<int>& nums, vector<int>& tmp,int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = left + (right - left) / 2;
    MergeSort(nums, tmp, left , mid);
    MergeSort(nums, tmp, mid + 1, right);
    int i = left, j = mid + 1, pos = left;
    while (i <= mid && j <= right) {
        if (nums[i] < nums[j]) {
            tmp[pos] = nums[i];
            ++i;
        } else {
            tmp[pos] = nums[j];
            ++j;
        }
        ++pos;
    }
    for (int k = i; k <= mid ; ++k) {
        tmp[pos++] = nums[k];
    }
    for (int k = j; k <= right ; ++k) {
        tmp[pos++] = nums[k];
    }
    copy(tmp.begin() + left, tmp.begin() + right + 1, nums.begin() + left);
}

// 堆排序
void maxHeapify(vector<int>& nums, int i, int n) {
    while (i * 2 + 1 < n) {
        // 代表当前 i 节点的左右儿子；
        // 超出数组大小则代表当前 i 节点为叶子节点，不需要移位
        int lSon = 2 * i + 1;
        int rSon = 2 * i + 2;
        int large = i;
        if (lSon < n && nums[lSon] > nums[i]) large = lSon;
        if (rSon < n && nums[rSon] > nums[large]) large = rSon;

        if (large != i) {
            swap(nums[i], nums[large]);
            // 迭代判断对应子节点及其儿子节点的大小关系
            i = large;
        } else {
            break;
        }
    }
}
void buildMaxHeap(vector<int> &nums) {
    int n = nums.size();
    for (int i = (n - 1) / 2; i >= 0; --i) {
        maxHeapify(nums, i, n);
    }
}
void HeapSort(vector<int>& nums){
    // heapSort 堆排序
    int n = nums.size();
    // 将数组整理成大根堆
    buildMaxHeap(nums);
    for (int i = n - 1; i >= 1; --i) {
        // 依次弹出最大元素，放到数组最后，当前排序对应数组大小 - 1
        swap(nums[0], nums[i]);
        --n;
        maxHeapify(nums, 0, n);
    }
}





int main(){
    vector<int> vec = {5,1,1,2,0,0};
    int n = vec.size();

//    quickSort(vec, 0, n - 1);
//    BubbleSort(vec, 0, n - 1);
//    InsertionSort2(vec, 0, n - 1);
//    SelectionSort(vec, 0, n - 1);

//    vector<int> tmp;
//    tmp = vec;
//    MergeSort(vec, tmp, 0, n - 1);
    HeapSort(vec);
    for (auto it : vec) {
        cout<< it << " ";

    }
}

