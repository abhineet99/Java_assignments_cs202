
#include<bits/stdc++.h>
class compares
{
public:
	bool operator()(item A,item B) const
		{
			if(!A.getislab())
			return ((A.getnum())>(B.getnum()));
			else 
				return ((A.getarea())>(B.getarea()));
		}
};