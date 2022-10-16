#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Banking{
	char acc_from[50];
	char acc_to[50];
	int money;
	char time_point[50];
	char atm[50];
} ds[10005];

char accs[200005][50];

// function to find the partition position
int partition(char array[][50], int low, int high) {
  
  // select the rightmost element as pivot
  char pivot[50], tmp[50];
  strcpy(pivot, array[high]);
  
  // pointer for greater element
  int i = (low - 1);

  // traverse each element of the array
  // compare them with the pivot
  int j;
  for (j = low; j < high; j++) {
  	if (strcmp(array[j], pivot) <= 0){    
        
      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;
      
      // swap element at i with element at j      
      strcpy(tmp, array[i]);
      strcpy(array[i], array[j]);
      strcpy(array[j], tmp);
    }
  }

  // swap the pivot element with the greater element at i
  strcpy(tmp, array[i + 1]);
  strcpy(array[i + 1], array[high]);
  strcpy(array[high], tmp);
  
  // return the partition point
  return (i + 1);
}

void quickSort(char array[][50], int low, int high) {
  if (low < high) {
    
    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on right of pivot
    int pi = partition(array, low, high);
    
    // recursive call on the left of pivot
    quickSort(array, low, pi - 1);
    
    // recursive call on the right of pivot
    quickSort(array, pi + 1, high);
  }
}

int main() {	
	int n = 0;
	int m = 0;
	char tmp[50];
	while (scanf("%s", tmp)){
		if (strcmp(tmp,"#") == 0) break;
		strcpy(ds[n].acc_from, tmp);
		scanf("%s", ds[n].acc_to);
		scanf("%d", &ds[n].money);
		scanf("%s", ds[n].time_point);
		scanf("%s", ds[n].atm);
		strcpy(accs[m], ds[n].acc_to);
		m+=1;
		strcpy(accs[m], ds[n].acc_from);
		m+=1;
		n+= 1;
	}
	
	int i;
	long long sum = 0;
	for (i=0; i<n; i++) sum += ds[i].money;
	quickSort(accs, 0, m-1);
	
	while (scanf("%s", tmp)){
		if (strcmp(tmp,"#") == 0) break;
		if (strcmp(tmp, "?list_sorted_accounts") == 0){
			printf("%s ", accs[0]);
			for (i=1; i<m; i++){
				if (strcmp(accs[i], accs[i-1]) == 0) continue;
				printf("%s ", accs[i]);
			}
				
			printf("\n");
		}
	}	

  	return 0;
}