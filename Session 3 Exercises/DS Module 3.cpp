#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Note: printf("\e[1;1H\e[2J"); used to clear the console using regex method

struct node{
    long long int rollNo; //attribute 1
    char name[100]; //attribute 2
    float grade; //attribute 3
    struct node* link; 
}; 

struct node *head = NULL, *tail = NULL; 

void header(){
    printf("\t\t\t\tMade by\n\t\t\t\tPristian Budi Dharmawan - 2501983105\n");
    printf("\t\t\t\t\t\t\tVer. 2.03.10");
}

void displayList(){
    //Validating the list to be displayed
    if(tail == NULL){ 
        printf("404 NOT FOUND\nKindly Input The Data First:)\n\n");
        printf("Press ENTER to continue..."); getchar();
        printf("\e[1;1H\e[2J"); 
    } else{ 
        printf("\t\t----STUDENT LIST----\n");
        printf("No.\t\t\t| Name\t\t| Grade\n");
        printf("------------------------------------------------\n");
        
        struct node *display = tail->link;

        do{
            printf("%02lld\t\t| %s\t\t| %.2f\n", display->rollNo, display->name, display->grade);
            display = display->link;
        } while(display != tail->link);

        printf("\n\t\t=====This is EOF=====\n\n"); 
        printf("Press ENTER to continue..."); getchar(); 
        printf("\e[1;1H\e[2J");
    } 
}

void displayData(){
    //Validating the list to be displayed
    if(tail == NULL){ 
        printf("404 NOT FOUND\nKindly Input The Data First:)\n\n");
        printf("Press ENTER to continue..."); getchar();
        printf("\e[1;1H\e[2J"); 
    } else{ 
        printf("\t\t----STUDENT LIST----\n");
        printf("No.\t\t\t| Name\t\t| Grade\n");
        printf("------------------------------------------------\n");
        
        struct node *display = tail->link;

        do{
            printf("%02lld\t\t| %s\t\t| %.2f\n", display->rollNo, display->name, display->grade);
            display = display->link;
        } while(display != tail->link);
    } 
}

struct node *newNode(){
    struct node *inputNode = (struct node *) malloc(sizeof(struct node));
    scanf("%lld", &inputNode->rollNo, printf("Enter Student ID: ")); fflush(stdin);
    scanf("%[^\n]", &inputNode->name, printf("Enter Student Name: ")); fflush(stdin);
    scanf("%f", &inputNode->grade, printf("Enter Student Grades: ")); fflush(stdin);
    inputNode->link = NULL;
    return inputNode;
}

void insertBeg(){
    struct node *insert_beg = newNode();

    //Checking the list
    if(tail != NULL){
        insert_beg->link = tail->link;
        tail->link = insert_beg;
    } else{
        insert_beg->link = insert_beg;
        tail = insert_beg;
    } 
    
    printf("\n\t\t===Input data Succeeded!===\n\n");
    printf("Press ENTER to continue..."); getchar();
    printf("\e[1;1H\e[2J"); 
}

void insertEnd(){
    struct node *insert_end = newNode();
    
    //Inverse Package Queue
    if(tail != NULL){
        insert_end->link = tail->link;
        tail->link = insert_end;
        tail = insert_end;
    } else{
        insert_end->link = insert_end;
        tail = insert_end;
    }

    printf("\n\t\t===Input data Succeeded!===\n\n");
    printf("Press ENTER to continue..."); getchar();
    printf("\e[1;1H\e[2J"); 
}

void insertafterGiven(){
    struct node *temp = tail->link, *insert_given;
    displayData(); printf("\n");

    int pos;

    scanf("%d", &pos, printf("Insert Position (After): ")); fflush(stdin);
    insert_given = newNode();
    insert_given->link = NULL;

    while(pos > 1){
        temp = temp->link;
        pos--;
    } insert_given->link = temp->link;
    temp->link = insert_given;

    if(temp == tail){
        tail = tail->link;
    }

    printf("\n\t\t===Input data Succeeded!===\n\n");
    printf("Press ENTER to continue..."); getchar();
    printf("\e[1;1H\e[2J"); 
}

