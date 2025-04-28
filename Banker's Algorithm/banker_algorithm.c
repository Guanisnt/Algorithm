/*
banker's algorithm，按照OS簡報的寫法
n: number of tasks
m: number of resources types
available: vector of length m, if available[i]=k, there are k instances of resource type R[j] available
max: n*m matrix, if max[i, j]=k, then task T[i] may request at most k instances of resource typr R[j]
allocation: n*m matrix, if allocation[i, j]=k, then T[i] is currently allocated k instances of R[j]
need: n*m matrix, if need[i, j]=k, then T[i] may need k more instances of R[j] to complete its task
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_PROCESSES 20
#define MAX_RESOURCES 20

int n, m;
int avai[MAX_RESOURCES];
int max[MAX_PROCESSES][MAX_RESOURCES];
int alloc[MAX_PROCESSES][MAX_RESOURCES];
int need[MAX_PROCESSES][MAX_RESOURCES];
bool finish[MAX_PROCESSES];
int work[MAX_PROCESSES]; // 目前可用資源
int safeSequence[MAX_PROCESSES];

void input() {
	printf("input the number of processes: ");
	scanf("%d", &n);
	printf("input the number of resources types: ");
	scanf("%d", &m);
	printf("Enter Available Resources:\n");
	for(int j=0; j<m; j++) scanf("%d", &avai[j]);
	printf("Enter Allocation Matrix:\n");
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			scanf("%d", &alloc[i][j]);
		}
	}
	printf("Enter Max Matrix:\n");
	for(int i=0; i<n; i++) {
                for(int j=0; j<m; j++) {
                        scanf("%d", &max[i][j]);
                }
        }
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			need[i][j] = max[i][j] - alloc[i][j]; // 最多-目前他有的
		}
	}
}

bool can_alloc(int i) {
	for(int j=0; j<m; j++) {
		if(work[j] < need[i][j]) return false; // 目前有的不夠需求
	}
	return true;
}

void find_safe_sequence(int cnt) {
	if(cnt == n) {
		printf("safe sequence: ");
		for(int i=0; i<n; i++) {
			printf("T[%d]", safeSequence[i]);
			if(i!=n-1) printf(" -> ");
		}
		printf("\n");
		return;
	}
	for(int i=0; i<n; i++) {  // 分配每一個task
		if(!finish[i] && can_alloc(i)) {
			for(int j=0; j<m; j++) {
				work[j] = work[j] + alloc[i][j];
			}
			finish[i] = true;
			safeSequence[cnt] = i;
			find_safe_sequence(cnt+1);

			// back track
			for(int j=0; j<m; j++) {
				work[j] = work[j] - alloc[i][j];
			}
			finish[i] = false;
		}
	}
}

void banker_algo() {
	for(int j=0; j<m; j++) work[j] = avai[j];
	for(int i=0; i<n; i++) finish[i] = false;
	printf("all possible safe sequence:\n");
	find_safe_sequence(0);
}

int main() {
	input();
	banker_algo();
	return 0;
}
