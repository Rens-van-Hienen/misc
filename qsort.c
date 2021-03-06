/*
 * This is my own implementation of the quicksort algorithm.
 */

void qsort(void *base, size_t num, size_t size, 
		int (*compare)(const void*,const void*)){
	char *bptr = (char *)base;
	size_t pivot = num - 1;
	size_t i = 0;
	while(i < pivot){
		if(compare(bptr + i * size, bptr + pivot * size) > 0){
			size_t j = size;
			char tmp;
			char *a = bptr + i * size;
			char *b = bptr + pivot * size;
			char *c = bptr + (--pivot) * size;
			while(j--){
				tmp = *a;
				*a++ = *c;
				*c++ = *b;
				*b++ = tmp;
			}
			i--;
		}
		i++;
	}
	num = num - pivot;
	if(pivot > 1) qsort(bptr, pivot, size, compar);
	if(num   > 1) qsort((bptr + pivot * size), num, size, compare);
	return;
}

//quicksort for int[] only
/*
void qsort(int *arr, int size){
	int pivot = size-1;
	int i = 0;
	while(i < pivot){
		if(arr[i] > arr[pivot]){
			int j = pivot-1;
			int tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = arr[pivot];
			arr[pivot] = tmp;
			pivot = j;
			i--;
		}
		i++;
	}
	size = size - pivot;
	if(pivot > 1) qsort(arr, pivot);
	if(size  > 1) qsort((arr + pivot), size);
	return;
}
*/
