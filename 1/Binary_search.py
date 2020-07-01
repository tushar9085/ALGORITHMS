
def binarySearch(A, UB, LB, value):
    while UB >= LB:
        mid = int((UB + LB)/2)
        if A[mid] == value:
            return mid+1

        elif A[mid] <= value:
            LB = mid + 1

        elif A[mid] >= value:
            UB = mid -1

array = [1,2,4,5,6,7]

a = binarySearch(array, len(array)-1, 0, 5)
print(a)
