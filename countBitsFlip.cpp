int countBitsFlip(int a, int b){
    
    // Your logic here
    a =  a^b;
    int count = 0;
    while(a){
        count++;
        a = a&(a-1);
    }
    return count;
}