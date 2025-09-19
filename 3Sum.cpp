#include <stdlib.h>

int cmp(const void *a, const void *b) 
{
    return (*(int*)a - *(int*)b);
}


int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) 
{
  int **Result = malloc(sizeof(int*)*numsSize*numsSize);
  *returnSize = 0;
  *returnColumnSizes = malloc(sizeof(int)*numsSize*numsSize);
  qsort(nums, numsSize, sizeof(int), cmp);
  
    for(int i = 0; i < numsSize - 2; ++i)
    {
        if(i > 0 && nums[i] == nums[i - 1])  {continue;}

        int Left = i + 1;
        int Rigth = numsSize - 1;

        while(Left < Rigth)
        {
            int Sum = nums[i] + nums[Left] + nums[Rigth];
            if(Sum == 0)
            {
                int *Triplet = malloc(sizeof(int)*3);
                Triplet[0] = nums[i];
                Triplet[1] = nums[Left];
                Triplet[2] = nums[Rigth];
                Result[*returnSize] = Triplet;
                (*returnColumnSizes)[*returnSize] = 3;
                 ++(*returnSize);

                 while(Left < Rigth && nums[Left] == nums[Left + 1]) {++Left;}
                 while(Rigth > Left && nums[Rigth] == nums[Rigth - 1]) {--Rigth;}

                 ++Left;
                 --Rigth;
            }
            else if(Sum < 0) {++Left;}
            else {--Rigth;}
        }
    }

  return Result;
}
