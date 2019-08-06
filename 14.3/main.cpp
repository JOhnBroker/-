#include <iostream>
#include <cstring>
#include "Worker.h"
#include "QueueTP.h"
const int SIZE = 5;

int main() {
    using std::cin;
    using std::cout;
    using std::endl;

    QueueTP<Worker *> lolas(SIZE);              //Worker * lolas[SIZE];

    int ct;
    for (ct = 0; ct < SIZE; ct++)
    {
        char choice;
        cout << "Enter the employee category:\n"
             << "w: waiter  s: singer  "
             << "t: singing waiter  q: quit\n";
        cin >> choice;
        while (strchr("wstq", choice) == NULL)
        {
            cout << "Please enter a w, s, t, or q: ";
            cin >> choice;
        }
        if (choice == 'q')
            break;
        switch(choice)
        {
            case 'w':   lolas.Push(new Waiter);
                break;
            case 's':   lolas.Push(new Singer);
                break;
            case 't':   lolas.Push(new SingingWaiter);
                break;
        }
        cin.get();
        lolas.rear()->Set();
    }

    cout << "\nHere is your staff:\n";
    int i;
    for (i = 0; i < ct; i++)
    {
        cout << endl;
        lolas.front()->Show();
        lolas.Push(lolas.front());
        lolas.Pop();
    }
    for (i = 0; i < ct; i++)
    {
        delete lolas.front();
        lolas.Pop();
    }
    cout << "Bye.\n";
    // cin.get();
    // cin.get();
    return 0;
}