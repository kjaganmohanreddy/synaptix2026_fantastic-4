#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
} *start = NULL, *end = NULL;
void create_list()
{
    int value;
    struct node *newnode;
    printf("Enter values (-999 to stop):\n");
    while (1)
    {
        scanf("%d", &value);
        if (value == -999)
            break;
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = value;
        newnode->link = NULL;
        if (start == NULL)
            start = end = newnode;
        else
        {
            end->link = newnode;
            end = newnode;
        }
    }
}
void insert_begin(int value)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
	newnode->link = NULL;
    if (start == NULL) {
        start = end = newnode;
    }
    else {
        newnode->link = start;
        start = newnode;
    }
}
void insert_end(int value)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->link = NULL;
    if (start == NULL)
        start = end = newnode;
    else {
        end->link = newnode;
        end = newnode;
    }
}
void insert_after_value(int newvalue, int key)
{
    struct node *newnode, *ptr;
    if (start == NULL){
        printf("List is empty\n");
        return;
    }
    ptr = start;
    while (ptr->data != key)
        ptr = ptr->link;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = newvalue;
    newnode->link = NULL;
    newnode->link = ptr->link;
    ptr->link = newnode;
}
void delete_begin()
{
    struct node *temp;
    if (start == NULL)
    {
        printf("List is empty\n");
        return;
    }
    temp = start;
    start = start->link;
    free(temp);
    if (start == NULL)
        end = NULL;
}
void delete_end()
{
    struct node *temp, *prev;
    if (start == NULL)
    {
        printf("List is empty\n");
        return;
    }
    prev = start;
    temp = start->link;
    while (temp->link != NULL)
    {
        prev = temp;
        temp = temp->link;
    }
    prev->link = NULL;
    end = prev;
    free(temp);
}
void delete_by_value(int key)
{
    struct node *temp, *ptr = start;
    if (start == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while (ptr->data != key)
    {
        temp = ptr;
        ptr = ptr->link;
    }
    temp->link = ptr->link;
    free(ptr);
    
        if (temp == NULL) {
        printf("Value %d not found\n", key);
        return;
    }
}
void display() {
        struct node *temp;
    if (start == NULL)
    {
        printf("List is empty\n");
        return;
    }
    temp = start;
    printf("Linked List: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}
int main()
{
    int choice, value, key;
    while (1)
    {
        printf("\n--- MENU ---\n");
        printf("0.Create List\n");
        printf("1.Insert Begin\n");
        printf("2.Insert End\n");
        printf("3.Insert After Value\n");
        printf("4.Delete Begin\n");
        printf("5.Delete End\n");
        printf("6.Delete By Value\n");
        printf("7.Display\n");
        printf("8.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
         switch (choice)
        {
        case 0:
            create_list();
            break;
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            insert_begin(value);
            break;
        case 2:
            printf("Enter value: ");
            scanf("%d", &value);
            insert_end(value);
            break;
        case 3:
            printf("Enter new value and existing value: ");
            scanf("%d%d", &value, &key);
            insert_after_value(value, key);
            break;
        case 4:
            delete_begin();
            break;
        case 5:
            delete_end();
            break;
        case 6:
            printf("Enter value to delete: ");
            scanf("%d", &key);
            delete_by_value(key);
            break;
        case 7:
            display();
            break;
        case 8:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}
