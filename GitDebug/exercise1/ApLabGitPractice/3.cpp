//in dige che code sammi bod :o

#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 200
long long arr[MAX_SIZE];

typedef struct alfa* alfaptr;

struct alfa {
    long long x;
    alfaptr next;
};

alfaptr rear = nullptr, front = nullptr;

void push(long long x)
{
    alfaptr node;
    node = (alfaptr)malloc(sizeof(struct alfa));
    node->x = x;
    if (!front)
    {
        front = node;
        rear = node;
    }
    else {
        node->next = front;
        front = node;
    }
}

void pop()
{
    alfaptr node = front;
    if (!front)
        printf("ERROR1");
    else if(front->next == nullptr)
    {
        rear = nullptr;
        free(front);
        front = nullptr;
    }
    else
    {
        front = front->next;
        free(node);
    }
}
void search(int x)
{
    alfaptr node = front;
    int counter = 0;
    while (node)
    {
        if (node->x == x)
        {
            printf("%d", counter);
            counter++;
        }
        node = node->next;
    }
    if(counter == 0)
        printf("ERROR2");
}

void rpop() {//pop last element
    alfaptr node = rear;
    while (node->next->next)
        node = node->next;
    free(rear);
    rear = node;
    node->next = nullptr;
}

void set()
{
    alfaptr node = front;
    for (int i = 0; i < MAX_SIZE && node; i++, node = node->next)
        arr[i] = node->x;
}

int size()
{
    alfaptr node = front;
    int count=0;
    while (node)
    {
        count++;
        node = node->next;
    }
    return count;
}

void show()
{
    if (front) {
        for (int i = 0; i < MAX_SIZE; i++)
            printf("%d ", arr[i]);
    }
    else
    {
        printf("ERROR3");
    }
}

int average()
{

    alfaptr node = front;
    int sum = 0, count=0;
    while (node) {
        sum += node->x;
        count++;
        node = node->next;
    }
    return sum / count;
}
//void is not valid in c++ for main function
int main()
{
    int cmd;
    long long int x;
    //always true loops are not good practice but whatever
    while (true)
    {
        scanf("%d", &cmd);
        switch (cmd)
        {
            case 1://push
                scanf("%lld", &x);
                push(x);
                break;
            case 2://pop
                pop();
                break;
            case 3://rpop
                rpop();
                break;
            case 4://search
                scanf("%lld", &x);
                search(x);
                break;
            case 5://set
                set();
                break;
            case 6://show
                show();
                break;
            case 7://size
                printf("%d", size());
                break;
            case 10:
                exit(0);
        }
    }
}