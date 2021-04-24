#include<stdio.h>
int end=0;
int board[10]={1,2,3,4,5,6,7,8,9};
int TicTacToe()
{
	int match[10]={4,9,2,3,5,7,8,1,6};
	printf("\t\t\t\tWelcome Friends\n");
	printf("\t\t\tPlay the Tic-Tac-Toe game\n");
	printf("\t\t\tChoose two players -1 and 11\n");
	while(!end) 
	{
       PrintBoard();
       end = CheckWin(11,match);  
       if(end) break;
       printf("Choose a box player -1 "); 
        while(1) {
          int ind; scanf("%d",&ind);
          if(ind>=1 && ind<=9) {
     	   if(board[ind-1]!= -1 && board[ind-1]!= 11) {
		    board[ind-1]=-1; break; }
		   else  {
		    printf("\nBox already occupied. Try another one\n");
           continue; }
	      }
	      else printf("\nNumber not in box, Try again\n");
        }
     
     PrintBoard();
     end = CheckWin(-1,match);
     if(end) break;
     printf("Choose a box player 11 ");
     while(1) {
         int ind; scanf("%d",&ind);
         if(ind>=1&&ind<=9) {
     	   if(board[ind-1]!= -1 && board[ind-1]!= 11) {
		     board[ind-1]=11; break; }
		   else  {
		      printf("\nBox already occupied. Try another one\n");
              continue; 	}
	     }
	     else printf("\nNumber not in box, Try again\n");
      }
   }
   return 0;	
}
int PrintBoard()
{
	printf("\n");
	printf(" %d | %d | %d\n",board[0],board[1],board[2]);
	printf("---|---|---\n");
	printf(" %d | %d | %d\n",board[3],board[4],board[5]);
	printf("---|---|---\n");
	printf(" %d | %d | %d\n",board[6],board[7],board[8]);
	printf("\n");
}
int CheckWin(int player,int MagicSquare[]) 
{ 
    int i,j,k;
    for(i=0;i<9;i++)
    {
      for(j=0;j<9;j++)
      {
        for(k=0;k<9;k++)
        {
          if(i!=j && j!=k && k!=i)
          {
            if (board[i] == player&&board[j] == player&&board[k] == player) 
              if(MagicSquare[i] + MagicSquare[j] + MagicSquare[k] == 15)
              {
                printf("Player, %d ,wins!\n",player);
                end=1;
                return 1;
              }
          } 
       }
      }
    } 
	int count=0;
    for(i=0;i<9;i++)
    {
      if(board[i]==-1 || board[i]==11) count += 1;
      if (count == 9) {
        printf("The game ends in a Tie\n"); 
        end=1;
      } 
    } 
    return 0;;
}
int main()
{
	TicTacToe();
	return 0;
}
