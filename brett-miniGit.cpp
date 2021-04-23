#include "brett-miniGit.hpp"
#include <filesystem>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
namespace fs = std::filesystem;

miniGit::miniGit(/* args */)
{
    fs::remove_all(".minigit");       // remove directory and its contents
    fs::create_directory(".minigit"); // create a new directory
}

miniGit::~miniGit()
{

}

void miniGit::init()
{
    commit_head = new branchNode;   // branch nodes are doubly linked lists
    commit_head->commit_ID = 0; // initial file version is 0
    commit_head->file_head = nullptr;   // head of file nodes stored in a singly linked 
    commit_head->previous = nullptr; // pointer to previous branchNode in the doubly linked list 
    commit_head->next = nullptr; // pointer to the next branchNode in the doubly linked list
}
void miniGit::addFile(string file_to_add)
{
    if (commit_head == nullptr)
    {
        cout << "miniGit has not been initialized" << endl;
    }
    else
    {
        fileNode *curr = commit_head->file_head; // initialized a curr pointer at the head of a file node SLL
        while (curr != nullptr)
        {
            if (curr->fileName == file_to_add)
            {
                cout << "file already exists" << endl;
                return;
            }
            curr = curr->next;
        }

        fileNode* new_file = new fileNode();
        new_file->fileName = file_to_add;
        new_file->fileVersion = "0";
        new_file->next = commit_head->file_head;
        commit_head->file_head = new_file;

        return;
    }
}
void miniGit::rmFile(string file_to_remove)
{
    if (commit_head == nullptr)
    {
        cout << "miniGit has not been initialized" << endl;
    }
    else
    {
        fileNode *curr = commit_head->file_head;
        fileNode *prev = nullptr;
        while (curr != nullptr)
        {
            if (curr->fileName == file_to_remove)
            {
                if (prev != nullptr) // 
                {
                    prev->next = curr->next;
                    delete curr;
                    return;
                }
                else
                {
                    commit_head->file_head = curr->next;    // 
                    delete curr; 
                }
                
            }
            // keep iterating across the SLL until we find the file_to_remove we are looking for
            prev = curr;
            curr = curr->next;
        }
        cout << "file does not exist" << endl; // looped through entire fileNode SLL and did not find the file we wanted to remove

        return;
    }
}

void file_copy(string input_file_name, string output_file_name)
{
    ifstream input_file(input_file_name);
    ofstream output_file(output_file_name);
    char char1, char2;
    bool flag = false;

    if (!input_file.is_open())
    {
        cout << "failed to open input file" << endl;
        return;
    }
    if (!output_file.is_open())
    {
        cout << "failed to open output file" << endl;
        return;
    }
    
    while (true)
    {
        char1 = input_file.get();
        if (char1 == EOF)
        {
            break;
            output_file << char1;
        }
    }
    
    input_file.close();
    output_file.close();
}

bool isEqual(string file1, string file2)
{
    
}

bool miniGit::commit()
{
    
}