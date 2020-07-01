
#### CODE BY ME ###

### BINARY SEARCH
### RETURNS THE POSITION OF THE KEY VALUE WHERE IT SHOULD BE
### THEN YOU NEED TO CHECK KEY VALUE AND THE ARRAY[POS]


def binarySearch(A, UB, LB, value):
    mid = None

    while UB > LB:
        mid = int((UB + LB)/2)
        if A[mid] == value:
            return mid + 1

        elif A[mid] <= value:
            LB = mid + 1

        elif A[mid] >= value:
            UB = mid -1
    return LB


### INSERTION SORT

def insertionSort(A):
    for i in range(len(A) - 1):
        key = i + 1
        key_value = A[key]

        if key == 1 and key_value < A[key-1]:
            A[key] = A[key - 1]
            A[key-1] = key_value

        else:
            pos = binarySearch(A,key - 1, 0, key_value)
            j = key - 1

            if key_value < A[pos]:
                while j >= pos:
                    A[j+1] = A[j]
                    j -= 1
                A[pos] = key_value

            if key_value > A[pos]:
                while j > pos:
                    A[j+1] = A[j]
                    j -= 1
                A[pos + 1] = key_value

    return A

def __main__():
    Array = [1,2,3,4,5,6,7,8,9,0]
    print(Array)
    A = insertionSort(Array)
    print(A)

__main__()