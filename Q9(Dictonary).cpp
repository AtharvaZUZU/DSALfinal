#include <iostream>
#include <string>
#include <map>
#include <iterator>
using namespace std;
class Dictionary
{
public:
    map<string, string> data; // created a map of key string and value string datatype and its object as data 
    void addKeyWord(string keyWord, string meaning)
    {
        // in this we add a new keyword with its associated meaning
        data[keyWord] = meaning;
    }
    void deleteKeyWord(string keyWord)
    {
        data.erase(keyWord);
    }
    void updateKeyWord(string keyWord, string newMeaning)
    {
        data[keyWord] = newMeaning;
    }
    void displayAscending()
    {
        for (map<string, string>::iterator it = data.begin(); it !=data.end();++it)
        {
            cout << it->first << ": " << it->second << endl;
        }
    }
    void displayDescending()
    {
        for (map<string, string>::reverse_iterator it = data.rbegin(); it != data.rend(); ++it)
        {
            cout << it->first << ": " << it->second << endl;
        }
    }
    int getMaxComparisons(string keyword)
    {
        int count = 0;
        for (map<string, string>::iterator it = data.begin(); it !=
                                                              data.end();
             ++it)
        {
            ++count;
            if (it->first == keyword)
            {
                return count;
            }
        }
        return count;
    }
};
void printMenu()
{
    cout << "1. Add keyword" << endl;
    cout << "2. Delete keyword" << endl;
    cout << "3. Update keyword" << endl;
    cout << "4. Display ascending" << endl;
    cout << "5. Display descending" << endl;
    cout << "6. Find max comparisons" << endl;
    cout << "7. Quit" << endl;
    cout << "Enter your choice: ";
}
int main()
{
    Dictionary dict;
    int choice;
    string keyWord, meaning;
    do
    {
        printMenu();
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "\n Enter keyword: ";
            cin >> keyWord;
            cout << "\n Enter meaning: ";
            cin >> meaning;
            dict.addKeyWord(keyWord, meaning);
            break;
        }
        case 2:
        {
            cout << "\n Enter the keyword to delete: ";
            cin >> keyWord;
            dict.deleteKeyWord(keyWord);
            break;
        }
        case 3:
        {
            cout << "\n Enter the keyword you want to update: ";
            cin >> keyWord;
            cout << "\n Enter the new Meaning to assign: ";
            cin >> meaning;
            dict.updateKeyWord(keyWord, meaning);
            break;
        }
        case 4:
        {
            cout << "\n Ascending order:" << endl;
            dict.displayAscending();
            break;
        }
        case 5:
        {
            cout << "\n Descending order:" << endl;
            dict.displayDescending();
            break;
        }
        case 6:
        {
            cout << "Enter keyword: ";
            cin >> keyWord;
            cout << "Max comparisons for '" << keyWord << "': " << dict.getMaxComparisons(keyWord) << endl;
            break;
        }
        case 7:
        {
            cout << "Exiting..." << endl;
            exit(0);
            break;
        }
        default:
        {
            cout << "Invalid choice" << endl;
            break;
        }
        }
    } while (choice != 7);
    return 0;
}
