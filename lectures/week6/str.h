#if !defined(STR_H)
#define STR_H
typedef struct mystr {
    char* block;
    int sz; //Keep track of str length 
    int capacity; //Keep track of block size
} mystr;

void create_string(mystr** p_p_s); //Send the addr of pointer, set pointer to be addr of valid mystr
void set_char(mystr *p_s, int ind, char c); //Set the char of the string -- send pointer to mystr, change p_s -> block contents
void append_str(mystr *p_s, const char* c); //Append a char to the string
void destroy_string(mystr *p_s); //Free the memory of the string
char get_char(mystr *p_s, int ind); //Get the char of the string
char* get_str(mystr *p_s); //Get the string

#endif