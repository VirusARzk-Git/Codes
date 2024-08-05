'''
Given an array "A" of N integers, you have also defined the new array
"B" as a concatenation of array "A" foran infinite number oftimes. For
example,if the given array "A" is[1,2,3] then,the infinite array "B" is
[1,2,3,1,2,3,1,2,3....]

Now you are given Q queries, each query consists of two integers "L"
and "R" (1 based indexing).Your task is to find the sum of the subarray
from index "L" to "R" (both inclusive) in the infinite array "B" for each
query.
'''

mod = 10**9 + 7

def sumInRanges(arr, n, queries, q):
    for j in range(q):
        s = sum(arr)
        a = queries[j][0]-1
        b = queries[j][1]-1
        m = (b-a+1)//n
        p = b-a+1-m*n
        s = (s*m)%mod
        a=a%n
        b = b%n
        for i in range(a,a+p):
            s = (s + arr[i%n])%mod
        # if b!=n-1:
        #     for i in range(0,b+1):
        #         s = (s + arr[i])%mod
        print(s%mod,end=" ")
    print()
        # print(a,b)

for i in range(int(input())):
    n = int(input())
    arr = list(map(int,input().split()))
    q = int(input())
    queries = []
    for j in range(q):
        a,b= map(int,input().split())
        queries.append([a,b])
    sumInRanges(arr,n,queries,q)

