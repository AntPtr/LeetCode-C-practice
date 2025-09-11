/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    int* Result = malloc(sizeof(int) * 2);
    int* Freq = calloc(numsSize + 1, sizeof(int));

    for (int i = 0; i < numsSize; i++) 
    {
        Freq[nums[i]]++;
    }

    int Duplicate = -1, Missing = -1;
    for (int i = 1; i <= numsSize; i++) 
    {
        if (Freq[i] == 2)
        {
            Duplicate = i;
        } 
        if (Freq[i] == 0) 
        {
            Missing = i;
        }
    }

    Result[0] = Duplicate;
    Result[1] = Missing;
    *returnSize = 2;

    free(Freq);
    return Result;
}
