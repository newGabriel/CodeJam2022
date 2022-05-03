memo = {}
def maxQ(q,m,i,f):
	if (i,f) in memo:
		return memo[(i,f)]
	if len(q)==0:
		return 0
	t1=0
	t2=0
	if q[0]>=m:
		t1=1
	if q[-1]>=m:
		t2=1
	t1+=maxQ(q[1:],max(m,q[0]),i+1,f)
	t2+=maxQ(q[:-1],max(m,q[-1]),i,f-1)
	memo[(i,f)] = max(t1,t2)
	return memo[(i,f)]


t = int(input())
for k in range(1,t+1):
	memo = {}
	n = int(input())
	l = input()
	l = l.split()
	q = []
	for i in l:
		q.append(int(i))
	tot = maxQ(q,0,0,n);
	print('Case #'+str(k)+":",tot)
