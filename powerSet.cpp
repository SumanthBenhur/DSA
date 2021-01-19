vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string> powerSet;
		    int len = s.length();
		    for(int i = 0; i<(1<<len); i++){
		        int temp = i, count=0;
		        string x = "";
		        while(temp){
		            if(temp&1) x+=s[count];
		            count++;
		            temp = temp>>1;
		        }
		        if(x.length())
		            powerSet.push_back(x);
		        
		    }
		    sort(powerSet.begin(), powerSet.end());
		    return powerSet;
		}