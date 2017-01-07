#define MAXN 100

typedef struct stack{
 int data[MAXN];
 int top;
} stack;

//---------------------------------------------
int priority(char x)
{
   if(x == '(')
 return(0);
   if(x == '+' || x == '-')
 return(1);
   if(x == '*' || x == '/' || x == '%')
 return(2);
   return(3);
}
//---------------------------------------------
void init(stack *s)
{
   s->top=-1;
}
//---------------------------------------------
int empty2(stack *s)
{
    if(s->top==-1)
 return(1);
    else
 return(0);
}
//---------------------------------------------
int full(stack *s)
{
    if(s->top==MAXN-1)
 return(1);
    else
 return(0);
}
//---------------------------------------------
void push2(stack *s,char x)
{
  s->top=s->top+1;
  s->data[s->top]=x;
}
//---------------------------------------------
char pop2(stack *s)
{
   int x;
   x=s->data[s->top];
   s->top=s->top-1;
   return(x);
}
//---------------------------------------------
char top2(stack * s)
{
   return(s->data[s->top]);
}
//---------------------------------------------
