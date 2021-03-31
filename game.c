#include <stdio.h>      
#include <stdlib.h> 
#include <stdbool.h>


// initialize board globally 
char board[3][3] = { 
		 {' ', ' ', ' '}, 
		 {' ', ' ', ' '},
		 {' ', ' ', ' '}  
};      

int player = 1 ;  
bool game = true ;  
int move_count = 0 ;

void clearScreen() {  
    system("cls") | system("clear"); 
}     

void printBoard()  {           
    // instructional board  
    printf("\t\t  1 |  2 | 3  \n");
    printf("\t\t--------------\n");
    printf("\t\t  4 |  5 | 6  \n");
    printf("\t\t--------------\n");
    printf("\t\t  7 |  8 | 9  \n\n");

   for (int i = 0; i <3 ; ++i) 
   {     

   	printf("\t\t"); 
	for (int j = 0; j <3; ++j)
	    {
	      printf(" %c |" , board[i][j]);  
	    }      

   	printf("\n"); 
	if ( i == 1 || i == 0  ) {  
	printf("\t\t--------------"); 
	} 

   	printf("\n");
   } 

}

bool checkWinner( char symbol  , int player ) {    

    for (int i = 0 ; i <= 2 ; ++i ) {   
        int horizontal = 0 ; int vertical = 0 ; int diagonal = 0 ; int anti_diagonal = 0 ;   
	for ( int j = 0 ; j <= 2 ; ++j ) {     
    	    //horizontal  
	    if (board[i][j] == symbol) {   
		horizontal += 1 ; 
	    } 
	    //vertical 
	    if (board[j][i] == symbol ) {  
		vertical += 1 ; 
	    }  
	    // diagonal  
	    if (board[j][j] == symbol ) {  
		diagonal += 1 ; 
	    }     
	    //anti diagonal 
	    if (board[j][2-j] == symbol ) {  
		anti_diagonal += 1 ; 
	    }   

	    }  

        if (horizontal == 3 || vertical == 3 || diagonal == 3 || anti_diagonal == 3) {      
	    printf("Congratulations ! Player %d [%c] You Won The Game ! \n " , player , symbol ) ;
	    exit(0);
	    return true ;  
        }   
       
    }  
    return false ;
}  


int move(int n , char symbol , int player ){            
    clearScreen();

    if ( n > 0 & n < 4 ) {   
	if (board[0][n-1] == ' ') {   
	    board[0][n - 1] = symbol; 
	    move_count += 1  ; 
	} 
	else {
	    printf("\t\tinvalid input \n\t\tPls try again \n\n " );    
	    printBoard();
	    return false  ; 
       	}   
    }  

    else if ( n > 3 & n < 7 ) {   
	if (board[1][ abs(6-(n+2)) ] == ' ') {   
	    board[1][ abs(6-(n+2)) ] = symbol;  
	    move_count += 1 ; 
	} 
	else {  
	    printf("\t\tinvalid input \n\t\tPls try again \n\n " );    
	    printBoard();
	    return false  ; 
       	}   
    }  

    else if ( n > 6 & n < 10 ) {    
	if (board[2][abs(9-(n+2))] == ' ' ) {  
	    board[2][abs(9-(n+2))] = symbol; 
	    move_count += 1 ; 
	} 
	else {   
	    printf("\t\tinvalid input \n\t\tPls try again \n\n " );    
	    printBoard();
	    return false ; 
	}
    }   

    printBoard();   
   
    checkWinner(symbol , player ) ;

    return true  ;

}   

int main()  {
   /* my first program in C */
   printf("\t      Tic Tac Toe in C :) \n \n");  
   printf("\t   Player 1 = X | Player2 = O  \n \n" ) ;    


   // print the board 
   printBoard(); 


   // game loop         
   while(game) { 
	if (player == 1 ) {     
            int p1_input ; 
	    printf("Player 1 turn [X] : ");  
 	    scanf("%d" , &p1_input );  
	    bool is_move_valid = move(p1_input, 'X' , player ) ;      
	    if (is_move_valid == true  ) {  
	        player = 2  ;
	    }  
	    else {  
		player = 1  ;
	    } 
	} 
	else {  
            int p2_input ;  
	    printf("Player 2 turn [O] : ");             
	    scanf("%d" , &p2_input);  
	    int is_move_valid = move(p2_input , 'O' , player) ;     
	    if (is_move_valid == true  ) {  
		player = 1 ;
	    }  
	    else {  
		player = 2 ;
	    }   
	}  
        if (move_count == 9 ) {  
	    printf("Game Ended!! Final Result is Draw !! \nRun the program to play the game again " ) ; 
	    exit(0);
	} 	
        
	} 

   return 0;
}

