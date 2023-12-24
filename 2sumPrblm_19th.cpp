#include <iostream>

/*
                            Q. 2 sum Problem

                    explanation - there are 2 variants of this question
                                1) first one says, we are given a array arr[] = {2, 6, 5, 8, 11} and a
                                    target value (lets take 14)
                                    according to the question do we have 2 elements from the array
                                    which would give us sum as the target value,   such as {6 and 8}
                                    answer will be in 'Yes' or 'No'

                                2) second one says, to return the indexes of the element which would return 
                                    the target value    (here we get [1, 3]  for {6, 8})

                Brute force - in this approach we will take take the element at index 1 and pick every other
                                elements to check if we can get our reqd sum

for(i = 0; i<n; i++)
{
    for(j = i+1; j < n; j++)
    {
        if(arr[i] + arr[j] == target)
        {
            i, j;
        }
    }
}

                TC - O(N^2)


                Better sol - using hashing
                              will create a hash table and store element and index - > |element, index|
                              where element is 'key' and index is 'index'

                            first we will take element 2, to get our target we should also have 12, from our hash
                            table we will check if there is 12, but there is not (bcz hash table is currently empty).
                            so we store (2, 0) in hash table

                            then we take element 6, to get our target we need 8 but currently there is no 8 in the
                            hash table.  so we store (6, 1) in hash table

                            then we take element 5, to get our target we need 9 but there is no 9 in the hash table
                            so we store (5, 2) in hash table

                            then we take element 8 to get our target we need 6 and there is (6, 1) in our hash table
                            now we can return 'yes' as o/p and if it is asking for indexes we can return (3, 1)

                            if we can't find any 2Sum then we return 'no'

         Actual code
string read(int n, vector<int> book, int target)
{
    map<int, int> mpp;
    for(int i = 0; i < n; i++)
    {
        int a = book[i];
        int more = target - a;

        if(mpp.find(more) != mpp.end())
            return "YES";                   // return (mpp[more], i);       <- if indexes are asked

        mpp[a] = i;
    }
    return "NO";
}


        Actual code     (if indexes are asked)
vector<int> twoSum(vector<int>& nums, int target)
{
    map<int, int> mpp;
    int n = nums.size();
    for(int i = 0; i < n; i++)
    {
        int num = nums[i];
        int moreNeeded = target - num;
        if(mpp.find(moreNeeded) != mpp.end())
            return {mpp[moreNeeded], i};

        mpp[num] = i;
    }
    return {-1, -1};
}


                TC - O(N*log N)         // O(N) for unordered map
                                        // O(N^2) for worst case of unordered map
                SC - O(N)



                Optimal sol -  2 pointer approach

            expl -  we will appoint 'i' to index 0 & 'j' to index n and add them up
                    from above example we get 2+11 = 13
                    as we know the arrary is in sorted order by which means if we go fwd from index 0
                    we get larger nmbr and if we go bckwd from index n we get smaller nmbr
                    we got 13 as our sum which is smaller than 14(target) so we move 'i' to index 2
                    & add them, we will get 5+11 = 16
                    which is larger than target so we move 'j' bckwd to element 8 & add them, we will
                    get 5+8 = 13
                    which is smller than target so we moe 'i' fwd to element 6 & add them, we will get
                    6+8 = 14 which is our desired o/p

                    if any point the pointers cross and we don't find our desired o/p then we let or
                    o/p as 'NO'

                variety 2-
                    if it is asked the indexes of element then we have to put the array in some other 
                    data structure, where they stored as "key, value" type, but this approach will cost
                    most more time complexity which is not optimal

        Actual code
string read(int n, vector<int> book, int target)
{
    int left = 0, right = n-1;
    sort(book.begin(), book.end());

    while(left < right)
    {
        int sum = book[left] + book[right];
        if(sum == target)
            return "YES";
        else if(sum < target)
            left++;
        else
            right--;
    }
    return "NO";
}


                TC - O(N) + O(N*log N)      // moving left and right + for sorting
                SC - O(1)
                SC - O(N)           // <- for sorting of array


        note - better solution is optimal for variety 2`
*/

int main()
{
    std::cout << "Hello World!\n";
}