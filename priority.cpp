//prog 6.1
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

struct node
{
	int priority;
	int info;
	struct node *link;
};
class Priority_Queue
{
    private:
        node *frnt;
    public:
        Priority_Queue()
        {
            frnt = NULL;
        }
        void inst(int item, int priority)
        {
            node *tmp, *q;
            tmp = new node;
            tmp->info = item;
            tmp->priority = priority;
            if (frnt == NULL || priority < frnt->priority)
            {
                tmp->link = frnt;
                frnt = tmp;
            }
            else
            {
                q = frnt;
                while (q->link != NULL && q->link->priority <= priority)
                    q=q->link;
                tmp->link = q->link;
                q->link = tmp;
            }
        }
        void del()
        {
            node *tmp;
            if(frnt == NULL)
                cout<<"Queue Underflow\n";
            else
            {
                tmp = frnt;
                cout<<"Deleted item is: "<<tmp->info<<endl;
                frnt = frnt->link;
                free(tmp);
            }
        }
        /*
         * Print Priority Queue
         */
        void display()
        {

         node *ptr;
            ptr = frnt;
            if (frnt == NULL)
                cout<<"Queue is empty\n";
            else
            {	cout<<"Queue is :\n";
                cout<<"Priority       Item\n";
                while(ptr->link != NULL)
                {
                   ptr = ptr->link;
                }
                 cout<<ptr->priority<<"                 "<<ptr->info<<endl;

            }
        }
};
int main()
{
    int choice, item, priority;
    Priority_Queue pq;
    do
    {
        cout<<"1.Insert\n";
        cout<<"2.Delete\n";
        cout<<"3.Display\n";
        cout<<"4.Quit\n";
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Input the item value to be added in the queue : ";
            cin>>item;
            cout<<"Enter its priority : ";
            cin>>priority;
            pq.inst(item, priority);
            break;
        case 2:
            pq.del();
            break;
        case 3:
            pq.display();
            break;
        case 4:
            break;
        default :
            cout<<"Wrong choice\n";
        }
    }
    while(choice != 4);
    return 0;
}
