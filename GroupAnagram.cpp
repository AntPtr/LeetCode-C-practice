/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
bool isAnagram(char* s, char* t) {
    int count[26] = {0};

    for(int i = 0; s[i] != '\0'; ++i)
    {
        ++count[s[i] - 'a'];
    }

    for(int i = 0; t[i] != '\0'; ++i)
    {
        --count[t[i] - 'a'];
        ++s;
    }

    for(int i = 0; i < 26; ++i)
    {
        if(count[i] != 0 )
        {
            return false;
        }
    }
    return true;
}

char* copyString(const char* src) {
    int len = strlen(src);
    char* dst = malloc((len + 1) * sizeof(char));
    strcpy(dst, src);
    return dst;
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    char ***Result = malloc(strsSize*sizeof(char**));
    *returnColumnSizes = malloc(strsSize*sizeof(int));
    *returnSize = 0;

    int *Used = calloc(strsSize, sizeof(int));

    for(int i = 0; i < strsSize; ++i)
    {
        if(Used[i])
            continue;

        Result[*returnSize] = malloc(strsSize*sizeof(char*));
        int GroupCount = 0;

        Result[*returnSize][GroupCount++] = copyString(strs[i]);
        Used[i] = 1;
        for(int j = i + 1; j < strsSize; ++j)
        {
            if(!Used[j] && isAnagram(strs[i], strs[j]))
            {
                Result[*returnSize][GroupCount++] = copyString(strs[j]);
                Used[j] = 1;
            }
        }

        (*returnColumnSizes)[*returnSize] = GroupCount;
        (*returnSize)++;
    }
    free(Used);   
    return Result;
}
