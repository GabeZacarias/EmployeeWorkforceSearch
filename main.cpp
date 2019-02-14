
#include"EmployeeInfo.h"
#include"BinaryTree.h"
#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

int main()

{

    int num = 0;
    char quit = 'y';
    BinaryTree<EmployeeInfo> tree;   // create a BinaryTree object


    EmployeeInfo wkr1(1021, "John Williams"); // put data into object
        tree.insertNode(wkr1);   // put object into tree
    EmployeeInfo wkr2(1057, "Bill Witherspoon");
        tree.insertNode(wkr2);
    EmployeeInfo wkr3(2487, "Jennifer Twain");
        tree.insertNode(wkr3);
    EmployeeInfo wkr4(3769, "Sophia Lancaster");
        tree.insertNode(wkr4);
    EmployeeInfo wkr5(1017, "Debbie Reece");
        tree.insertNode(wkr5);
    EmployeeInfo wkr6(1275, "George McMullen");
        tree.insertNode(wkr6);
    EmployeeInfo wkr7(1899, "Ashley Smith");
        tree.insertNode(wkr7);
    EmployeeInfo wkr8(4218, "Josh Plemmons");
        tree.insertNode(wkr8);

    while (quit == 'y' || quit == 'Y')
    {
    cout << endl << "Here is the workforce:\n\n";
        tree.displayInOrder();

    cout << "Enter the employee number: ";
        cin >> num;
        cout << endl;
        EmployeeInfo search;
        search.setEmployeeID(num);
        EmployeeInfo *ptr = tree.searchNode(search);

    if (ptr)
        cout << "Employee was found:\n" << *ptr;

    else
        cout << "That employee was not found.\n\n";

    cout << endl << endl << "Enter 'Y' to compute another search: ";
    cin >> quit;

    if (quit == 'y' || quit == 'Y')
        num = 0;
        system("CLS");
    }

    return 0;

}
