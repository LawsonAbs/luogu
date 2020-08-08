#include <stdio.h>
#include <string.h>

/**
1.ȷ��Ѱ�ҵı߽�
2.���ݲ���Խ�� 
3.���Ĳ���http://www.cnblogs.com/549294286/p/3571604.html 
**/

int hashMap [36] ={false};//�����洢0-9��a-z֮����� 
char N1[11],N2[11];
int tag;
long long radix;//radix��ʾ���ǽ���
long long result ;
//typedef long long LL;
//LL inf = (1LL<<63 - 1); 

long long inf = ((long long)1<<63)-1;//long long�����ֵ2^63-1��ע������ 


//������������ȷ��������С�߽�  ----> Ϊ���գ���������Ϊlong long���� 
long long solveLowestBoundary(char str[]){
	int i ,length ;
	long long lowestBoundary = 1;//lowestBoundary��ʾ������С�ı߽� 
	length = strlen(str);
	for (i = 0;i<length;i++){
		if(str[i] <='9' && str[i] >='0'){
			hashMap[(str[i]-'0')] = true;//��Ҫע��������str[i]-'0' 
		}
		else if(str[i] <= 'z' && str[i] >= 'a'){
			hashMap[(str[i]-'a'+10)] = true;
		}
	}

	for(i = 0;i<35;i++){
		if(lowestBoundary <= i && hashMap[i] == true){		
			lowestBoundary = i + 1;//+1֮��ű�ʾ��С�Ľ��� ���൱�ڶ��ַ��е�left�� 
		}
	}
	return lowestBoundary;
} 


//���ַ���ת����ʮ���� 
long long convertTo10(char str[],long long radix,long long inf){
	int length = strlen(str);//����ַ����ĳ���
	int i ;
	long long sum = 0;//��ʾת�����ƺ�ĺ�---->ÿ������󶼵����㡾������ȷ��λ�á� 
	for	(i = 0;i<length;i++){
		if(str[i]<='9' && str[i]>=0){
			sum = ( sum * radix ) + str[i]-'0';
		}
		else if(str[i] <='z' && str[i]>='a'){
			sum = (sum * radix) + (str[i] - 'a' + 10) ;
		}
		
		//��Ϊ�ؼ���һ�� 
		if(sum <0 || sum > inf){//������߳���N1��ʮ���� 		
			return -1;
		}		
	}
	//printf("sumOf10 = %lld\n",sum);
	return sum;//�������Ĳ���ֵ 
} 

int cmp(char N2[],long long radix, long long t){
	int len = strlen(N2);
	long long num = convertTo10(N2,radix,t);
	if(num < 0)	return 1;//��� 
	//printf("t = %d\n",t); 
	if(t > num ) return -1;
	else if(t == num) return 0;//��ȣ�����0 
	else return 1;
}


//ʹ�ö��ַ��ҵ���һ��С��result�ĺ��ʽ��� 
long long selectRadix (long long left,long long right,long long t){	
	long long mid;		
	//printf("����t = %d\n",t);
	while(left <= right){
		mid = (left + right) / 2;
		int flag = cmp(N2,mid,t); 
	//	printf("flag = %d\n",flag); 
	//	printf("left = %lld,mid = %lld,right = %lld\n",left,mid,right); 				
		if(flag == 0){//����ý��Ƶ����ҵ��ˣ��򷵻ظý��� 
			return mid;
		}				
		else if(flag == -1 ){//��N1���������mid�������ת�� 
			left = mid + 1 ;
		}
		else{
			right = mid - 1;
		}	
	}	
	return -1 ;
}


int main(){
	
	scanf("%s %s %d %lld",N1,N2,&tag,&radix);	
	if(tag == 2){//Ϊ��ʹ��������������е�radix����N1�Ľ��ƣ� 
		char tempStr[11];
		strcpy(tempStr,N1);//�ݴ�N1�ַ�����ֵ 
		strcpy(N1,N2);
		strcpy(N2,tempStr); 
	}
	
	long long temp ;//temp�����洢���ַ����Ͻ� 
	 
	result = convertTo10(N1,radix,inf);
	temp = result;
	
	//printf("result = %lld\n",temp );
	
	long long lowestBoundary = solveLowestBoundary(N2);//ȷ�����Ƶ���С�߽� 
	
	//ȷ�����ַ����Ͻ���һ����С��׼ȷֵ 
	if(temp < lowestBoundary){
		temp = lowestBoundary;
	}
	
	if(selectRadix (lowestBoundary,temp,result) == -1){
		printf("Impossible\n");		
	}		
	else {
		printf("%lld\n",selectRadix (lowestBoundary,temp,result));		
	}
} 

/** 
s9jix hj 1 36

oj scb8j 2 36

10 aaaaaaaaaa 2 15

6 110 1 10

1 ab 1 2
 
32 20 1 10

0 0 1 34
5 5 1 10
*/