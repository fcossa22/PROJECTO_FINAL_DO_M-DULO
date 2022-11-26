#include <iostream>

#define MAX 100 // Definindo a capacidade da fila

int QUEUE[MAX],front=-1, rear=-1, customer_num=100, senha_chamada, proxima_senha=-1, proximo_cliente;

void enqueue(int QUEUE[],int customer_num) //Adicionando Fila
{
    if(rear==-1) //Para adicionar o primeiro elemento  na Fila
    {
        front=rear=0;
        QUEUE[rear]=customer_num;
    }
    else if(rear==MAX-1) //Se a FILA  estiver cheia
    {
        printf("\nWaiting List is full.\n");
        return;
    }
    else //Se estiver adcionando um elemento numa FILA que ja contenha um elemento
    {
        rear++;
        QUEUE[rear]=customer_num;
    }
    printf("\nPor favor aguarde ate que o seu numero seja chamado. Obrigado!");
    printf("\n\n");
}

//Para gerar um numero na FILA e adicionar na FILA
void generate_customer_num() 
{
	customer_num = customer_num+1;
	printf("\nVoce e o Cliente Numero: %i",customer_num + 1);
    senha_chamada = customer_num + proxima_senha;
    proximo_cliente = customer_num;
    printf("\nProximo Cliente da Fila: %i", proximo_cliente);
    printf("\nSenha chamada: %i", senha_chamada);
	printf("\n");
	enqueue(QUEUE,customer_num);
}

//Para Ver a FILA
void view(int QUEUE[])
{    
    if(rear==-1) // A FILA esta vazia
	{
		printf("\nWaiting Line is Empty.");
		printf("\n\n");
		return; 
	}
	
	//Se a FILA contem um elemento
	printf("\nWaiting Line:\n");
    for(int i=front;i<=rear;i++)
    { 
		printf("%i\n",QUEUE[i]);
	}
	printf("\n");
 
}

void update(int QUEUE[]) //Para remover um elemento da FILA
{
    //Se a FILA esta vazia
    if(front==-1)
    {
        printf("\nWaiting Line is Empty.");
        printf("\n\n");
        return;
    }
    else if(front==rear) //Para remover o primeiro elemento da lista antes que a FILA fique vazia
    {
        customer_num=QUEUE[front];
        front=rear=-1;
    }
    else //Para removeer o primeiro elemento da FILA e REAJUSTAR a FILA
    {
        customer_num=QUEUE[front];
        front++;
    }
    printf("\nNow Serving Customer Number: %i.",customer_num);
    printf("\n\n");
}



int main(){

   /*	A opcao 'Cliente' serve para Gerar uma senha e para saber que cliente esta seguindo assim como para saber quem esta sendo atendido
		O 'admin' e para vizualizar a FILA, remover os clientes da FILA*/
	start:
	int choice_admin, choice_customer, start;
	printf("========== Welcome to KingsMan Store! ==========\n\n");
	printf("1.Cliente \n2.Admin\n\n");
	scanf("%i",&start);
 	
	 //customer
	 if (start==1)
 	{
 		printf("\n========== Tenha Um otimo dia Dear Customer! ==========");
		
		//genreate a number and automatically adds it to the queue
		generate_customer_num();
		printf("\n\n");
		
		goto start;	
	}
	
	//admin account
	else if (start==2)	
	{
		printf("\n****Good day, Admin!*****\n");
		while(1)
		{
			printf("1.View Waiting Line\n2.Update 'Now Serving' number\n3.Quit\n\n");
			printf("what would you like to do? : ");	scanf("%i",&choice_admin);
		
			switch(choice_admin)
			{
				case 1:
				{
					//view the elements on the queue
					view(QUEUE);
					break;
				}
				case 2:
				{
					//remove the topmost element on the queue
					update(QUEUE);
					view(QUEUE);
					break;
				}
				case 3:
				{
					//to exit the 'admin' account
					printf("\n");
					goto start;
				}
				default:
				{
					printf("Invalid input.");
					printf("\n\n");
				}
			}
		}
	}
	else
	{
		printf("Invalid input. Plese Try again.");
		printf("\n\n");
		goto start;
	}
    return 0;
}
