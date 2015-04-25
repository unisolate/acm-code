#include<stdio.h>
#include<string.h>
int main()
{
	int i,j,temp,flag=1,m[50],n[50];
	char text[200],code[200];
	memset(m,0,sizeof(m));
	memset(n,0,sizeof(n));
	scanf("%s",code);
	scanf("%s",text);
	for(i=0;i<strlen(text);i++)
		m[text[i]-'A']++;
	for(i=0;i<strlen(code);i++)
		n[code[i]-'A']++;
	for(i=0;i<30;i++)
		for(j=i+1;j<26;j++)
			if(m[i]<m[j])
			{
				temp=m[i];
				m[i]=m[j];
				m[j]=temp;
			}
	for(i=0;i<30;i++)
		for(j=i+1;j<26;j++)
			if(n[i]<n[j])
			{
				temp=n[i];
				n[i]=n[j];
				n[j]=temp;
			}
	for(i=0;i<30;i++)
		if(m[i]!=n[i])
			flag=0;
	if(flag)
		printf("YES");else
		printf("NO");
	return 0;
}