#include<iostream>
using namespace std;
#define M 7
struct value {
	int key;
	int freq;
};
struct Node {
	value *data;
	int next;
};
struct HashTable {
	Node h[M];
	int r;
};
int func(int key) {
	return key%M;
}
void init(HashTable &ht) {
	for (int i = 0; i < M; i++) {
		ht.h[i].data = NULL;
		ht.h[i].data->freq = 0;
		ht.h[i].next = -1;
	}
	ht.r = M - 1;
}
void insertNode(HashTable &ht, value* x){
	int k = func(x->key);
	if (ht.h[k].data == NULL) {
		ht.h[k].data->key = x->key;
		ht.h[k].data->freq += 1;
	}
	else if (ht.h[ht.r].data->key==x->key) {
		ht.h[k].data->freq += 1;
		}
	else {
			while (ht.h[k].next != -1) {
				k = ht.h[k].next;
				if (ht.h[k].data->key == x->key) {
					ht.h[k].data->freq += 1;
					return;
				}
			}
			ht.h[ht.r].data->key = x->key;
			ht.h[k].next = ht.r;
		}
	while (ht.r >= 0 && ht.h[ht.r].next != -1) {
		ht.r--;
	}
}
void printHashTable(HashTable &ht) {
	for (int i = 0; i < M; i++) {
		if (ht.h[i].data != NULL) {
			cout << "Bucket" << "(" << i << ")" << ht.h[i].data->key << "-->" << ht.h[i].next<<"So lan xuat hien: "<<ht.h[i].data->freq;
		}
		cout << endl;
	}
}
int main() {
	HashTable ht;
	init(ht);
	int a[] = { 15, 7, 9, 7, 13, 15, 20, 11, 9, 15 };
	int n = sizeof(a) / sizeof(a[0]);

	for (int i = 0; i < n; i++) {
		value *v=new value;
		v->key = a[i];
		v->freq = 1;
		insertNode(ht,v);
	}
	/*insertNode(ht, 7);
	insertNode(ht, 14);
	insertNode(ht, 28);
	insertNode(ht, 15);*/
	printHashTable(ht);
	return 0;
}