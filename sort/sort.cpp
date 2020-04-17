#include "sort.h"

#define SORT_VECTOR_SIZE	(5)

void myVec::setVec(vector<int> inputVec) {
	vec.assign(inputVec.begin(), inputVec.end());
}

void myVec::showVec() {
	printf("elements of arr:\n");
	cout << "Vector Start" << endl;
	for (int i = 0; i < vec.size(); i++) {
		if (i == vec.size() - 1) {
			printf("%d", vec[i]);
			cout << endl << "Vector End" << endl;
		}
		else {
			printf("%d, ", vec[i]);
		}
	}
}

void myVec::swapVec(int &a, int &b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void mySort::show(void) {
	showVec();
}

void mySort::sortSelectVec(bool ascend) {
	if (ascend) {
		int refMin = INT_MAX;
		int refIdx;
		for (int i = 0; i < vec.size(); i++) {
			refMin = INT_MAX;
			for (int j = i; j < vec.size(); j++) {
				if (refMin > vec[j]) {
					refMin = vec[j];
					refIdx = j;
				}
			}
			swapVec(vec[i], vec[refIdx]);
		}
	}
	else {
		int refMax = INT_MIN;
		int refIdx;
		for (int i = 0; i < vec.size(); i++) {
			refMax = INT_MIN;
			for (int j = i; j < vec.size(); j++) {
				if (refMax < vec[j]) {
					refMax = vec[j];
					refIdx = j;
				}
			}
			swapVec(vec[i], vec[refIdx]);
		}
	}
}

void mySort::sortInsertVec(bool ascend) {
	for (int i = 0; i < vec.size() - 1; i++) {
		for (int j = i; j >= 0; j--) {
			if (ascend) {
				if (vec[j+1] < vec[j]) {
					swapVec(vec[j], vec[j + 1]);
				}
			}
			else{
				if (vec[j + 1] > vec[j]) {
					swapVec(vec[j], vec[j + 1]);
				}
			}
		}
	}
}

void mySort::sortBubbleVec(bool ascend){
	for (int i = 0; i < vec.size(); i++){
		for (int j = 0; j < vec.size() - i - 1; j++){
			if(ascend){
				if(vec[j] > vec[j + 1]){
					swapVec(vec[j], vec[j + 1]);
				}
				else{}
			}
			else{
				if (vec[j] < vec[j + 1]) {
					swapVec(vec[j], vec[j + 1]);
				}
				else {}
			}
		}
	}
}

void mySort::sortQuickVec(int start, int end){
	if (start >= end) return;
	int pivot = start, i = start + 1, j = end;
	while (true){
		while ((i <= end)  && (vec[i] <= vec[pivot])) i++;
		while ((j > start) && (vec[j] >= vec[pivot])) j--;
		if (i > j){
			swapVec(vec[j], vec[pivot]);
			break;
		}
		else {
			swapVec(vec[i], vec[j]);
		}
	}	
	sortQuickVec(start, j - 1);
	sortQuickVec(j + 1, end);
}

void mySort::sortRankVec(){
	int rankSize = 1000;
	vector<int> rankVec(rankSize, 0);
	for (int i = 0; i < vec.size(); i++){
		rankVec[vec[i]]++;
	}

	printf("elements of arr:\n");
	for (int i = 0; i < rankSize; i++){
		if (rankVec[i] != 0){
			printf("%d, ", i);
		}
	}
}

void mySort::sortRadixVec(){
	vector<int> result(vec.size());

	int maxDigit = 0;
	int exp = 1;
	for (int i = 0; i < vec.size(); i++){
		maxDigit = maxDigit < vec[i] ? vec[i] : maxDigit;
	}
	
	while (maxDigit / exp > 0){
		vector<int> bucket(10, 0);
		
		for (int i = 0; i < vec.size(); i++) {
			int digit = (vec[i] / exp) % 10;
			bucket[digit]++;
			
		}
#if 1
		printf("Bucket Element:\n");
		for (int i = 0; i < bucket.size(); i++) {
			printf("%d, ", bucket[i]);
		}
#endif
		for (int i = 1; i < bucket.size(); i++){
			bucket[i] += bucket[i - 1]; // accumulate
		}
#if 1
		printf("\nAccumulate Element:\n");
		for (int i = 0; i < bucket.size(); i++) {
			printf("%d, ", bucket[i]);
		}
#endif
		for (int i = vec.size() - 1; i >= 0; i--){
			int resultIdx = bucket[(vec[i] / exp) % 10];
			result[resultIdx - 1] = vec[i]; //result[bucket[(vec[i] / exp) % 10] = vec[i]
			bucket[(vec[i] / exp) % 10]--;
		}
#if 1
		printf("\nResult Element:\n");
		for (int i = 0; i < result.size(); i++) {
			printf("%d, ", result[i]);
		}
#endif
		exp *= 10;

		vec.assign(result.begin(), result.end());
		printf("\nelements of arr:\n");
		for (int i = 0; i < vec.size(); i++) {
			if (vec.size() != 0) {
				printf("%d, ", result[i]);
			}
		}
	}	

}