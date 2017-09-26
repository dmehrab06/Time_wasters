s=input()
s=list(s)
max_ans=-1
for i in range(len(s)):
	s1=list(s)
	cur_ans=0
	if s1[i]=="V":
		s1[i]="K"
	else:
		s1[i]=="V"
	for j in range(1,len(s1)):
		if s1[j]=="K" and s1[j-1]=="V":
			cur_ans+=1;
	max_ans=max(max_ans,cur_ans)
print(max_ans)
