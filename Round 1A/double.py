def mini(s):
	if len(s)==0: return ""
	s1 = mini(s[1:])
	if s[0]+s[0]+s1<s[0]+s1:
		return s[0]+s[0]+s1;
	return s[0]+s1

t = int(input())
for k in range(1,t+1):
	s = input()
	s = mini(s)
	print(f"Case #{k}: {s}");

