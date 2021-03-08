bool cmp(Item a, Item b){
        
        double r1 = (double)a.value / a.weight;
        double r2 = (double)b.value / b.weight;
        return r1 > r2;
    }
    
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr, arr+n, cmp);
        int i=0; float result = 0;
        while(W>0){
            if(arr[i].weight <= W){
                result+=arr[i].value;
                W-=arr[i].weight;
            }
            
            else{
                result+=arr[i].value / W;
                W=0;
            }
            
            i++;
            
        }
        return result;
    }