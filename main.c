nclude <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

/* global data */
typedef struct dlink  /* double linked list for text */
{ char input;  
    struct dlink *prev;  
      struct dlink *next;
}dnode;

dnode *begin, *cursor, *new;
const char csor='|';  /* cursor character */
const char LF=0xa;  /* line feed character */

void print_String(){
      dnode *cur = begin;
          while(cur!=NULL){
                    printf("%c",cur->input);
                            cur=cur->next;
                                }
}

void move_Left() {
      dnode *cur = cursor;
          if(cur->prev != NULL){
                    cur = cur->prev;
                            cursor->input = cur->input;
                                    cur->input = csor;
                                            cursor = cur;
                                                }
                  print_String();
}

void move_Right(){
      dnode *cur = cursor;
          if(cur->next != NULL){
                    cur = cur->next;
                            cursor->input = cur->input;
                                    cur->input = csor;
                                            cursor = cur;
                                                }
              print_String();
}

char cget()  // get command character, skip LF
{ char c;
    do {c=getchar();} while(c==LF);  // skip LFs
      return c;
}


void ins_Char(){
    dnode *newNextNode = (dnode*)malloc(sizeof(dnode));  
      char c = cget();
        newNextNode->input = c;
          newNextNode->prev = cursor;
            newNextNode->next = cursor->next;
              cursor->next= newNextNode;
                print_String();
}

void ini_String(){    
    new=(dnode*)malloc(sizeof(dnode));
      new->prev = NULL;
        new->next = NULL;
          begin=new;
            cursor = new;
                char c;
                    while(1) {
                              c = getchar();
                                      if(c=='\n')
                                                    break;
                                              new->input = c;
                                                      dnode *temp= (dnode*) malloc(sizeof (dnode));
                                                              new->next = temp;
                                                                      temp->prev = new;
                                                                              temp->next = NULL;
                                                                                      new = temp;
                                                                                          }
                            new->input = csor;
                                    cursor= new;
}

void del_Char(){
      if(cursor->next != NULL){
                dnode *delNode = cursor->next;
                        cursor->next = delNode->next;
                                free(delNode);
                                        print_String();
                                            }
}


void menu()  /*Menu choice and switch function*/
{ char option;
    printf("\nEnter option (v=view l=left r=right i=ins d=del x=exit): ");
      do
          { 
                option=(char)tolower( (int)cget() );
                    switch(option)
                          { case 'v': print_String();break;
                                  case 'l': move_Left(); break;
                                                  case 'r': move_Right(); break;
                                                                  case 'i': ins_Char(); break;
                                                                                  case 'd': del_Char(); break;
                                                                                                  case 'x': printf("Exit\n"); break;
                                                                                                                  default: printf("Invalid option=%x\n", option);
                                                                                                                               }
                      } while (option!='x');
}



int main()
{ 
    printf("Enter initial string: ");
      ini_String();
        menu();  /* command Entry menu loop */
          return(EXIT_SUCCESS);
} /*End main*/
