void insertion_sort(int array[], int size)
{
    int tmp,smallest;

    for (int i = 0; i < size; ++i)
    {
        smallest = i;
        // we find the smallest unsorted number, and swap it w/ i
        for (int j = i + 1; j < size; ++j)
        {
            if (array[j] < array[smallest])
            { smallest = j; }
        }
        // so the swap is so inconsequential, this check makes no practical difference:
        // don't swap if they're the same in hopes to save time
        // if (array[smallest] == array[i]) { continue; }
        // swap
        tmp = array[i];
        array[i] = array[smallest];
        array[smallest] = tmp;
    }
}