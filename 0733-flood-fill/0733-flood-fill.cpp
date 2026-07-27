class Solution {
public:

    // DFS function to color all connected pixels
    void dfs(vector<vector<int>>& image, int i, int j, int oldColor, int newColor) {

        int m = image.size();          // Number of rows
        int n = image[0].size();       // Number of columns

        // Stop if:
        // 1. Out of bounds
        // 2. Current pixel is not the original color
        if (i < 0 || j < 0 || i >= m || j >= n || image[i][j] != oldColor)
            return;

        // Change current pixel to the new color
        image[i][j] = newColor;

        // Visit all 4 neighboring pixels
        dfs(image, i + 1, j, oldColor, newColor); // Down
        dfs(image, i - 1, j, oldColor, newColor); // Up
        dfs(image, i, j + 1, oldColor, newColor); // Right
        dfs(image, i, j - 1, oldColor, newColor); // Left
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr, int sc, int color) {

        int oldColor = image[sr][sc];  // Store the starting pixel's original color

        // If the new color is the same as the old color,
        // nothing needs to be changed.
        if (oldColor == color)
            return image;

        // Start DFS from the given pixel
        dfs(image, sr, sc, oldColor, color);

        // Return the modified image
        return image;
    }
};