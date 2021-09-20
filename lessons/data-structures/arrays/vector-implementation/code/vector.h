typedef struct vector {
	int capacity;
	int size;
	int* arr;
	void (*init)(struct vector*);
	void (*get)(struct vector*);
} vector ;

void init(vector* v) {
	v->arr = (int*)malloc(sizeof(int) * v->capacity);
}
