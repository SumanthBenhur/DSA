class Solution {
public:
    
void solve(vector<vector<int>>& image, int sr, int sc, int newColor, int original) {
    
    if(sr<0 || sc<0 || sr>=image.size() || sc>=image[0].size())
        return;
    if(image[sr][sc]!= original) return;
    image[sr][sc]= newColor;
    solve(image,sr+1, sc, newColor, original);
    solve(image,sr-1, sc, newColor, original);
    solve(image,sr, sc+1, newColor, original);
    solve(image,sr, sc-1, newColor, original);
}   
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        int original = image[sr][sc];
        if(original!=newColor)
            solve(image,sr, sc, newColor, original);
        return image;
    }
};