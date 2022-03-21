#include <list>
#include <iostream>
#include "mat.hpp"
#include <string>

using namespace std;

void print_all_carpets(list<string> c_list)
{
    /* simple function to print all strings in a list(=linked list) */
    for (string carpet : c_list)
    {
        cout << carpet << "\n";
    }
}

void print_specific_carpet(list<string> c_list, int idx)
{
    /* simple function to print carpet at specific inx (assuming input is valid) */
    int i=0;
    for (string carpet : c_list)
    {
        if (i == idx)
        {
            cout << carpet << "\n";
            return;
        }
        i++;
    }
}

int main()
{
    // temp vars for input user 
    list<string> carpet_list;
    string temp_car;
    int temp_c, temp_r; 
    char temp_s1, temp_s2;
    int pivot, idx;

    while(1){
        cout << "inputs: 1 = add carpet, 2 = print all carpets added, 3 = specific carpet, anything else to EXIT: ";
        cin >> pivot;
        if (pivot == 1)
        {
            // get input from user about sizes and symbols
            cout << "\ntype col num: ";
            cin >> temp_c;
            cout << "type row num: ";
            cin >> temp_r;
            cout << "type 1st symbol: ";
            cin >> temp_s1;
            cout << "type 2nd symbol: ";
            cin >> temp_s2;
            // create carpet and add to list
            temp_car = ariel::mat(temp_c, temp_r, temp_s1, temp_s2);
            carpet_list.push_back(temp_car);
        } 
        else if (pivot == 2)
        {
            // call to func to print all carpets
            print_all_carpets(carpet_list);
        }
        else if (pivot == 3)
        {
            // update idx
            cout << "type idx of ur specific carpet: ";
            cin >> idx;
            if (0 <= idx && idx < carpet_list.size())
            {
                print_specific_carpet(carpet_list, idx);
            }
            else 
            {
                cout << "invalid idx, sorry <3 ";
            }
        }
        else
        {
            // defualt, stop running
            return 1;
        }
    }
}