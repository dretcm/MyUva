/* 8851194 10258 Contest Scoreboard Accepted C++ 0.008 2011-05-16 12:41:15 */
#include<stdio.h>
#define SOLVED -2147483647 
#define MAX_PENALTY 2147483647
#define SWAP(x,y) { int temp=x; x=y; y=temp; }
struct person{
	int number;
	int solved;
	int penalty;
	int try_solve[10];
};
void SWAP_obj(struct person *x,struct person *y){
	int i;
	SWAP((*x).number,(*y).number);
	SWAP((*x).penalty,(*y).penalty);
	SWAP((*x).solved,(*y).solved);
	for(i=0;i<10;i++)
		SWAP((*x).try_solve[i],(*y).try_solve[i]);
}
void initial(struct person people[]){
	int i,j;
	for(i=0;i<100;i++){
		people[i].number=0;
		people[i].penalty=0;
		people[i].solved=0;
		for(j=0;j<10;j++)
			people[i].try_solve[j]=0;
	}
}
int main(){
	bool first=true;
	int n,i,j,k,l;
	char str[20];
	scanf("%d",&n);
	(void) getchar();
	gets(str);	
	for(i=1;i<=n;i++){		
		struct person people[100];	
		initial(people);
		char c;
		int number,problem,time;
		int index;			
		index=0;
		while(true){
			if(!gets(str)) break;
			if(str[0]=='\0') break; 
			sscanf(str,"%d%d%d %c",&number,&problem,&time,&c);
			for(j=0;j<index;j++)
				if(number==people[j].number){
					if(c=='I'){
						people[j].try_solve[problem]++;						
					}
					else if(c=='C'&&people[j].try_solve[problem]>=0){
						people[j].solved++;
						people[j].penalty+=time+people[j].try_solve[problem]*20;
						people[j].try_solve[problem]=SOLVED;						
					}
					break;
				}
			if(j>=index){
				if(c=='I'){
					people[index].try_solve[problem]++;
					people[index].number=number;
				}
				else if(c=='C'&&people[index].try_solve[problem]>=0){
					people[index].number=number;
					people[index].solved++;
					people[index].penalty+=time+people[j].try_solve[problem]*20;
					people[index].try_solve[problem]=SOLVED;					
				}
				else
					people[index].number=number;
				index++;
			}
		}
		int max_solve;
		for(j=0;j<index;j++)
			for(k=j+1;k<index;k++)			
				if(people[j].solved<people[k].solved) // 最大解題數
					SWAP_obj(&people[j],&people[k]);
		max_solve=people[0].solved;
		while(max_solve>=0){
			for(j=0;j<index;j++)
				for(k=j+1;people[k].solved==max_solve&&people[j].solved==max_solve&&k<index;k++)			
					if(people[j].penalty>people[k].penalty) // 最少懲罰時間
						SWAP_obj(&people[j],&people[k]);			
			max_solve--;
		}
		j=0;
		while(j<index){			
			for(l=j;people[j].solved==people[l].solved&&people[j].penalty==people[l].penalty&&l<index;l++);
			for(;j<l;j++)
				for(k=j+1;k<l;k++)
					if(people[j].number>people[k].number)
						SWAP_obj(&people[j],&people[k]);	
		}
		if(first)
			first=false;
		else
			putchar('\n');
		for(j=0;j<index;j++)
			printf("%d %d %d\n",people[j].number,people[j].solved,people[j].penalty);		
	}
	return 0;
}
