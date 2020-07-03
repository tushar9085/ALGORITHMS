
def mergeSort(A):

    n = len(A)
    mid = int(n / 2)

    print(n)
    print(mid)

    if n == 1:
        return A

    L = mergeSort(A[:mid])
    R = mergeSort(A[mid:])
    C = []
    C.extend(merge(L, R))
    print(C)
    print(L)
    print(R)

    return C


def merge(L, R):
    i = 0
    j = 0

    B = list()

    while i < len(L) and j < len(R):
        if L[i] <= R[j]:
            B.append(L[i])
            i += 1
        else:
            B.append(R[j])
            j += 1

    if i >= len(L):
        while j < len(R):
            B.append(R[j])
            j += 1

    else:
        while i < len(L):
            B.append(L[i])
            i += 1
    return B

Array = [15, 5, 60, 8, 1, 3, 16, 10, 20]

A = mergeSort(Array)
print(A)

