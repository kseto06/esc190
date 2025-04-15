
#if !defined(AL_H)
#define AL_H

typedef struct ArrayList{
    int *array;
    int size;
    int capacity;
} AL;

void create_list(AL **list);
void destroy_list(AL *list);


void insert_list(AL *list, int data);
void print_list(AL *list);
void delete_list(AL *list, int data);
void destroy_list(AL *list);
void delete_list_ind(AL *list, int index);

#endif
