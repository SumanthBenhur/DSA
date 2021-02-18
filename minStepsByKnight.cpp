struct node{
        int x;
        int y;
        int dist;
    };
    
    bool isValid(int x, int y, int N){
        if(x>=0 && x<N && y>=0 && y< N) return true;
        return false;
    }
    
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	    // Code here
	    KnightPos[0]--;
	    KnightPos[1]--;
	    TargetPos[0]--;
	    TargetPos[1]--;
	    
	    int visited[N][N]{0};
	    int x_moves[] = {-2, -2, -1, -1, 2, 2, 1, 1};
	    int y_moves[] = {1, -1, 2, -2, 1, -1, 2, -2};
	    queue<node> q;
	    q.push({KnightPos[0], KnightPos[1], 0});
	    visited[KnightPos[0]][KnightPos[1]]=1;
	    while(q.empty()==false){
	        node temp = q.front();
	        q.pop();
	        if(temp.x == TargetPos[0] && temp.y == TargetPos[1]) 
	            return temp.dist;
	        for(int i=0; i<=8; i++){
	            int next_x = temp.x + x_moves[i];
	            int next_y = temp.y + y_moves[i];
	            
	            if(!visited[next_x][next_y] && isValid(next_x, next_y, N)){
	                q.push({next_x, next_y, temp.dist +1});
	                visited[next_x][next_y]=1;
	            }
	        }
	        
	    }
	}