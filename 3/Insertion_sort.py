

### CODE BY ME
def insertionSort(A):
    temp = None
    for i in range(len(A) - 1):
        key = i + 1

        while A[key] < A[key-1] and key != 0:
            temp = A[key]
            A[key] = A[key-1]
            A[key-1] = temp
            key -= 1
    return A


# ANOTHER ATTEMPT OF ME WHERE TEMP DOESNT REQUIRED
# (ALMOST LIKE MIT)
# (*** THINK ***)

def insertionSort1(A):
    for i in range(len(A) - 1):
        key = i + 1
        key_value = A[key]

        while key_value < A[key-1] and key != 0:
            A[key] = A[key-1]
            key -= 1
        A[key] = key_value
    return A


### CODE BY MIT
def insertSortMIT(A):
    for j in range(len(A)):
        key = A[j]
        # insert A[j] into sorted sequence A[0..j-1]
        i = j-1
        while i > -1 and A[i] > key:
            A[i+1] = A[i]
            i = i-1
        A[i+1] = key
    return A


Array = [5, 2, 4, 6, 1, 3]
print(Array)

A = insertionSort(Array)
print(A)
B = insertSortMIT(Array)
print(B)
C = insertionSort1(Array)
print(C)
