int findPosition(int N) {
        // code here
        if(N==0) return -1;
        int pos = 0;
        while(N>0){
            pos++;
            if((N&1)== 1){
                N/=2;
                break;
            } 
            N/=2;
            
        }
        
        if(N!=0) return -1;
        return pos;
    }