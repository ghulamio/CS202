/** 
* Title: Algorithm analysis & Sorting 
* Author : GHULAM AHMED
* ID: 22101001
* Section : 2
* Homework : 1 
* Description : description of your code */ 


void insertionSort(int *arr, const int size, int &compCount, int &moveCount){
    int i, j, temp;
    for (i = 1; i < size; i++){
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp){
            arr[j + 1] = arr[j];
            j--;
            compCount++;
            moveCount++;
        }
        arr[j + 1] = temp;
        moveCount++;
    }
}

void bubbleSort(int *arr, const int size, int &compCount, int &moveCount){
    int i, j, temp;
    for (i = 0; i < size - 1; i++){
        for (j = 0; j < size - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                moveCount += 3;
            }
            compCount++;
        }
    }
}

void hybridBubbleSort(int *arr, int startIndex, int endIndex, int &compCount, int &moveCount){
    int i, j, temp;
    int size = endIndex - startIndex;
    for (i = 0; i < size - 1; i++){
        for (j = startIndex; j <= startIndex + size - i; j++){
            compCount++;
            if (arr[j] > arr[j + 1]){
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                moveCount += 3;
            }
        }
    }
}

void merge(int *arr, int *left, int *right, int leftSize, int rightSize, int &compCount, int &moveCount){
    int i = 0, j = 0, k = 0;
    while (i < leftSize && j < rightSize){
        compCount ++;
        if (left[i] <= right[j]){
            arr[k] = left[i];
            i++;
            moveCount++;
        }
        else{
            arr[k] = right[j];
            j++;
            moveCount++;
        }
        k++;
    }
    while (i < leftSize){
        arr[k] = left[i];
        i++;
        k++;
        moveCount++;
    }
    while (j < rightSize){
        arr[k] = right[j];
        j++;
        k++;
        moveCount++;
    }
    compCount += (leftSize + rightSize - k) * 2; 
}

void mergeSort(int *arr, const int size, int &compCount, int &moveCount){
    if (size < 2){
        return;
        compCount ++;
    }
    int mid = size / 2;
    int left[mid];
    int right[size - mid];

    for (int i = 0; i < mid; i++){
        left[i] = arr[i];
        moveCount++;
    }
    for (int i = mid; i < size; i++){
        right[i - mid] = arr[i];
        moveCount++;
    }

    mergeSort(left, mid, compCount, moveCount);
    mergeSort(right, size - mid, compCount, moveCount);
    merge(arr, left, right, mid, size - mid, compCount, moveCount);
    compCount += mid + (size - mid) - 1; 
}


void quickSort(int *arr, const int size, int &compCount, int &moveCount){
    if (size < 2){
        return;
        compCount ++;
    }
    int lSize = 0, rSize = 0;
    int *lArray = new int[size];
    int *rArray = new int[size];
    int pivot = arr[size/2];
    moveCount += 2;

    for (int i=0; i<size; i++){
        if (arr[i] < pivot){
            lArray[lSize] = arr[i];
            lSize++;
            moveCount++;
            compCount++;
        }
        else if (arr[i] > pivot){
            rArray[rSize] = arr[i];
            rSize++;
            moveCount++;
            compCount++;
        }
        else {
            compCount++;
        }
    }

    int i = 0;
    for (; i<lSize; i++){
        arr[i] = lArray[i];
        moveCount++;
    }
    arr[i] = pivot;
    moveCount++;
    i++;
    for (int j=0; j<rSize; j++){
        arr[i] = rArray[j];
        moveCount++;
        i++;
    }

    delete[] lArray;
    delete[] rArray;

    quickSort(arr, lSize, compCount, moveCount);
    quickSort(arr + lSize + 1, rSize, compCount, moveCount);

    compCount += lSize - 1;
    compCount += rSize - 1;
}

void hybridSort(int *arr, const int size, int &compCount, int &moveCount){
    if (size < 2){
        compCount ++;
        return;
    }
    int lSize = 0, rSize = 0;
    int *lArray = new int[size];
    int *rArray = new int[size];
    int pivot = arr[size/2];
    moveCount += 2;

    for (int i=0; i<size; i++){
        if (arr[i] < pivot){
            lArray[lSize] = arr[i];
            lSize++;
            moveCount++;
            compCount ++;
        }
        else if (arr[i] > pivot){
            rArray[rSize] = arr[i];
            rSize++;
            moveCount++;
            compCount ++;
        }
        else {
            compCount ++;}
    }

    int i = 0;
    for (; i<lSize; i++){
        arr[i] = lArray[i];
        moveCount++;
    }
    arr[i] = pivot;
    moveCount++;
    i++;
    for (int j=0; j<rSize; j++){
        arr[i] = rArray[j];
        moveCount++;
        i++;
    }

    delete[] lArray;
    delete[] rArray;

    if (lSize <= 20){
        hybridBubbleSort(arr, 0, lSize, compCount, moveCount);
    }
    else{
        quickSort(arr, lSize, compCount, moveCount);
    }
    if (rSize <= 20){
        hybridBubbleSort(arr, lSize + 1, size, compCount, moveCount);
    }
    else{
        quickSort(arr + lSize + 1, rSize, compCount, moveCount);
    }
}