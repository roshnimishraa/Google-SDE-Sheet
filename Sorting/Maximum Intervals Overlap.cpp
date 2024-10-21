Time Complexity: O(N*Log(N) )
Auxiliary Space: O(1)

class Solution{
	public:
	vector<int> findMaxGuests(int Entry[], int Exit[], int N)
	{
	   sort(Entry, Entry+n);
	   sort(Exit, Exit+n);
	   int guests_in = 1, max_guests = 1, time = Entry[0];
	   int i=1, j=0;
	   while(i<n && j<n)
	   {
	       if(Entry[i] <= Exit[j])
	       {
	           guests_in++;
	           
	           if(guests_in > max_guests)
	           {
	               max_guests = guests_in;
	               time = Entry[i];
	           }
	           i++; 
	       }
	       else{
	           guests_in++;
	           j++;
	       }
	   }
	   return 
	}

};