void delBeg(){
    struct node *delete_beg;

    //Validating and deleting head
    if(tail == NULL){
        printf("404 NOT FOUND\nKindly Input The Data First:)\n\n");
        printf("Press ENTER to continue..."); getchar();
        printf("\e[1;1H\e[2J"); 
    } else{
        delete_beg = tail->link;
        tail->link = delete_beg->link;
        free(delete_beg);

        printf("\n\t\t===Delete data Succeeded!===\n\n");
        printf("Press ENTER to continue..."); getchar();
        printf("\e[1;1H\e[2J"); 
    }
}

void delEnd(){
    struct node *delete_end;

    //Validating and deleting tail
    if(tail == NULL){
        printf("404 NOT FOUND\nKindly Input The Data First:)\n\n");
        printf("Press ENTER to continue..."); getchar();
        printf("\e[1;1H\e[2J"); 
    } else{
        delete_end = tail->link;
        while(delete_end->link != tail){
            delete_end = delete_end->link;
        } delete_end->link = tail->link;
        tail = delete_end;

        printf("\n\t\t===Delete data Succeeded!===\n\n");
        printf("Press ENTER to continue..."); getchar();
        printf("\e[1;1H\e[2J"); 
    }
}

void delGiven(){
    struct node *delete_given = tail->link, *temp;
    int position;
    
    if(tail == NULL){
        printf("404 NOT FOUND\nKindly Input The Data First:)\n\n");
        printf("Press ENTER to continue..."); getchar();
        printf("\e[1;1H\e[2J"); 
    } else{
        displayData(); printf("\n");
        scanf("%d", &position, printf("Position: ")); fflush(stdin);

        //Connecting Given to Queue
        for(int i=0; i <= position - 1; i++){
            delete_given = delete_given->link;
        } temp = delete_given->link;
        delete_given->link = temp->link;
        free(temp);

        printf("\n\t\t===Delete data Succeeded!===\n\n");
        printf("Press ENTER to continue..."); getchar();
        printf("\e[1;1H\e[2J"); 
    }
}

int main(){
    int opt;
    printf("\n");
    do{
        header();
        printf("\n\n\t\t=========MENU=========\n\n\n");
        printf("Student data organizer program\n");
        printf("------------------------------\n");
        printf("1. Display the list\n"); //Requirement 5
        printf("2. Add a node at the beginning\n"); //Requirement 1
        printf("3. Add a node at the end\n"); //Requirement 2
        printf("4. Add a node at given node\n"); //Extra Insertion
        printf("5. Delete a node from the beginning\n"); //Requirement 3
        printf("6. Delete a node from the end\n"); //Requirement 4
        printf("7. Delete a node from a given node\n"); //Extra Deletion
        printf("0. EXIT\n");
        scanf("%d", &opt, printf("Input your choice: ")); fflush(stdin);
        switch (opt){
        case 1:
            printf("\e[1;1H\e[2J"); 
            displayList(); break;
        case 2:
            printf("\e[1;1H\e[2J"); 
            insertBeg(); break;
        case 3:
            printf("\e[1;1H\e[2J"); 
            insertEnd(); break;
        case 4:
            printf("\e[1;1H\e[2J"); 
            insertafterGiven(); break;
        case 5:
            printf("\e[1;1H\e[2J"); 
            delBeg(); break;
        case 6:
            printf("\e[1;1H\e[2J"); 
            delEnd(); break;
        case 7:
            printf("\e[1;1H\e[2J"); 
            delGiven(); break;
        default:
            printf("\e[1;1H\e[2J"); 
            printf("\n\nThere's no menu no %d\n\n", opt);
            break;
        }
    } while(opt != 0); 
    
    printf("\e[1;1H\e[2J"); 
    printf("Thankyou");
    
    return 0;
}