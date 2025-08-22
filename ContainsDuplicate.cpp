//Raw solution
bool containsDuplicate(int* nums, int numsSize) 
{
    bool found = false;
    for(int i = 0; i < numsSize; ++i)
    {
        for(int j = 0; j < numsSize; ++j)
        {
            if(nums[i] == nums[j] && i != j)
            {
                found = true;
                return found;
            }
        }    
    }
    return found;
}

//Optimized weith hash table
#include <stdbool.h>
#include <stdlib.h>

typedef struct 
{
  int *table;
  int size;
} HashSet;

int hash(int key, int size) 
{
  return (key < 0 ? -key : key) % size;
}

bool insert(HashSet *set, int key) 
{
  int idx = hash(key, set->size);
  while (set->table[idx] != INT_MIN) 
  {
    if (set->table[idx] == key) return false; // duplicate found
    idx = (idx + 1) % set->size;
  }
  set->table[idx] = key;
  return true;
}

bool containsDuplicate(int* nums, int numsSize) 
{
  HashSet set;
  set.size = numsSize * 2; // larger size to reduce collisions
  set.table = malloc(set.size * sizeof(int));
  for (int i = 0; i < set.size; i++) set.table[i] = INT_MIN;

  for (int i = 0; i < numsSize; i++) 
  {
    if (!insert(&set, nums[i])) 
    {
      free(set.table);
      return true; // duplicate found
    }
  }
  free(set.table);
  return false;
}
