#include <iostream> //to use cin and cout
#include <fstream>  //to get input from a file
#include <string>   //uses strings
#include <vector>
#include "bits/stdc++.h"

using namespace std;

ifstream in_file;

double sum_vec(vector<double> data)
{
    double result = 0;
    for(int i = 0; i < data.size(); i++){
        result += data[i];
    };
    return result;

};


int main() {

    in_file.open("p8input.txt", ios::in);
    if(in_file.fail()) {
        cout << "Could not open input file.  Program terminating.\n\n";
        return 9;
    }
    
    //Your code goes here
    //remember that you can read from the file by treating
    //  in_file like cin. For example,


    int last_num = 0;

    double max_sales = 0.0;

    string highest_income;

    string most_sales;

    int max_num_sales = 0;



    do {
        string name;

    in_file >> name;

    int num_sales;

    in_file >> num_sales;

    if(num_sales > max_num_sales){
        max_num_sales = num_sales;
        most_sales = name;
    };



    vector<double> values;

    for(int i = 0; i < num_sales; i++){
        double s;
        in_file >> s;
        values.push_back(s);
    };

    if(sum_vec(values) > max_sales ){
        max_sales = sum_vec(values);
        highest_income = name;
    }

    int l;
    in_file >> l;

    last_num = l;

    cout << "Salesperson name: " << name << endl;
    cout << "Number of sales: " << num_sales << endl;
    cout << "Total income: " << sum_vec(values) << endl;


    cout << "\n";

    if(in_file.eof()){
        cout << "Most sales: " << most_sales<< endl;
        cout << "Highest income: " << highest_income << endl;
    };
} while (last_num != -2);

};