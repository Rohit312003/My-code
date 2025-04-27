#include <stdio.h>
#define MAXSIZE 100

struct stack
{
    int num[MAXSIZE];
    int current;
};
void intialize(struct stack *s)
{
    s->current = 0;
    for (int i = 0; i < MAXSIZE; i++)
    {
        s->num[i] = 0;
    }
}

void push(struct stack *s, int num)
{

    s->num[s->current] = num;
    s->current += 1;
}

int top(struct stack *s)
{

    if (s->current > 0)
    {
        return s->num[s->current - 1];
    }
    return -1;
}

void pop(struct stack *s)
{

    if (s->current > 0)
    {
        int temp = s->num[s->current - 1];
        s->num[s->current - 1] = 0;
        s->current -= 1;
    }

    return;
}

void printt(struct stack *s)
{

    for (int i = 0; i < (s->current); i++)
    {

        printf("%d ", s->num[i]);
    }
    printf("\n");
}

int main()
{
    struct stack s;
    intialize(&s);
    push(&s, 1);
    push(&s, 5);
    push(&s, 2);
    pop(&s);
    printt(&s);
    push(&s, 3);
    push(&s, 8);
    printf("%d \n", top(&s));
    push(&s, 1);
    pop(&s);
    printt(&s);

    return 0;
}
