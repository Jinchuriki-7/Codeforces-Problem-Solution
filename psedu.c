Linear Search
LinearSearch(A,n,key)

for i=0 to n-1

    if A[i]=key

        return i

return -1

Binary Search
BinarySearch(arr, n, target)

low = 0
high = n - 1

while(low <= high)

    mid = (low + high) / 2

    if(arr[mid] == target)
        return "Found"

    else if(arr[mid] < target)
        low = mid + 1

    else
        high = mid - 1

return "Not Found"

Merge short
MergeSort(arr, left, right)

if(left < right)

    mid = (left + right) / 2

    MergeSort(arr, left, mid)

    MergeSort(arr, mid + 1, right)

    Merge(arr, left, mid, right)


Quick short
QuickSort(l,h)

if(l<h)
{
    j=Partition(l,h)
    QuickSort(l,j)
    QuickSort(j+1,h)
}
Partition(l,h)

pivot=A[l]
i=l
j=h

while(i<j)
{
    do
        i=i+1
    while(A[i]<=pivot)

    do
        j=j-1
    while(A[j]>pivot)

    if(i<j)
        swap(A[i],A[j])
}

swap(A[l],A[j])

return j

Insertion short
InsertionSort(A, n)

for i = 1 to n-1
{
    temp = A[i]
    j = i - 1

    while (j >= 0 and A[j] > temp)
    {
        A[j + 1] = A[j]
        j = j - 1
    }

    A[j + 1] = temp
}
Selection short
SelectionSort(A,n)

for i=0 to n-2
    min=i

    for j=i+1 to n-1
        if A[j]<A[min]
            min=j

    swap(A[i],A[min])

    BubbleSort(A,n)

    for i=0 to n-2

     for j=0 to n-2-i

        if A[j]>A[j+1]

            Swap(A[j],A[j+1])