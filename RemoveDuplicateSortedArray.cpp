//Optimized solution
int removeDuplicates(int* nums, int numsSize) 
{
  if (numsSize == 0) return 0;

  int writeIndex = 1;
  for (int i = 1; i < numsSize; i++) 
  {
    if (nums[i] != nums[i - 1]) 
    {
      nums[writeIndex] = nums[i];
      writeIndex++;
    }
  }
  return writeIndex;
}

//Raw solution
int removeDuplicates(int* nums, int numsSize) 
{
  int size = numsSize;

  for (int i = 0; i < size; i++) 
  {
    for (int k = i + 1; k < size; k++) 
    {
      if (nums[i] == nums[k]) 
      {
        // Shift elements to the left
        for (int j = k; j < size - 1; j++) 
        {
          nums[j] = nums[j + 1];
        }
        size--;
        k--; 
      }
    }
  }
  return size;
}
