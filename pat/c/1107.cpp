#include <stdio.h>
#include <algorithm> 
using namespace std;

#define maxSize 1001

bool cmp(int a,int b){
	return a > b;
}

int people[maxSize];//统计人数 
int arr[maxSize][maxSize];//爱好 
 
int main(){
	int n,hobby,i,j,k; 
	scanf("%d",&n);//输入总人数
	int record = 0;//记录员 
	for(i = 1;i<= n;i++){ 
		people[i] = 0;//初始化为0
		scanf("%d:",&arr[i][0]);//输入爱好数目----->将爱好数目存储下来 
		for( j = 1;j <= arr[i][0] ; j++){//注意下标 
			scanf("%d",&hobby);//输入爱好
			arr[i][j] = hobby;
						
			for( k = 1; k< i;k++) {//检查每个输入数据是否之前输入过 
				for(int m = 1;m <= arr[k][0];m++ ) {
					if(arr[k][m] == hobby){
						record = k;
						break;//跳出循环 
					}					 
				}
				if(record) break;	//跳出循环			
			}
			if(record)	break;//跳出循环						
		}
		if(record == 0 )//如果没有相同的 
		{							
			people[i]++;
		}
		else{
			 
			people[record]++;//爱好相同的人数增加 
			record = 0;
		}
	}
	sort(people,people+n+1,cmp);//注意排序的数为n+1   且排完序之后，下标从0开始了 
	int count = 0;
	for(i = 0;i <= n;i++){
		if(people[i]!=0){
			count++;
		}
	}
	printf("%d\n",count);
	for( i = 0;i <= n;i++){		
		if(count>1 && people[i]>0)	printf("%d ",people[i]);
		else if(count == 1 && people[i]>0) 	printf("%d",people[i]);
		count--;
	}	
} 

/**
8
3: 2 7 10
1: 4
2: 5 3
1: 4
1: 3
1: 4
4: 6 8 1 5
1: 4

8
1: 2
1: 4
1: 3
1: 1
1: 5
1: 7
1: 6
1: 8

4
4: 4 2 3 11
2: 4 5
2: 6 5
3: 8 5 10
*/

/**
1.集合在动态的变化，才是本题的关键 
*/
