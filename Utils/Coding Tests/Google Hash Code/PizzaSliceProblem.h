#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <map>

int CURRENTSUM = 0;
std::string TEMP = "";

struct DataTemplate
{
    int MaxSlices;
    int NoOfPizzas;
    std::map<int, int> slices;

    DataTemplate()
    {
        this->MaxSlices = 0;
        this->NoOfPizzas = 0;
    }
};

struct DataTemplate* ConvertData(std::string s)
{
    DataTemplate* ptr = new DataTemplate();
    size_t start = 0, end = 0;
    try
    {
        end = s.find(" ");
        ptr->MaxSlices = stoi(s.substr(start, end));

        start = end;
        end = s.find(" ", end + 1);
        ptr->NoOfPizzas = stoi(s.substr(start, end));
    }
    catch (...) {}

    for (int i = 0; i < ptr->NoOfPizzas; i++)
    {
        start = end;
        end = s.find(" ", end + 1);
        ptr->slices.insert(std::pair<int, int>(i, stoi(s.substr(start, end))));
    }
    return ptr;
}

int RecursionBackTracking(DataTemplate* ptr, int index, int sum, std::string s)
{
    if (index > ptr->NoOfPizzas || sum == ptr->MaxSlices)
    {
        if (sum > CURRENTSUM && sum <= ptr->MaxSlices)
        {
            CURRENTSUM = sum;
            TEMP = s;
        }
        else
            sum = CURRENTSUM;
        return sum;
    }

    int sum1 = RecursionBackTracking(ptr, index + 1, sum, s);

    if (sum + ptr->slices[index] <= ptr->MaxSlices)
        sum = RecursionBackTracking(ptr, index + 1, sum + ptr->slices[index], s + " " + std::to_string(index));
    sum = (sum > sum1) ? sum : sum1;

    return sum;
}

void ComputeLargeDataSet(struct DataTemplate* ptr)
{
    int sum = 0;
    int i = ptr->NoOfPizzas - 1;
    int mediate = ptr->MaxSlices - (ptr->MaxSlices / ptr->NoOfPizzas);
    std::string temp = "";

    while (mediate > sum + ptr->slices[i] || i < 0)
    {
        sum = sum + ptr->slices[i];
        temp = std::to_string(i) + " " + temp;
        i--;
    }

    ptr->MaxSlices = ptr->MaxSlices - sum;
    ptr->NoOfPizzas = i + 1;
    i = (i >= 10) ? i - 10 : i;
    sum = RecursionBackTracking(ptr, i, 0, "") + sum;
    TEMP = TEMP + " " + temp;
}

void ProcessData(struct DataTemplate* ptr)
{
    if (ptr->NoOfPizzas <= 20)
        RecursionBackTracking(ptr, 0, 0, "");
    else
        ComputeLargeDataSet(ptr);
}

std::string GetString()
{
    std::string s1, s2;
    std::ifstream DATA_FILE;

    try
    {
        DATA_FILE.open("Pizza_Slices_Problem\\c_medium.in", std::ios::in);
        getline(DATA_FILE, s1);
        getline(DATA_FILE, s2);
        s1 = s1 + " " + s2;
        DATA_FILE.close();
    }
    catch (std::exception x) { std::cout << "File Error ... !" << std::endl; }
    return s1;
}

void SetString(struct DataTemplate* ptr)
{
    int size = 0;
    for (int i = 0; i < TEMP.size(); i++)
        if (TEMP[i] == ' ')
            size++;
    try
    {
        std::ofstream DATA_FILE;
        DATA_FILE.open("Pizza_Slices_Problem\\Ans.out", std::ios::out);
        DATA_FILE << size << std::endl;
        TEMP.erase(0, 1);
        DATA_FILE << TEMP << std::endl;

        DATA_FILE.close();
    }
    catch (std::exception x) { std::cout << "File Error ... !" << std::endl; }
}
