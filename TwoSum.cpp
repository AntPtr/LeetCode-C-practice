/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *Arr = (int*)malloc(2*sizeof(int));

    for(int IndexI = 0; IndexI < numsSize; ++IndexI)
    {
        for(int IndexJ = 0; IndexJ < numsSize; ++IndexJ)
        {
            if(IndexI != IndexJ)
            {
                int Sum = nums[IndexI] + nums[IndexJ];
                if(Sum == target)
                {
                    Arr[0] = IndexI;
                    Arr[1] = IndexJ;
                    *returnSize = 2;
                    return Arr;
                }
            }
        }
    }
    *returnSize = 0;
    free(Arr);
    return NULL;
}
