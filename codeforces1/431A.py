a,b,c,d=map(int,raw_input().split())
s=raw_input()
p=0
for i in s:
	if i=='1':p+=a
	if i=='2':p+=b
	if i=='3':p+=c
	if i=='4':p+=d
print p