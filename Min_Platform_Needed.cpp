int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	sort(arr, arr+n);
    	sort(dep, dep+n);
    	
    	int total_platform_needed = 0;
    	int max_plat = 0;
    	
    	int i=0, j=0;
    	while(i!=n && j!=n){
    	    if(arr[i]<=dep[j]){
    	        max_plat++;
    	        i++;
    	    }
    	    
    	    else if(dep[j]<arr[i]){
    	        max_plat--;
    	        j++;
    	   }
    	   
    	   total_platform_needed = max(total_platform_needed, max_plat); 
    	    
    	}
    	return total_platform_needed;
    }