// Variant 10

#include<iostream>
#include<string>
using namespace std;

struct File{
    string name;
    int creation_date;
    int queries;
    File* node;

    File(string name, int creation_date, int queries){
        this->name = name;
        this->creation_date = creation_date;
        this->queries = queries;
    }

    void set_node(File* node){
        this->node = node;
    }
};

File* create_file(){
    File* file1 = new File("first", 20, 35);
    File* file2 = new File("second", 15, 21);
    File* file3 = new File("third", 31, 3);
    file1->set_node(file2);
    file2->set_node(file3);
    return file1;
}

void render_files(File* file){
    File* iter = file;
    while(iter != NULL){
        cout << iter->name << " " << iter->creation_date << " " << iter->queries << endl;
        iter = iter->node;
    }
}

void remove_all_with_prev_dates(File **file, int date){
    File* iter = *file;
    File* prev = NULL;
    if (iter != NULL && iter->creation_date < date)
    {
        *file = iter->node;
        iter = iter->node;
    } else {
        prev = iter;
        iter = iter->node;
    }
    while (iter)
    {
        if(iter->creation_date < date){
            prev->node = iter->node;
            iter = iter->node;
        } else {
            prev = prev->node;
            iter = iter->node;
        }
        
    }
}

int largest_queries(File* f){
    int maxim = 0;
    File* iter = f;
    while(iter != NULL){
        if(iter->queries > maxim){
            maxim = iter->queries;
        } 
        iter = iter->node;
    }
    return maxim;
}

int main(){
   File* file = create_file();
//   remove_all_with_prev_dates(&file, 10);
//   render_files(file);
   cout << largest_queries(file);
}